// Statistics.h

class Statistics
{
	private:

		int hp;
		int mana;
		int money;
		int speed;
		int strength;
	public:
		Statistics(int h = 0, int m = 0, int mo = 0, int sp = 0, int str = 0) \
				   : hp(h), mana(m), money(mo), speed(sp), strength(str) {}

		int& get_hp() {return hp;}
		int& get_mana() {return mana;}
		int& get_money() {return money;}
		int& get_speed() {return speed;}
		int& get_strength() {return strength;}

};

class Player_Statistics : public Statistics
{
	public:
		Player_Statistics(int h=0, int m=0, int mo=0, int sp=0, int str=0, int counter=0)\
				       	: Statistics(h, m, mo, sp, str), item_count(counter) {}

		int item_count;
};
