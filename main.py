#!/usr/bin/python3

# Usage:
# (python3 |./)main.py [OUTPUT] [INPUT]

from PIL import Image
import json, sys

input_location = "data.json"
output_location = "output.gif"
json_obj = None
data = None

#---------------------------------------------------------------------------------------------------
# Open input file, and parse arguments.

if len(sys.argv) >= 2:
	output_location = sys.argv[1]
	if len(sys.argv) >= 3:
		input_location = sys.argv[2]

with open(input_location) as file:
	json_obj = json.load(file)
	data = json_obj["data"]

#---------------------------------------------------------------------------------------------------

print(data)
