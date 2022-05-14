PLANETS = 512;

CC = g++

CPPMAIN = main.cpp
CPPEXEC = engine

#---------------------------------------------------------------------------------------------------

CPPBUILDOPTIONS = -DPLANETS=$(PLANETS)

#---------------------------------------------------------------------------------------------------

all: $(CPPEXEC)

clean:
	rm $(CPPEXEC)

$(CPPEXEC): $(CPPMAIN) header.hpp configuration.hpp utilities.cpp
	$(CC) $(CPPMAIN) -o $(CPPEXEC)

.PHONY: all clean
