CXX = g++
CXXFLAGS = -std=c++17

# adding all necessary include paths
INCLUDES = -Iutils/env -Iutils/functions -Idb

# adding source files (cpp files)
SOURCES = \
    src/main.cpp \
    utils/env/env.cpp \
    utils/functions/functions.cpp \
    db/db.cpp

LDFLAGS = -lpqxx -lpq

# output executable
TARGET = main

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) $(INCLUDES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
