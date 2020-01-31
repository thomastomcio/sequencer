// efekt.h
#include"signal.h"
#include<math.h>

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

class echo : public efekt 
{
	private:
		int krotnosc;
		double time_delay;
	public:
		echo( WavObject& wav_file, int k, double td, double a );
		
};

class flanger : public efekt // trzeba poprawic
{
	private:
		double	time_var_period;
//		double time_delay;
//		int index_delay; // do przemyslenia
	public:
		flanger( WavObject& wav_file, double tvp, double a);
		
};

class distortion: public efekt // trzeba poprawic
{
	private:
		double distortion_range;
		double distortion_lvl;
//		int index_delay; // do przemyslenia
	public:
		distortion( WavObject& wav_file, short int dis_lvl, double range,  double a);
		
};
