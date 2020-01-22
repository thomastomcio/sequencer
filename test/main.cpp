#include<vector>
#include<iostream>
using namespace std;


class  klatki
{
	public:
	static int zmienna;
	klatki() {cout<<"powstalem"<<endl;}
	klatki( const klatki& ) { ++zmienna; }
	int get_zmienna() {return zmienna;}
};

class pimpek
{
	public:
	vector <klatki> ramki;
	pimpek() {ramki = vector<klatki>(10, klatki());}
	
};

int klatki::zmienna = 1;

main()
{
	pimpek lalik;
	pimpek lalik2;
	cout<<lalik.ramki[1].get_zmienna()<<endl;
	cout<<lalik2.ramki[0].get_zmienna()<<endl;
}

