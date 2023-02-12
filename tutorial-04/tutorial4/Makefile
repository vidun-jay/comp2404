all: test
	
test: test.cc Photo.o Date.o HeapArrays.o StackArrays.o
	g++ -o test test.cc Photo.o Date.o HeapArrays.o StackArrays.o
	
StackArrays.o:	StackArrays.h StackArrays.cc 
	g++ -c StackArrays.cc 
	
HeapArrays.o:	HeapArrays.h HeapArrays.cc 
	g++ -c HeapArrays.cc 

Photo.o:	Photo.h Photo.cc
	g++ -c Photo.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc
	
clean:
	rm -f test *.o
