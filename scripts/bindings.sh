c++ -O3 -Wall -shared -std=c++17 -fPIC `python3 -m pybind11 --includes` \
    bindings.cpp src/*.cpp -o TASCEmu$(python3-config --extension-suffix)
