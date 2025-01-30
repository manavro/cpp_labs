CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS = -lcrypto -lpthread

SRC = src/main.cpp src/password_cracker.cpp
OBJ = $(SRC:src/%.cpp=build/%.o)  
TARGET = build/worker


$(shell mkdir -p build)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)


