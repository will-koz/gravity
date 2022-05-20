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

def map (a, b, t, x, y):
	return (t - a) / (b - a) * (y - x) + x

def circle (draw_obj, location, radius):
	l = [(location[0] - radius, location[1] - radius), (location[0] + radius, location[1] + radius)]
	color = (int(map(conf.radius_sml, conf.radius_lar, radius, conf.p_color1[0], conf.p_color2[0])),
		int(map(conf.radius_sml, conf.radius_lar, radius, conf.p_color1[1], conf.p_color2[1])),
		int(map(conf.radius_sml, conf.radius_lar, radius, conf.p_color1[2], conf.p_color2[2])))
	draw_obj.ellipse(l, fill = color)

#---------------------------------------------------------------------------------------------------

print("Beginning to render %s images of %s planets. (Seed: %s)" % (len(data), \
	json_obj["header"]["planets"], json_obj["header"]["seed"]))

output_images = []
count = 0

glo_max = 0 # Calculate the global maximum (even through the fourth dimension)
glo_min = 0
mass_max = 0 # Calculate the largest and smallest masses
mass_min = 0
guidelines = []
for i in data:
	for j in i:
		if j["position"][0] > glo_max:
			glo_max = j["position"][0]
		elif j["position"][0] < glo_min:
			glo_min = j["position"][0]
		if j["position"][1] > glo_max:
			glo_max = j["position"][1]
		elif j["position"][1] < glo_min:
			glo_min = j["position"][1]
		if j["mass"] > mass_max:
			mass_max = j["mass"]
		if (j["mass"] < mass_min) or (mass_min == 0):
			mass_min = j["mass"]
for i in range(1, conf.num_guide_lines):
	guidelines.append(glo_min + (i * (glo_max - glo_min) / conf.num_guide_lines))

for i in data:
	# remember that count refers to the index of i, and i is the data at index count
	output_images.append(Image.new("RGB", (conf.width, conf.height)))
	draw = ImageDraw.Draw(output_images[count])
	# Find minimum and maximum for scale
	loc_min = 0
	loc_max = 0
	for j in i:
		if j["position"][0] > loc_max:
			loc_max = j["position"][0]
		elif j["position"][0] < loc_min:
			loc_min = j["position"][0]
		if j["position"][1] > loc_max:
			loc_max = j["position"][1]
		elif j["position"][1] < loc_min:
			loc_min = j["position"][1]
	# Render guiding lines
	for j in guidelines:
		guide_x = map(loc_min, loc_max, j, 0, conf.width)
		guide_y = map(loc_min, loc_max, j, 0, conf.height)
		draw.line([guide_x, 0, guide_x, conf.height], fill = conf.l_fill, width = conf.line_width)
		draw.line([0, guide_y, conf.width, guide_y], fill = conf.l_fill, width = conf.line_width)
	for j in i:
		# Render each individual planet
		radius = map(mass_max, mass_min, j["mass"], conf.radius_sml, conf.radius_lar)
		# print("X: %s, Y: %s" % (j["position"][0], j["position"][1]))
		# print("  X: %s, Y: %s" % (j["velocity"][0], j["velocity"][1]))
		# print("  X: %s, Y: %s" % (j["acceleration"][0], j["acceleration"][1]))
		# print("  M: %s" % (j["mass"]))
		location = (map(loc_min, loc_max, j["position"][0], 0, conf.width),
					map(loc_min, loc_max, j["position"][1], 0, conf.height))
		circle(draw, location, radius)
	print("Completed %s of %s." % (count + 1, len(data)))
	count += 1

print("Writing data to %s." % (output_location))
output_images[0].save(output_location, save_all = True, append_images = output_images[1:], \
	duration = conf.duration, loop = conf.loop)
