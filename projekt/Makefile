all: seq.exe

seq.exe: main.o wav.o efekt.o signal.o 
	g++ -o seq.exe main.o wav.o efekt.o signal.o 

main.o: main.cpp
	g++ -o main.o -c main.cpp

wav.o: wav.cpp 
	g++ -o wav.o -c wav.cpp 

signal.o: signal.cpp
	g++ -o signal.o -c signal.cpp

efekt.o: efekt.cpp 
	g++ -o efekt.o -c efekt.cpp 


clean:
	rm main.o wav.o efekt.o signal.o seq.exe 
