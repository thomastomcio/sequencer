>>> SEQUENCER MUZYCZNY <<<

OPIS DZIA�ANIA:
Program ma za zadanie doda� odpowiedni efekt d�wi�kowy do pliku d�wi�kowego w formacie WAV.

Program obs�uguje dodawanie efekt�w:
1. Delay - op�nienie w czasie odtwarzania d�wi�ku
2. Echo - suma sygna��w o rosn�cej gradacji op�nienia i malej�cej gradacji amplitudy
3. Flaneger - sygna� powsta�y z okresowo zmienij�cego si� opo�nienia pr�bek ( r�wnie� ujemnego ) w wektorze danych
4. Distortion - ograniczenie amplitudy sygna�u do warto�ci �redniej wyliczonej z podanego zakresu

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


INSTRUKCJA OBS�UGI:
Nale�y poda� list� argument�w wywo�ywanych wraz z programem w nast�puj�cy spos�b:

" >>>> seq.exe <nazwa efektu> [args...] <nazwa_pliku_do_przetworzenia> "


 * dla pola <nazwa_efektu> dost�pne s� nast�puj�ce opcje:
	|
	|--> delay
	|
	|--> echo
	|
	|--> flanger
	|
	|--> distortion


 * argumenty [args...] dla ka�dego z efekt�w:
	|
	|--> delay 	time_delay 	ampl
	|	1. time_delay - czas op�nienia sygna�u w sekundach( liczba rzeczywista )
	|	2. ampl - czynnik, kt�ry zwi�ksza amplitud� "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> echo 	krot 	time_delay 	ampl
	|	1. krot - okresla ilosc wyst�pien sygna��w na�ladaj�cych sygna� g��wny, ale przesuni�tych w czasie ( liczba ca�kowita )
	|	2. time_delay - okre�la interwa� czasowy w sekundach kolejnych sygna��w na�laduj�cych ( liczba rzeczywista ) 
	|	3. ampl - czynnik, kt�ry zwi�ksza amplitud� "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> flanger	 time_var_period 	ampl 
	|	1. time_var_period - okres w sekundach zmian op�nie� dla kolejnych pr�bek sygna�u( liczba rzeczywista )
	|	2. ampl - czynnik, kt�ry zwi�ksza amplitud� "ampl-krotnie" ( liczba rzeczywista ) 
	|
	|--> distortion		dis_lvl		dis_range 	ampl 
		1. dis_lvl - warto�� podwy�szaj�ca amplitud� sygna�u ( liczba ca�kowita )
		2. dis_range - czas przedzia�u pr�bek (w sekundach), z kt�rych wyliczana jest �rednia, kt�ra to jest przypisywan warto�ci� tych pr�bek ( liczba rzeczywista )
		3. ampl - czynnik, kt�ry zwi�ksza amplitud� "ampl-krotnie" ( liczba rzeczywista ) 


 * pole <nazwa_pliku_do_przetworzenia> zawiera nazw� bez nazwy formatu pliku( "WAV" ), z kt�rego dane b�d� wczytywane, a nast�pnie modyfikowane
   zgodnie z wyborem efektu oraz jego parametr�w przez u�ytkownika.
