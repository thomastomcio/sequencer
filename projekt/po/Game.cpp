// Game.cpp
#include"Game.h"

Game::Game() : mapa(Map(0))
{	
	file_open("config.txt");
	mapa = Map( map_len );
	gracz = new Player( pstats[0], pstats[1], pstats[2], pstats[3], pstats[4] );
       	pusty = new Empty(); 	
	middle = map_len/2;
	cursor = &mapa[middle][middle];
	x_aktual = cursor->get_x();
	y_aktual = cursor->get_y(); 
} 

Game::Game( string path ) : mapa(Map(0))
{
	file_open(path);
	mapa = Map( map_len );
	gracz = new Player( pstats[0], pstats[1], pstats[2], pstats[3], pstats[4] );
       	pusty = new Empty(); 	
	middle = map_len/2;
	cursor = &mapa[middle][middle];
	x_aktual = cursor->get_x();
	y_aktual = cursor->get_y(); 
}

void Game::file_open(string path)
{
	fstream plik(path, ios::in);
	string linia;
	string key;
	string statstr;
	regex expr("(?!\\w+\\s*=\\s*)([0-9]+)");
	smatch sm;

	if (plik.is_open())
	{
		while( plik >> key && key!="####GAME####")
		{
			plik.get();
			getline( plik, linia); 
			messages[key] = linia;
		}
		map_len = stoi(messages["map_len"]);
		while( true )
		{
			getline(plik, linia);
			if( linia != "####STATS####" )
			{
			statstr += linia + '\n' ;
			}
			else
			break;
		}
		int i = 0;

		while( regex_search( statstr, sm, expr) )
		{
			pstats[i] = stoi(sm.str());
			statstr = sm.suffix();
			i++;
		}
		plik.close();
	}	

}

void Game::start()
{
	system("cls");
	cursor->aktualny = gracz;
	cursor->zakulisowy = pusty;
	cout<<messages["wprowadzenie"]<<endl;
	mapa.wyswietl();
	cout<<messages["kontynuacja"]<<endl;

	while ( idz() )
	{
		system("cls");
		if( !aktualizuj_mape() )
		{	system("cls");
			cout<<messages["przegrana"] <<endl;
			exit(0);
		}

	}
	system("cls");
	cout<<messages["gratulacje"]<<endl;

}
bool Game::process(Player* pl, Character* ch)
{
	int& hp_ref = pl->pfeatures.get_hp();
	(pl->pfeatures.get_mana() += ch->features.get_mana()) < 0 ? (hp_ref-= 10) : true;
	(pl->pfeatures.get_speed() += ch->features.get_speed()) < 0 ? (hp_ref-= 10) : true;
	(pl->pfeatures.get_strength() += ch->features.get_strength()) < 0 ? (hp_ref-= 10) : true;
	(pl->pfeatures.get_money() += ch->features.get_money()) < 0 ? (hp_ref-= 10) : true;

	if( hp_ref <= 0 )
	{return false;}
	else
	{return true;}
} 

bool Game::aktualizuj_mape()
{
	cursor->aktualny = cursor->zakulisowy; // stary cursor
	cursor = &mapa[x_aktual][y_aktual]; // nowy cursor
	cursor->aktualny = cursor->zakulisowy; 
	cursor->zakulisowy = pusty;

	mapa.wyswietl();
	cout<<endl;
	cout<<messages["natrafiles"]<<endl;
	cursor->aktualny->show_stats();
	cout<<endl;
	cout<<messages["statystyki"]<<endl;
	gracz->show_stats();
	cout<<endl;
	if( typeid(Empty) == typeid(*cursor->aktualny) )
	{
		if( gracz->pfeatures.item_count != 0 )
		{
			cout<<messages["czy_zostawic"]<<endl;
			char wybor;
			cin >> wybor;
			switch(wybor)
			{
				case 't': cursor->zakulisowy = &(gracz->dropItem());
					  break;
				default : break;
			}
		}

	}	

	if( typeid(Item) == typeid(*cursor->aktualny) )
	{
		cout<<messages["czy_podniesc"]<<endl;
		char wybor;
		cin >> wybor;
		switch(wybor)
		{
			case 't': gracz->pickItem(*(Item*)cursor->aktualny);
				break;
			default : cursor->zakulisowy = cursor->aktualny;
				  break;

		}
	}
	cout<<endl;	
	cout<<messages["kontynuacja"]<<endl;
	_getch();
	system("cls");

	if( process(gracz, cursor->aktualny))
	{
		cursor->aktualny = gracz;
		mapa.wyswietl();
		cout<<messages["kierunek"]<<endl;
		return true;
	}else 
		{return false;}
}

bool Game::idz()
{
	x_plus = 0; y_plus = 0;
	unsigned char znak1, znak2;
	while(true)
	{
		znak1 = _getch();
		if(_kbhit())
		{
			znak2 = _getch();
			if( static_cast<int>(znak1) == 224 )
			{
				switch(static_cast<int>(znak2))
				{
					case 72: x_plus--; 
						break;
					case 80: x_plus++;
						break;
					case 75: y_plus--;
						break;
					case 77: y_plus++;
						 break;
				}
				x_aktual += x_plus;
				y_aktual += y_plus;
				break;
			}
		}
	}

       if( x_aktual!= -1 && y_aktual != -1 && x_aktual != map_len && y_aktual != map_len )
       {
	       return true;
       } else
       {
	       return false;
       }
}



Game::~Game()
{
	delete pusty;
	delete cursor;
	delete gracz;
}
