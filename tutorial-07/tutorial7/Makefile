objects = Driver.o Entity.o Franchise.o Location.o Order.o Queue.o

all: test
	
test: test.cc $(objects)
	g++ -o test test.cc $(objects)
	
Driver.o:	Driver.h Driver.cc
	g++ -c Driver.cc

Entity.o:	Entity.h Entity.cc
	g++ -c Entity.cc

Franchise.o:	Franchise.h Franchise.cc
	g++ -c Franchise.cc

Queue.o:	Queue.h Queue.cc
	g++ -c Queue.cc

Order.o:	Order.h Order.cc
	g++ -c Order.cc

Location.o:	Location.h Location.cc
	g++ -c Location.cc
	
clean:
	rm -f test *.o
