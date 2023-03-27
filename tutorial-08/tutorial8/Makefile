objects = test.o Criteria.o Photo.o Date.o

all: test

test: $(objects)
	g++ -o test $(objects)

test.o: test.cc Criteria.h Photo.h
	g++ -c -g test.cc

Criteria.o: Criteria.h Criteria.cc
	g++ -c -g Criteria.cc

Photo.o: Photo.cc Photo.h
	g++ -c -g Photo.cc

Date.o: Date.cc Date.h
	g++ -c -g Date.cc


clean:
	rm -f test *.o