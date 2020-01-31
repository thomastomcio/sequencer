// wav.h
#include<stdio.h>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

struct wav_header
{
	
	char chunkID[4]; //RIFF
	unsigned long chunkSize; //28
	char format[4]; //WAVE
	char subchunk1ID[4]; //fmt
	unsigned long subchunk1Size; //16
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;

};

struct chunk_t
{
	char ID[4];
	unsigned long size;
};


class WavObject
{
	protected:
	FILE *file;

	wav_header *header;
	short int *data; // wsk na dane
	int samples_count;

	public:
	WavObject(string f, char mode);
	
	short int* get_data();
	wav_header* get_header();
	int get_samples_count();	
	
};

class WavReader : public WavObject
{
	public:
	WavReader(string f) : WavObject(f, 'r') {}
	bool read_data();	
};

class WavWriter : public WavObject
{
	public:
	WavWriter(string f) : WavObject(f, 'w') {}
	bool write_data(short int* data, wav_header* h, int sc);
};



	
	
