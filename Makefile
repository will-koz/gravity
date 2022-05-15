PLANETS = 2

CC = g++

CPPMAIN = main.cpp
CPPEXEC = engine
JSONDATA = data.json

#---------------------------------------------------------------------------------------------------

CPPBUILDOPTIONS = -DPLANETS=$(PLANETS)

#---------------------------------------------------------------------------------------------------

all: $(CPPEXEC) $(JSONDATA)

clean:
	rm $(CPPEXEC) $(JSONDATA)

$(CPPEXEC): $(CPPMAIN) header.hpp configuration.hpp utilities.cpp general.cpp general.hpp
	rm -f $(JSONDATA)
	$(CC) $(CPPMAIN) -o $(CPPEXEC) $(CPPBUILDOPTIONS)

$(JSONDATA):
	./$(CPPEXEC) > $(JSONDATA)

.PHONY: all clean
