OBJ = Hotel.o Reservation.o Room.o Date.o

assignment1: main.cc ${OBJ}
	g++ -o assignment1 main.cc ${OBJ}

Hotel.o: Hotel.cc
	g++ -c -w Hotel.cc

Reservation.o: Reservation.cc
	g++ -c -w Reservation.cc

Room.o: Room.cc
	g++ -c -w Room.cc

Date.o: Date.cc
	g++ -c -w Date.cc

clean:
	rm -f assignment1 *.o