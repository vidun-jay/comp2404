#observe - Linux is case sensitive. These names should match your filenames exactly

all: test
	
test: test.o PhotoArray.o Photo.o Date.o Album.o 
	g++ -o test test.o PhotoArray.o Photo.o Date.o Album.o 
	
test.o: test.cc Photo.h Album.h
	g++ -c test.cc

PhotoArray.o:   PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc
	
Album.o:	Album.h Album.cc 
	g++ -c Album.cc 

Photo.o:	Photo.h Photo.cc
	g++ -c Photo.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc
	
clean:
	rm -f test *.o
