#include<iostream>
using namespace std;

main()
{
	int pimpek = 90;
	int lalik = 10;
	int &gnom = pimpek;
	cout<<gnom<<endl;
	gnom = lalik;
	cout<<gnom<<" "<<lalik<<endl;

	return 0;
}
