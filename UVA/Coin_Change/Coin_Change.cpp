#include <iostream>
#include <vector>
using namespace std;

int calc_num_ways( int num_cents, vector <int> coin_values )
{
	int num_ways_to_make[num_cents + 1];
	for( int i = 0; i <= num_cents; i++ )
		num_ways_to_make[i] = 0;

	num_ways_to_make[0] = 1;
	for( int i = 0; i < coin_values.size(); i++ )
		for( int j = 0; j + coin_values[i] <= num_cents; j++ )
			num_ways_to_make[j + coin_values[i]] += num_ways_to_make[j];

	return num_ways_to_make[num_cents];
}

int main()
{
	vector <int> coin_values;
	coin_values.push_back( 1 );
	coin_values.push_back( 5 );
	coin_values.push_back( 10 );
	coin_values.push_back( 25 );
	coin_values.push_back( 50 );

	int num_cents;
	while( cin >> num_cents )
		cout << calc_num_ways( num_cents, coin_values ) << endl;

	return 0;
}
