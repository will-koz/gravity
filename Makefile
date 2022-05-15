ITERATIONS = 64
PLANETS = 2

CC = g++

CPPEXEC = engine
JSONDATA = data.json
OUTPUTGIF = output.gif

#---------------------------------------------------------------------------------------------------

CPPMAIN = main.cpp
CPPBUILDOPTIONS = -DITERATIONS=$(ITERATIONS) -DPLANETS=$(PLANETS)
PYMAIN = main.py

#---------------------------------------------------------------------------------------------------

all: $(CPPEXEC) $(JSONDATA) $(OUTPUTGIF)

clean:
	rm -f $(CPPEXEC) $(JSONDATA) $(OUTPUTGIF)

$(CPPEXEC): $(CPPMAIN) header.hpp configuration.hpp utilities.cpp general.cpp general.hpp
	rm -f $(JSONDATA) $(OUTPUTGIF)
	$(CC) $(CPPMAIN) -o $(CPPEXEC) $(CPPBUILDOPTIONS)

$(JSONDATA):
	rm -f $(OUTPUTGIF)
	./$(CPPEXEC) > $(JSONDATA)

$(OUTPUTGIF):
	python3 $(PYMAIN) $(OUTPUTGIF) $(JSONDATA)

.PHONY: all clean
