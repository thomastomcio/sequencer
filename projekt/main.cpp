#include"efekt.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

main( int argc, char* argv[])
{
	WavReader odczyt("example.wav");
	if ( odczyt.read_data() )
	{	
		cout<<"data_pointer_main: "<<odczyt.get_data()<<endl;
		efekt* eff = nullptr;
	
		string mode (argv[1]);

		if ( mode == "flanger")
		{
			flanger f( odczyt, stod(argv[2]) );
			eff = &f; 
		}
		else if ( mode == "echo")
		{
			echo e(odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]));
			eff = &e; 
		}
		else if ( mode == "delay")
		{
			delay d(odczyt, stod(argv[2]), stod(argv[3]));
			eff = &d;
		} 
		else if ( mode == "distortion") 
		{
			distortion di(odczyt, stod(argv[2]), stod(argv[3]));
			eff = &di;
		}
		else exit(-1);

		WavWriter zapis(mode + ".wav");

		int samples_count = odczyt.get_samples_count();
		cout<<samples_count<<endl;
		wav_header* header = odczyt.get_header();

		if ( zapis.write_data(eff->data.data(), header, samples_count) )
		{
		cout<<"ok"<<endl;
		}	
	}
return 0;
}
