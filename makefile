battleship:ship.o helpers.o board.o player.o opponent.o main.cpp
	g++ -o battleship ship.o helpers.o board.o player.o opponent.o main.cpp
ship.o: ship.h ship.cpp
	g++ -c ship.cpp
helpers.o: helpers.h helpers.cpp ship.h opponent.h player.h
	g++ -c helpers.cpp
board.o: board.h board.cpp ship.h
	g++ -c board.cpp
player.o: player.h player.cpp board.h helpers.h
	g++ -c player.cpp
opponent.o: opponent.h opponent.cpp board.h helpers.h
	g++ -c opponent.cpp
clean:
	rm *.o battleship