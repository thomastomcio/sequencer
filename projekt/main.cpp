#include"efekt.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<windows.h>
using namespace std;

main( int argc, char* argv[])
{	
	string nazwa = string(argv[argc-1]);
	WavReader odczyt( string(nazwa) + ".wav");
	if ( odczyt.read_data() )
	{	
		efekt *eff;
	
		string mode (argv[1]);
		string mode_file (mode + ".wav");

		if ( mode == "flanger")
		{
			eff = new flanger ( odczyt, stod(argv[2]), stod(argv[3]) );
	//		eff = &f; 
		}
		else if ( mode == "echo")
		{
		eff = new echo (odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]));
	//		eff = &e; 
		}
		else if ( mode == "delay")
		{
		 eff = new delay (odczyt, stod(argv[2]), stod(argv[3]));
	//		eff = &d;
		} 
		else if ( mode == "distortion") 
		{
		eff = new distortion (odczyt, stod(argv[2]), stod(argv[3]), stod(argv[4]));
	//		eff = &di;
		}
		else exit(-1);

		WavWriter zapis(mode_file);

		int samples_count = odczyt.get_samples_count();
		wav_header* header = odczyt.get_header();

		if ( zapis.write_data(eff->data.data(), header, samples_count) )
		{
		short int* data = odczyt.get_data();
		delete [] data;
		delete header;	

		cout<<endl;
		cout<<"All is ok"<<endl;
		system(mode_file.c_str());
		}	
	}
return 0;
}
