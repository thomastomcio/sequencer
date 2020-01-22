#include"efekt.h"
#include<iostream>
#include<cstdlib>
using namespace std;

main( int argc, char* argv[])
{
	WavReader odczyt("laliczek.wav");
	if ( odczyt.read_data() )
	{
		WavWriter zapis("pimp.wav");
		delay opoznienie(odczyt, atof(argv[1]), atof(argv[2]), atof(argv[3]));
		
		short int *data = odczyt.get_data();
		int samples_count = odczyt.get_samples_count();

		if ( zapis.write_data(opoznienie.data.data(), odczyt.get_header(), samples_count) )
		{
		cout<<"ok"<<endl;
		}	
	}
return 0;
}
