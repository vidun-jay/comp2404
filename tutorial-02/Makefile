OBJ = main.o Character.o battle.o

all: $(OBJ)
	g++ -o p1 $(OBJ)

main.o: main.cc
	g++ -c main.cc

Character.o: Character.h Character.cc
	g++ -c Character.cc

battle.o: battle.h battle.cc
	g++ -c battle.cc

clean:
	rm -f $(OBJ) p1