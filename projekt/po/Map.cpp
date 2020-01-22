// Map.cpp
#include"Map.h"


vector<Location>& Map::operator[] (int poz)
{
	return pozycje[poz];
}

void Map::wyswietl()
{
	char c = '*';
	cout<<string(2*(map_len*2)+1, c)<<endl;
	for(int i=0; i<map_len; i++)
	{
		cout<<c<<" ";
		for(int j=0; j<map_len;j++)
		{
		cout<<pozycje[i][j].aktualny->get_symbol()<<" "<<c<<" ";
		}
			
	cout<<endl;	
	cout<<string(2*(map_len*2)+1, c)<<endl;
	}
}
