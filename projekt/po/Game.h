// Game.h
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<regex>
#include<map>
#include"Map.h"
using namespace std;

class Game
{
	private:
		int middle;
		int map_len;
		int pstats[5];
		Map mapa;
		Player* gracz;
		Empty* pusty;
		Location* cursor;
		int x_aktual;
		int y_aktual;
		int x_plus;
		int y_plus;
		// lab 6
		map<string, string> messages;
		// lab 6
	public:
		Game();  	
		Game(string path);
		void file_open(string path);
		void start();
		bool aktualizuj_mape();
		bool idz();
		bool process(Player*, Character*);
		~Game();
};

