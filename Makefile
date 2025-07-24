CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17 -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

all: dirs TASCEmulator

dirs:
	mkdir -p build

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

TASCEmulator: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o build/TASCEmulator

clean:
	rm -rf build/*.o build/TASCEmulator
