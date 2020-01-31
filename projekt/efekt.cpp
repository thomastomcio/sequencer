// efekt.cpp
#include"efekt.h"

delay::delay( WavObject& wav_file, double td, double a ) : time_delay(td), efekt(wav_file, a) 
{
	index_delay = time_delay * header->sampleRate*2; 
	signal delay_calc( samples_count, 0, header); 

	cout<<"index_delay: "<<index_delay<<endl;

	for(int k = 0 ; k+index_delay < samples_count; k++)
	{
/*		
		if(abs(amplitude*data[k]) > 32767) 
		{ to_add = sgn(amplitude*data[k])*32767;}
		else
		{ to_add = amplitude * data[k];}
*/
		delay_calc[k+index_delay] = amplitude * data[k];
	}
	
	data = delay_calc.data;
}

echo::echo( WavObject& wav_file, int k, double td, double a ) : krotnosc(k), time_delay(td), efekt(wav_file, a) 
{
	signal &ref = *this;
	double new_time_delay = time_delay/k;
	double new_amplitude = amplitude /2 ;  // ze skali decybelowej
	for(int i = 1 ; i < krotnosc+1; i++)
	{
		cout<<"new_amplitude: "<<new_amplitude<<endl;
		ref += delay(wav_file, time_delay*i, new_amplitude);
		new_amplitude = new_amplitude/2 ;
	}
	data = ref.data;
}

flanger::flanger( WavObject& wav_file, double tvp, double a ) : time_var_period(tvp), efekt(wav_file, a) 
{
	signal flanger_calc( samples_count, 0, header); 
	int data_var_delay = time_var_period * header->sampleRate*2; 
	int index_delay = 0;
	double current = 0;

	for( int i = 0; i <= samples_count; i++)
	{
		current = sin(2*M_PI*i/ data_var_delay);
		index_delay = data_var_delay * current;	

		if( 0 < index_delay + i && index_delay + i <samples_count)
		{
			flanger_calc[index_delay + i] = amplitude * data [i] + data[index_delay + i];
		}
		else continue;

		//frame_window[ frame_beg + intermediate ] = amplitude * data[ frame_beg + p];	
	}

	data = flanger_calc.data;
}

distortion::distortion( WavObject& wav_file, short int dis_lvl, double range,  double a ) : distortion_lvl(dis_lvl),distortion_range(range), efekt(wav_file, a) 
{
	signal distortion_count( samples_count, 0, header); 
	short int sum = 0;
	short int mean = 0;
	for( int i = 0; (i+1) * distortion_range < samples_count; i++)
	{
		for( int j = i * distortion_range; j < (i+1)*distortion_range; j++)
		{
		     sum += data[j];
		}
		mean = sum / distortion_range;

		for( int k = i * distortion_range; k < (i+1)*distortion_range; k++)
		{
        	    distortion_count[k] = amplitude * mean + distortion_lvl;
		}
	}
	data = distortion_count.data;
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
