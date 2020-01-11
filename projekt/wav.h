#include

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
}


class WavObject
{
	private:
	string file;
	/*float type*/ data ;
	public:
	WavObject( string f) : file(f) {}
	
	
};

class WavReader : WavObject
{
	public:
/*float type*/	read_data();	
};

class WavWriter : WavObject
{
	private:
	public:
	write_data(vector</*float type*/> dane);
};



	
	
