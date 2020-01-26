// signal.cpp
#include"signal.h"

klatka::klatka ( const klatka& kopiowany )
{
	data_period = kopiowany.data_period;
	beg_id = data_period * counter;
	end_id = data_period * (counter + 1)-1;
	counter++;
}

int klatka::counter = 0;

signal::signal( WavObject& wav_file) 
{ 
	header = wav_file.get_header();
	samples_count = wav_file.get_samples_count();
	short int* data_pointer = wav_file.get_data();
	data = vector<short int> (data_pointer, data_pointer + samples_count); 

}

signal::signal( const signal& sig )
{
	header = sig.header;
	samples_count = sig.samples_count;
	data = sig.data;
}

short int& signal::operator[]( int index )
{
	return data[index];
		
}

signal& signal::operator+= ( const signal& adder )
{
	for( int i = 0; i < samples_count; i++)
	{
		data[i] =  adder.data[i] + data[i];
	}
		cout<<"tu jestem"<<endl;
	return *this;
}

signal& signal::operator+ ( const signal& adder)
{
	for( int i = 0; i < samples_count; i++)
	{
		data[i] = ( sgn(adder.data[i] + data[i])  > 32767 ) ? :32767;
	}
	return *this;
}

signal& signal::operator=( const signal& assigner)
{
	this->header = assigner.header;
	this->samples_count = assigner.samples_count;
	this->data = assigner.data;
	return *this;
}
