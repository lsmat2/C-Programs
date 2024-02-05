#
# 'make'        build exec file 'main'
# 'make clean'  removes all .o and executable files
# 'make debug'  compiles with debugging info (-g and -Wall flags)

CXX=clang
# INCLUDES=-Iincludes
# CXXFLAGS=-std=c++20 -gdwarf-4 -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)


exec: ./helloworld.c
	$(CXX) $^ -o $@
# ACTUAL: clang ./helloworld.c -o exec

debug: ./helloworld.c
	$(CXX) -g -Wall $^ -o $@
# ACTUAL: clang -g -Wall ./helloworld.c -o exec

numb: ./type_representation.c
	$(CXX) $^ -o $@
# ACTUAL: clang ./typeRepresentation.c -o numb

dataStructures: ./data_structures.c
	$(CXX) $^ -o $@
# ACTUAL: clang ./data_structures.c -o dataStructures

clean:
	rm ./exec ./debug ./numb ./dataStructures



.DEFAULT_GOAL := exec
.PHONY: clean exec debug

