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

def circle (draw_obj, location, radius):
	l = [(location[0] - radius, location[1] - radius), (location[0] + radius, location[1] + radius)]
	draw_obj.ellipse(l, fill = (255, 255, 255))

def map (a, b, t, x, y):
	return (t - a) / (b - a) * (y - x) + x

#---------------------------------------------------------------------------------------------------

print("Beginning to render %s images of %s planets. (Seed: %s)" % (len(data), \
	json_obj["header"]["planets"], json_obj["header"]["seed"]))

output_images = []
count = 0

loc_min_x = 0
loc_min_y = 0
loc_max_x = 0
loc_max_y = 0

# Find the minimum and maximum values of x and y
for i in data:
	for j in i:
		if j["position"][0] > loc_max_x:
			loc_max_x = j["position"][0]
		elif j["position"][0] < loc_min_x:
			loc_min_x = j["position"][0]
		if j["position"][1] > loc_max_y:
			loc_max_y = j["position"][1]
		elif j["position"][1] < loc_min_y:
			loc_min_y = j["position"][1]

for i in data:
	# remember that count refers to the index of i, and i is the data at index count
	output_images.append(Image.new("RGB", (conf.width, conf.height)))
	draw = ImageDraw.Draw(output_images[count])
	for j in i:
		# Render each individual planet
		radius = 3 # TODO
		location = (map(loc_min_x, loc_max_x, j["position"][0], 0, conf.width),
					map(loc_min_y, loc_max_y, j["position"][1], 0, conf.height))
		circle(draw, location, radius)
	print("Completed %s of %s." % (count + 1, len(data)))
	count += 1

print("Writing data to %s." % (output_location))
output_images[0].save(output_location, save_all = True, append_images = output_images[1:], \
	duration = conf.duration, loop = conf.loop)
