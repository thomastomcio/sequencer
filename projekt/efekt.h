// efekt.h
#include"signal.h"

class efekt : public signal
{
	protected:
		double amplitude;
	public:
		efekt(WavObject& wf, double a) : signal(wf), amplitude(a) {}
//		efekt( signal& sig, double a );
};

class delay : public efekt
{
	protected:
		double time_delay;
		int index_delay;
	public:
		delay( WavObject& wav_file, double td, double a );
//		delay( signal& sig, double td, double a );
};

class echo : public delay
{
	private:
		int krotnosc;
	public:
		echo( WavObject& wav_file, int k, double td, double a );
		
};

class flanger : public efekt // trzeba poprawic
{
//	private:
//		double time_delay;
//		int index_delay; // do przemyslenia
	public:
		flanger( WavObject& wav_file, double a);
		
};

class distortion: public efekt // trzeba poprawic
{
	private:
		double distortion_lvl;
//		int index_delay; // do przemyslenia
	public:
		distortion( WavObject& wav_file, double dis_lvl, double a);
		
};
