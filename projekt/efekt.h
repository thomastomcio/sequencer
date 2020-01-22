// efekt.h
#include"signal.h"
#include<math.h>

#define sgn(x) (signbit(x) ? -1 : 1)

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
	private:
		double time_delay;
		int index_delay;
	public:
		delay( WavObject& wav_file, double td, double ftp, double a );
		delay( signal& sig, double td, double ftp, double a );
	//	signal add_frame( klatka& ramka, signal& sig );
		
};

class echo : public efekt
{
};

class flanger : public efekt
{
};
