>>> SEQUENCER MUZYCZNY <<<

OPIS DZIA£ANIA:
Program ma za zadanie dodaæ odpowiedni efekt dŸwiêkowy do pliku dŸwiêkowego w formacie WAV.

Program obs³uguje dodawanie efektów:
1. Delay - opóŸnienie w czasie odtwarzania dŸwiêku
2. Echo - suma sygna³ów o rosn¹cej gradacji opó¿nienia i malej¹cej gradacji amplitudy
3. Flaneger - sygna³ powsta³y z okresowo zmienij¹cego siê opoŸnienia próbek ( równie¿ ujemnego ) w wektorze danych
4. Distortion - ograniczenie amplitudy sygna³u do wartoœci œredniej wyliczonej z podanego zakresu

DIAGRAM KLAS:

	> czytanie pliku WAV ( plik "wav.h" ):
	   	
		    ____WavObject____
	   	   |		     |	
		   |		     |	
		WavRead		 WavWrite

	> dodawanie efektu do pliku ( pliki "signal.h"(interpretacja danych) i "efekt.h"(wykonywanie modyfikacji danych) )
		
			Signal
			  |
			  |
	_______________	Efekt___________________
	|	|		|		|			  
	|	|	  	|		|
      Delay	Echo	     Flanger 	Distortion


INSTRUKCJA OBS£UGI:
Nale¿y podaæ listê argumentów wywo³ywanych wraz z programem w nastêpuj¹cy sposób:

" >>>> seq.exe <nazwa efektu> [args...] <nazwa_pliku_do_przetworzenia> "


 * dla pola <nazwa_efektu> dostêpne s¹ nastêpuj¹ce opcje:
	|
	|--> delay
	|
	|--> echo
	|
	|--> flanger
	|
	|--> distortion


 * argumenty [args...] dla ka¿dego z efektów:
	|
	|--> delay 	time_delay 	ampl
	|	1. time_delay - czas opóŸnienia sygna³u w sekundach( liczba rzeczywista )
	|	2. ampl - czynnik, który zwiêksza amplitudê "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> echo 	krot 	time_delay 	ampl
	|	1. krot - okresla ilosc wyst¹pien sygna³ów naœladaj¹cych sygna³ g³ówny, ale przesuniêtych w czasie ( liczba ca³kowita )
	|	2. time_delay - okreœla interwa³ czasowy w sekundach kolejnych sygna³ów naœladuj¹cych ( liczba rzeczywista ) 
	|	3. ampl - czynnik, który zwiêksza amplitudê "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> flanger	 time_var_period 	ampl 
	|	1. time_var_period - okres w sekundach zmian opóŸnieñ dla kolejnych próbek sygna³u( liczba rzeczywista )
	|	2. ampl - czynnik, który zwiêksza amplitudê "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> distortion		dis_lvl		dis_range 	ampl 
		1. dis_lvl - wartoœæ podwy¿szaj¹ca amplitudê sygna³u ( liczba ca³kowita )
		2. dis_range - czas przedzia³u próbek (w sekundach), z których wyliczana jest œrednia, która to jest przypisywan wartoœci¹ tych próbek ( liczba rzeczywista )
		3. ampl - czynnik, który zwiêksza amplitudê "ampl-krotnie" ( liczba rzeczywista ) 


 * pole <nazwa_pliku_do_przetworzenia> zawiera nazwê bez nazwy formatu pliku( "WAV" ), z którego dane bêd¹ wczytywane, a nastêpnie modyfikowane
   zgodnie z wyborem efektu oraz jego parametrów przez u¿ytkownika.
