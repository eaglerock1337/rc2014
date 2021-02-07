#!/usr/bin/env pipenv-shebang

import argparse
import os
import pyperclip
import sys


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

        self.data = self._import_data()
        self.checksum = self._get_checksum()
        self.output = self._format_output()

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

        return parser.parse_args()

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
        output = f"A:DOWNLOAD {self.filename.upper()}\r\nU{self.user}\r\n:"
        output += self.data.hex().upper()
        output += f">{self.checksum}\r\n"

        return output

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
        if not self.stdout and not self.clipboard and not self.outfile:
            self._output_clipboard()


if __name__ == "__main__":
    print("Formatting output for the RC2014 console...")
    uploader = RC2014Upload()
    uploader.process_output()
