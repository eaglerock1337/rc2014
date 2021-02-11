#!/usr/bin/env pipenv-shebang

import argparse
import os
import pyperclip
import yaml
import serial
import sys
import time


SETTINGS_YAML = "settings.yaml"
SERIAL_DEFAULTS = {
    "baud":         115200,
    "databits":     8,
    "parity":       serial.PARITY_NONE,
    "stopbits":     1,
    "timeout":      0,
    "writetimeout": 0,
    "txdelay":      0.001,
    "rxdelay":      1.0,
    "flowctl": {
        "soft":     False,
        "rtscts":   True,
        "dsrdtr":   False,
    },
}


class RC2014Upload:
    def __init__(self):
        self.dir = os.getcwd()
        args = self._parse_args()

        self.infile = args.filename
        self.filename = os.path.basename(self.infile)
        self.user = args.user

        self.clipboard = args.clipboard
        self.stdout = args.stdout
        self.outfile = args.file
        self.terminal = args.terminal

        self.data = self._import_data()
        self.checksum = self._get_checksum()
        self.output = self._format_output()
        self.settings = self._load_settings()

    def _parse_args(self):
        """
        Parses command-line arguments and returns them to the calling function.
        """
        parser = argparse.ArgumentParser()
        parser.add_argument(
            "filename", type=str, help="Path to filename containing the file to copy."
        )
        parser.add_argument(
            "-u",
            "--user",
            type=int,
            default=0,
            help="The CP/M user the file should be saved under.",
        )

        outputs = parser.add_argument_group(
            "outputs", "The available outputs for terminal data:"
        )
        outputs.add_argument(
            "-c",
            "--clipboard",
            action="store_true",
            help="Send terminal data directly to the clipboard for quick pasting.",
        )
        outputs.add_argument(
            "-s",
            "--stdout",
            action="store_true",
            help="Copy and paste data from stdout. Recommended only for small files.",
        )
        outputs.add_argument(
            "-f",
            "--file",
            type=str,
            help="Save data to the specified file path.",
        )
        outputs.add_argument(
            "-t",
            "--terminal",
            action="store_true",
            help="Send data directly over a serial port to the rc2014.",
        )

        return parser.parse_args()

    def _load_settings(self):
        """
        Loads all configuration options for the script from settings.yaml in the same directory.
        """
        if os.path.exists(os.path.join(sys.path[0], SETTINGS_YAML)):
            with open(os.path.join(sys.path[0], SETTINGS_YAML), "r") as settings:
                return yaml.load(settings, Loader=yaml.FullLoader)
        
        return {}

    def _import_data(self):
        """
        Opens the provided COM file and imports the data into a bytearray.
        """
        with open(os.path.join(self.dir, self.infile), "rb") as hex:
            return bytearray(hex.read())

    def _get_checksum(self):
        """
        Generate the expected checksum of the file as follows:
        2 bytes:
        - low-byte of the length of the file being uploaded
        - low-byte of the sum of each byte being uploaded
        """
        length = 0
        bytesum = 0
        for byte in self.data:
            length += 1
            bytesum += byte

        lowlength = format(0x000000FF & length, "x")
        lowsum = format(0x000000FF & bytesum, "x")

        return f"{str(lowlength).zfill(2)}{str(lowsum).zfill(2)}"

    def _format_output(self):
        """
        Uses the input data and command-line args to format the output string.
        """
        output = f"A:DOWNLOAD {self.filename.upper()}\nU{self.user}\n:"
        output += self.data.hex().upper()
        output += f">{self.checksum}\n"

        return output

    def _setup_terminal(self):
        """
        Sets up a serial connection to the rc2014 based on the YAML settings.
        """
        if "terminal" not in self.settings:
            print("Terminal settings missing...please update settings.yaml!")
            exit(1)
        
        term = self.settings["terminal"]
        if not term["port"]:
            print("Terminal port undefined...please set port under the terminal section in settings.yaml!")
            exit(1)

        baudrate = term["baud"] if "baud" in term else SERIAL_DEFAULTS["baud"]
        serialout = serial.Serial(port=term["port"], baudrate=baudrate)
        print(f"Configuring port {term['port']} at {baudrate}bps...")

        serialout.bytesize = term["databits"] if "databits" in term else SERIAL_DEFAULTS["databits"]
        serialout.parity = term["parity"] if "parity" in term else SERIAL_DEFAULTS["parity"]
        serialout.stopbits = term["stopbits"] if "stopbits" in term else SERIAL_DEFAULTS["stopbits"]
        serialout.timeout = term["timeout"] if "timeout" in term else SERIAL_DEFAULTS["timeout"]

        if "flowctl" in term:
            serialout.xonxoff = term["flowctl"]["soft"] if "soft" in term["flowctl"] else SERIAL_DEFAULTS["flowctl"]["soft"]
            serialout.rtscts = term["flowctl"]["rtscts"] if "rtscts" in term["flowctl"] else SERIAL_DEFAULTS["flowctl"]["rtscts"]
            serialout.dsrdtr = term["flowctl"]["dsrdtr"] if "dsrdtr" in term["flowctl"] else SERIAL_DEFAULTS["flowctl"]["dsrdtr"]
        else:
            serialout.xonxoff = SERIAL_DEFAULTS["flowctl"]["xonxoff"]
            serialout.rtscts = SERIAL_DEFAULTS["flowctl"]["rtscts"]
            serialout.dsrdtr = SERIAL_DEFAULTS["flowctl"]["dsrdtr"]       

        return serialout

    def _output_stdout(self):
        """
        Prints the output to stdout
        """
        print("- " * 30)
        print("Copy and paste the output below into your terminal:\n")
        print(self.output, "\n")

    def _output_clipboard(self):
        """
        Copies the output to the system clipboard.
        """
        pyperclip.copy(self.output)
        print("- " * 30)
        print("The output has been copied to your clipboard\nfor easy copy-paste into your terminal.")

    def _output_file(self):
        """
        Saves the output to a file.
        """
        with open(os.path.join(self.dir, self.outfile), "w") as outfile:
            outfile.write(self.output)
        print("- " * 30)
        print(f"The output has been saved to {self.outfile}.")

    def _output_terminal(self):
        """
        Prints output directly to the serial terminal. Terminal needs to be
        configured first.
        """
        serialout = self._setup_terminal()
        txdelay = self.settings["terminal"]["txdelay"] if "txdelay" in self.settings["terminal"] else SERIAL_DEFAULTS["txdelay"]
        # rxdelay = self.settings["terminal"]["rxdelay"] if "rxdelay" in self.settings["terminal"] else SERIAL_DEFAULTS["rxdelay"]

        for byte in self.output:
            serialout.write(byte.encode())  
            time.sleep(txdelay)

        print("- " * 30)      
        print(f"The output has been sent to serial port {self.settings['terminal']['port']}.")

    def process_output(self):
        """
        Processes the different types of outputs and outputs result to stdout.
        """
        print(f"Outputting data for {self.filename}:")
        if self.stdout:
            self._output_stdout()
        if self.outfile is not None:
            self._output_file()
        if self.clipboard:
            self._output_clipboard()
        if self.terminal:
            self._output_terminal()
        if not self.stdout and not self.clipboard and not self.outfile and not self.terminal:
            self._output_clipboard()


if __name__ == "__main__":
    print("Formatting output for the rc2014 console...")
    uploader = RC2014Upload()
    uploader.process_output()
