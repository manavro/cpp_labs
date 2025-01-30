CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS = -lssl -lcrypto

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/server.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = $(BUILD_DIR)/server

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: all
	./$(TARGET)

