PLANETS = 2

CC = g++

CPPMAIN = main.cpp
CPPEXEC = engine

#---------------------------------------------------------------------------------------------------

CPPBUILDOPTIONS = -DPLANETS=$(PLANETS)

#---------------------------------------------------------------------------------------------------

all: $(CPPEXEC)

clean:
	rm $(CPPEXEC)

$(CPPEXEC): $(CPPMAIN) header.hpp configuration.hpp utilities.cpp general.cpp general.hpp
	$(CC) $(CPPMAIN) -o $(CPPEXEC) $(CPPBUILDOPTIONS)

.PHONY: all clean
