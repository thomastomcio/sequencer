// signal.h
#include"wav.h"
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

#define sgn(x) (signbit(x) ? -1 : 1)

class signal
{
	public:
		signal ( WavObject& wav_file); // sygnal z danych
		signal ( const signal& sig); // konstruktor kopiujacy
		signal( int size, short int val, wav_header* h) \
			:samples_count(size), header(h), data(std::vector<short int>(size, val)){}

		wav_header* header;	
		int samples_count;
		//short int* data_pointer;
		short int* vector_pointer;
		std::vector<short int> data;


		short int& operator[] ( int index );
		signal& operator= ( const signal& assigner );
		signal& operator+= ( const signal& adder );
		signal& operator+ ( const signal& adder );

};

