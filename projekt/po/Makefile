all: gra.exe

gra.exe: main.o Map.o Location.o Character.o Game.o Statistics.o
	g++ -o gra.exe main.o Map.o Location.o Character.o Game.o Statistics.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

Map.o: Map.cpp 
	g++ -o Map.o -c Map.cpp 

Location.o: Location.cpp
	g++ -o Location.o -c Location.cpp

Character.o: Character.cpp
	g++ -o Character.o -c Character.cpp

Game.o : Game.cpp
	g++ -o Game.o -c Game.cpp

Statistics.o: Statistics.cpp
	g++ -o Statistics.o -c Statistics.cpp

clean:
	rm main.o Map.o gra.exe Location.o Character.o Game.o Statistics.o
