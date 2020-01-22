// Map.h
#include<vector>
#include<math.h>
#include<string>
#include"Location.h"
using namespace std;

class Map
{
	private:
		int map_len;
	public:
		Map(int len) : pozycje( vector<vector <Location>> (len,\
		vector<Location>(len, Location(len))) ), map_len(len) 
		{}
		// przy wowolaniu konstruktora z konstruktorem Location(i) zmienna static nie ujawnia sie
		// prawdopodobnie dlatego ze wektor kopiuje jedna instancje na inne
		vector<vector <Location>> pozycje;

		vector<Location>& get_location(int);

		vector<Location>& operator[] (int poz);

		void wyswietl();//Location*);
};
