CC = g++
CFLAGS = -std=c++11

all: complex_sort

complex_sort: main.o ComplexNum.o
    $(CC) $(CFLAGS) main.o ComplexNum.o -o complex_sort

main.o: main.cpp ComplexNum.hpp
    $(CC) $(CFLAGS) -c main.cpp

ComplexNum.o: ComplexNum.cpp ComplexNum.hpp
    $(CC) $(CFLAGS) -c ComplexNum.cpp

clean:
    rm -f *.o complex_sort

