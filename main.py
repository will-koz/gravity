#!/usr/bin/python3

# Usage:
# (python3 |./)main.py [OUTPUT] [INPUT]

from PIL import Image, ImageDraw
import json, sys
import conf

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

print("Beginning to render %s images of %s planets. (Seed: %s)" % (len(data), \
	json_obj["header"]["planets"], json_obj["header"]["seed"]))

output_images = []
count = 0

for i in data:
	# remember that count refers to the index of i, and i is the data at index count
	output_images.append(Image.new("RGB", (conf.width, conf.height)))
	draw = ImageDraw.draw()
	output_images[count];
	count += 1

output_images[0].save(output_location, save_all = True, append_images = output_images[1:], \
	duration = conf.duration, loop = conf.loop)
