
CXXFLAGS=-std=c++17

all: cpp_sequence.i cpp_sequence test

cpp_sequence: cpp_sequence.cpp
	$(CXX) $(CXXFLAGS) cpp_sequence.cpp -o $@

cpp_sequence.i: cpp_sequence.cpp
	$(CXX) $(CXXFLAGS) -E cpp_sequence.cpp >$@

test: cpp_sequence
	./cpp_sequence
