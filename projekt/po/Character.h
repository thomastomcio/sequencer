//Characte.h 
#include<iostream>
#include<fstream>
#include<memory>
#include<cstdlib>
#include<vector>
#include<map>
#include<string>
#include"Statistics.h"
using namespace std;

class Character // klasa pure virtual
{
	private:
		const char symbol;
	public:
		Character(char s, int hp=0, int mana=0, int money=0, int speed=0, int strength=0) \
		       	: symbol(s), features( Statistics(hp, mana, money, speed, strength) )
			{}
		Statistics features;
		static map<string, string> dane;
		//funkcje wirtualne
		virtual void typ() = 0;
		virtual void show_stats() = 0;
		virtual Character* clone() = 0;
		// funkcje wirtualne
		char get_symbol();
};



class Empty : public Character
{
	public:
		Empty(): Character(' ') {}
		void typ();
		void show_stats();
		Empty* clone();

};

class Hidden : public Character
{
	public:
		Hidden(): Character('#') {}
		void typ();
		void show_stats();
		Hidden* clone();
};


class Monster : public Character
{
	public:
		Monster(): Character('M', -(rand()%80 + 1), -(rand()%80 + 1), -(rand()%80 + 1), -(rand()%80 + 1), -(rand()%80 + 1) ) {}
		void typ();
		void show_stats();
		Monster* clone();
};

class Item : public Character
{
	public:
		Item(): Character('A', 40 - (rand()%50 + 1), 40 - (rand()%50 + 1), 40 - (rand()%50 + 1), 40 - (rand()%50 + 1), 40 - (rand()%50 + 1) ) {}
		void typ();
		void show_stats();
		Item* clone();

};

class Player : public Character
{
//		static int ile_pol; // ilosc pol pokonanych przez gracza
	public:
		Player(int hp=0, int mana=0, int money=0, int speed=0, int strength=0 ): Character('P'), \
			pfeatures(Player_Statistics(hp, mana, money, speed, strength, 0) ) \
			{}

		void typ();
		void show_stats();
		Player* clone(); 
		//  tzw. covariant return type
		// lab5
		vector<unique_ptr<Item>> items;
		void pickItem(Item& item);
		Item& dropItem();
		Player_Statistics pfeatures;
		// lab5

};
