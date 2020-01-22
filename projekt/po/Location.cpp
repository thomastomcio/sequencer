// Location.cpp
#include"Location.h"

int Location::counter = 0;

Character* Location::losuj_ch()
{
	Character* losowany;
	int losowe = rand()%3;
	switch(losowe)
	{
		case 0: losowany = new Monster();
			break;
		case 1: losowany = new Item();
			break;
		case 2: losowany = new Empty();
			break;
	}
	return losowany;
}
Location::Location( int w, Character* akt) : wymiar(w), aktualny(akt)
{
	zakulisowy = losuj_ch();
} 

Location::Location (const Location& kopiowany) 
{
	wymiar = kopiowany.wymiar;
	aktualny= kopiowany.aktualny->clone();
	zakulisowy = losuj_ch();
	x =counter/wymiar-1; // tego nie rozumiem;
			     // powinno zaczynac sie od 0
	y = counter%wymiar;

	counter++;
}

Location* Location::operator=( Location* assigner)
{
	if ( assigner != this )
	{
		assigner = this;
	}
	return this;	
}

int Location::get_x()
{
	return x;
}

int Location::get_y()
{
	return y;
}


Location::~Location()
{
	delete aktualny;
	delete zakulisowy;
}

//Character* Location::get_character()
//{
//	return charakt;
//}
