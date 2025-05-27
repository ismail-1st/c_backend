CXX = g++
CXXFLAGS = -std=c++17
INCLUDES = -Iutils/env -Iutils/functions
SOURCES = src/main.cpp utils/env/env.cpp utils/functions/functions.cpp
TARGET = main

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) $(INCLUDES) -o $(TARGET)

clean:
	rm -f $(TARGET)