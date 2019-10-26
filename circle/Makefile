# TC=/opt/mongodbtoolchain/v3
#TC=/usr
#CXX=${TC}/bin/clang++
#CXX=${TC}/bin/g++
CXXFLAGS=-O2 -std=c++17
# /usr/lib/libfmt.a
# LDLIBS=-lfmt
CC=${CXX}
LD=${CXX}
LDLIBS=-lfmt

all: circle_test.out

test: circle_test
	./circle_test

circle_test:

circle_test.out: circle_test
	./circle_test |tee circle_test.out

