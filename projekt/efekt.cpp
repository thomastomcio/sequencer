// efekt.cpp
#include"efekt.h"


efekt::efekt(WavObject& wf, double ftp, double a) : signal(wf), frame_time_period(ftp), amplitude(a)
{
	frame_data_period = frame_time_period * header->sampleRate * 2; // ilosc podzialow	
	int interval_count = samples_count / frame_data_period; // okres danych (ilosc danych w okresie)
	ramki = vector<klatka>(interval_count, klatka(frame_data_period));
}

delay::delay( WavObject& wav_file, double td, double ftp, double a ) : time_delay(td), efekt(wav_file, ftp, a) 
{
	index_delay = time_delay * header->sampleRate*2; //
	signal delay_t( samples_count, 0, header); // trzeba zrobic
	signal frame_window( samples_count, 0, header); // trzeba zrobic

	cout<<"id_delay: "<<index_delay<<endl;
	cout<<"frame_data_period: "<<frame_data_period<<endl;
	cout<<"frame_count: "<<ramki.size()<<endl;
	cout<<"sample_count: "<<samples_count<<endl;
	int to_add;
	for( int i=0; i < ramki.size(); i++)
	{
			//cout<<"jestem"<<endl;
		for(int k = ramki[i].beg_id; k+index_delay <= ramki[i].end_id; k++)
		{
			
			if(abs(amplitude*data[k]) > 32767) 
			{ to_add = sgn(amplitude*data[k])*32767;}
			else
			{ to_add = amplitude * data[k];}
			frame_window[k+index_delay] = to_add ;		
		}
		delay_t += frame_window;
	}
	 data = delay_t.data;
}

flanger::flanger( WavObject& wav_file, double ftp, double a ) : efekt(wav_file, ftp, a) 
{
// w jednej klatce ma sie zmiescic jeden okres sinusoidy wyznaczajacej przesuniecie( opznienie ) zgodnie z td

	double step_unit = 2 * M_PI / frame_data_period;
	cout<<step_unit<<endl;
	signal frame_window( samples_count, 0, header);

	double previous = 0;
	int intermediate = 0;
	int frame_beg;
	int frame_end;
	for( int i=0; i < ramki.size(); i++)
	{
		frame_beg = ramki[i].beg_id;
		frame_end = ramki[i].end_id;
		for( int p = 0; p <= frame_data_period; p++)
		{
			double current = sin(p*step_unit);
			if( current > previous)
			{
				intermediate++;
			}
			else if ( current < previous )
			{
				intermediate--;
			}
			frame_window[ frame_beg + intermediate ] = amplitude * data[ frame_beg + p];	
			previous = current;
		}
	}
		
	signal(*this) += frame_window;
	cout<<"hej"<<endl;
}

echo::echo( WavObject& wav_file, int k, double td, double ftp, double a ) : krotnosc(k), delay(wav_file, td, ftp, a) 
{
	signal &ref =  *this;
	
	for(int i = 2 ; i <= krotnosc; i++)
	{
		ref += (signal)delay(wav_file, time_delay*k, frame_time_period, amplitude/k);
	}
	cout<<"hello"<<endl;
	
	(signal)*this = ref;

}

distortion::distortion( WavObject& wav_file, double dis_lvl, double ftp, double a ) : distortion_lvl(dis_lvl), efekt(wav_file, ftp, a) 
{

}
/*
signal delay::add_frame( klatka& ramka, signal& sig )
{
	

	return frame_window;
}
delay::delay( signal& sig, double td, double ftp, double a ) : time_delay(td), efekt(sig, ftp, a)
{
	index_delay = time_delay * header->sampleRate; //
	signal delay( samples_count, 0, header); // trzeba zrobic
	signal frame_window( samples_count, 0, header); // trzeba zrobic

	for( int i=0; i < ramki.size(); i++)
	{
			//cout<<"jestem"<<endl;
		for(int k = ramki[i].beg_id; k+index_delay <= ramki[i].end_id; k++)
		{
			frame_window[k+index_delay] = data[k];		
		}
		delay += frame_window;
	}

	signal::data = delay.data;
}


efekt::efekt(signal& sig, double ftp, double a): signal(sig), frame_time_period(ftp), amplitude(a)
{
	frame_data_period = frame_time_period * header->sampleRate * 2; // ilosc podzialow	
	int interval_count = samples_count / frame_data_period; // okres danych (ilosc danych w okresie)
	ramki = vector<klatka>(interval_count, klatka(frame_data_period));
		
}

*/
