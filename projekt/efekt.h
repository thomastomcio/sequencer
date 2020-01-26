// efekt.h
#include"signal.h"

class efekt : public signal
{
	protected:
		double amplitude;
		double frame_time_period;
		int frame_data_period;
		vector<klatka> ramki;

	public:
		efekt( WavObject& wf, double ftp, double a ); 
		efekt( signal& sig, double ftp, double a );
		// efekt(klatka& frame, wav_header* h) : signal(frame, h), freq 
		
		//virtual vector<short int>
		//virtual signal add_frame( klatka& ramka, signal& sig) = 0; 
			 
};


class delay : public efekt
{
	protected:
		double time_delay;
		int index_delay;
	public:
		delay( WavObject& wav_file, double td, double ftp, double a );
		delay( signal& sig, double td, double ftp, double a );
	//	signal add_frame( klatka& ramka, signal& sig );
		
};

class echo : public delay
{
	private:
	int krotnosc;
	public:
		echo( WavObject& wav_file, int k, double td, double ftp, double a );
		
};

class flanger : public efekt // trzeba poprawic
{
//	private:
//		double time_delay;
//		int index_delay; // do przemyslenia
	public:
		flanger( WavObject& wav_file, double ftp, double a);
		
};

class distortion: public efekt // trzeba poprawic
{
	private:
		double distortion_lvl;
//		int index_delay; // do przemyslenia
	public:
		distortion( WavObject& wav_file, double dis_lvl, double ftp, double a);
		
};
