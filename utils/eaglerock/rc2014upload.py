#!/usr/bin/python3

import argparse
import os

class RC2014Upload:
    def __init__(self):
        self.dir = os.getcwd()
        self.parse_args()
        self.import_data()
        self.format_output()

        if self.outputs["file"]:
            self.save_outfile()

    def parse_args(self):
        '''
        This will eventually parse arguments. For now, it's hardcoding variables for testing purposes.
        '''
        # parser = argparse.ArgumentParser()
        # parser.add_argument(
        #     "-v", "--verbose", action="store_true", help="Enable verbose output."
        # )
        # args = parser.parse_args()
        # self.verbose = args.verbose
        self.infile = "WORM.COM"
        self.filename = os.path.basename(self.infile)
        self.user = 0

        self.outputs = {
            "clipboard": False,
            "stdout":    False,
            "file":      True,
        }

        self.outfile = "worm.txt"

    def import_data(self):
        '''
        This function will open the provided COM file and import the data into a bytearray.
        '''
        with open(os.path.join(self.dir, self.infile), "rb") as hex:
            self.data = bytearray(hex.read())
            print(self.data)

    def format_output(self):
        '''
        This function will take the input data and command-line args to format the output string.
        '''
        self.output = f"A>DOWNLOAD.COM {self.filename}\r\nU{self.user}\r\n:"
        self.output += self.data.hex().upper()
        self.output += ">0050\r\n"

    def save_outfile(self):
        '''
        This function will save the output data to a file.
        '''
        with open(os.path.join(self.dir, self.outfile), "w") as outfile:
            outfile.write(self.output)

if __name__ == "__main__":
    upload = RC2014Upload()