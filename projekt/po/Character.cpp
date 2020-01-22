//Character.cpp
#include "Character.h"

// std::srand(time(NULL)); to nie dziala

char Character::get_symbol()
{
	return symbol;
}

void Player::typ()
{
	cout<<"Player"<<endl;
}

void Monster::typ()
{
	cout<<"Monster"<<endl;
}

void Hidden::typ()
{
	cout<<"Pole ukryte"<<endl;
}
	
void Empty::typ()
{
	cout<<"Czyste pole"<<endl;
}

void Item::typ()
{
	cout<<"Artefakt"<<endl;
}

Player* Player::clone()
{
	return nullptr; // tak musi byc przy unique_ptr
       			// nie moze byc zdefiniowany
			// copy constructor	
}

Monster* Monster::clone()
{
	return new Monster(*this);
}

Hidden* Hidden::clone()
{
	return new Hidden(*this);
}

Empty* Empty::clone()
{
	return new Empty(*this);
}

Item* Item::clone()
{
	return nullptr;
}
// show_stats functions
//
void Player::show_stats()	
{
        cout<<"hp : " + to_string(pfeatures.get_hp())<<endl;
        cout<<"mana : " + to_string(pfeatures.get_mana())<<endl;
        cout<<"money : " + to_string(pfeatures.get_money())<<endl;
        cout<<"speed : " + to_string(pfeatures.get_speed())<<endl;
        cout<<"strenght : " + to_string(pfeatures.get_strength())<<endl;
}

void Monster::show_stats()	
{
	this->typ();
        cout<<"-- mana : " + to_string(features.get_mana())<<endl;
        cout<<"-- money : " + to_string(features.get_money())<<endl;
        cout<<"-- speed : " + to_string(features.get_speed())<<endl;
        cout<<"-- strenght : " + to_string(features.get_strength())<<endl;
}

void Item::show_stats()
{
	this->typ();

}

void Empty::show_stats()
{
	this->typ();
}

void Hidden::show_stats()
{
	this->typ();
}

Item& Player::dropItem()
{
	cout<<"Odrzucono item"<<endl;
	return *(items.back());
	
}

void Player::pickItem(Item& item)
{
	unique_ptr<Item> ptr (&item);
	items.push_back(move(ptr));		
	pfeatures.item_count++;
}
