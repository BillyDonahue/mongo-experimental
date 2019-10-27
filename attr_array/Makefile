# TC=/opt/mongodbtoolchain/v3
#TC=/usr
#CXX=${TC}/bin/clang++
#CXX=${TC}/bin/g++
CXXFLAGS=-O2 -std=c++17 -g
# /usr/lib/libfmt.a
# LDLIBS=-lfmt
CC=${CXX}
LD=${CXX}
LDFLAGS=--verbose
LDLIBS=-lfmt

all: test

test: attr_array
	./attr_array

clean:
	rm attr_array symb1.o attr_array.o

attr_array:  linker_array.ldscript symb1.o attr_array.o

attr_array.out: attr_array
	./attr_array |tee attr_array.out

