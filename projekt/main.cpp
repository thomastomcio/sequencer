#include"efekt.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

main( int argc, char* argv[])
{
	WavReader odczyt("laliczek.wav");
	if ( odczyt.read_data() )
	{	
		efekt* eff = nullptr;
	
		string mode (argv[1]);
		delay d(odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]));

		if ( mode == "flanger")
		{
			flanger f( odczyt, stod(argv[2]), stod(argv[3]));
			eff = &f; 
		}
		else if ( mode == "echo")
		{
			echo e(odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]));
			eff = &e; 
		}
		else if ( mode == "delay")
		{
//			delay d(odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]));
			eff = &d;
		} 
		else if ( mode == "distortion") 
		{
			distortion di(odczyt, stod(argv[2]), stod(argv[3], stod(argc[4]);
			eff = &di;
		}
		else exit(-1);

		WavWriter zapis(mode + ".wav");
		
		short int *data = odczyt.get_data();
		int samples_count = odczyt.get_samples_count();
		wav_header* header = odczyt.get_header();

		cout<<eff<<endl;
		//flanger gnom(odczyt, atof(argv[1]), atof(argv[2]));
		cout<<"teraz tu"<<endl;
		if ( zapis.write_data(d.data.data(), header, samples_count) )
		{
		cout<<"ok"<<endl;
		}	
	}
return 0;
}
