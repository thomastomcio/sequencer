// wav.cpp
#include"wav.h"
#include<iostream>
using namespace std;


WavObject::WavObject( string f, char mode ) : data(nullptr), header(new wav_header)
{
	switch(mode)
	{
		case 'r' : file = fopen(f.c_str(), "rb");
			break;
		case 'w' : file = fopen(f.c_str(), "wb");
	}
}

short int* WavObject::get_data ()
{
	return data;
}

wav_header* WavObject::get_header()
{
	return header;
}

int WavObject::get_samples_count()
{
	return samples_count;
}	

bool WavReader::read_data()
{
	// czytaj header
	fread(header, sizeof(wav_header), 1, file);
	// znajdz i czytaj dane
	chunk_t chunk;
	while(true)
	{
	fread(&chunk, sizeof(chunk), 1, file); 
        if (*(unsigned int *)&chunk.ID == 0x61746164)
            break;
        //skip chunk data bytes
        fseek(file, chunk.size, SEEK_CUR);
   	}
    //Number of samples
    int sample_size = header->bitsPerSample / 8;

    samples_count = chunk.size * 8 / header->bitsPerSample;

    data= new short int[samples_count];
    memset(data, 0, sizeof(short int) * samples_count);

    //Reading data
    //for(int i = 0; i < samples_count; i++)
    //{
        fread(data, sample_size, samples_count, file);
    //}
	fclose(file);
	return true;
	
}

bool WavWriter::write_data(short int* d, wav_header* h, int sc)
{
	header = h;
	data = d;
	fwrite(header, sizeof(wav_header), 1, file);

	chunk_t data_chunk;
	int samples_count = sc;

	*(unsigned int *)&data_chunk.ID = 0x61746164;
    	int sample_size = header->bitsPerSample / 8;
	data_chunk.size = samples_count * sample_size;

	fwrite(&data_chunk, sizeof(data_chunk), 1, file);
	cout<<">>>> Data writing <<<<"<<endl;
	cout<<"Samples count:"<<samples_count<<endl;
	cout<<"Sample size: "<<sample_size<<endl;	
	//Writing data
	for(int i = 0; i < samples_count; i++)
	{
	//	cout<<data[i]<<" "<<i<<endl;
		fwrite(&data[i], sample_size, 1, file);
	}
fclose(file);
return true;
}


