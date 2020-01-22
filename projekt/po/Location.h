// Location.h
#include<iostream>
#include"Character.h"
using namespace std;

class Location 
{
	private:
		static int counter;
		int x;
		int y; 
		int wymiar;	
	public:
		
		Location( int w, Character* akt = new Hidden()); 

		Location (const Location&);

		Character* aktualny;
		Character* zakulisowy;
		Character* losuj_ch();
		void pokazXY();
		int get_x();
		int get_y();

		Location* operator=( Location* );
		// Character* get_character();

		~Location();

};

