#include <iostream>
#include <vector>
using namespace std;

int num_ways( int num_cents, vector <int> coins )
{
	vector <int> num_ways( num_cents + 1, 0 );
	num_ways[0] = 1;

	for( int i = 0; i < coins.size(); i++ )
		for( int j = 0; j + coins[i] <= num_cents; j++ )
			num_ways[j + coins[i]] += num_ways[j];
	
	return num_ways[num_cents];
}

int main()
{
	vector <int> coins;

	int num_cents;
	cin >> num_cents;

	int coin_value;
	while( cin >> coin_value )
		coins.push_back( coin_value );
	
	cout << "There are " << num_ways( num_cents, coins ) << " to make " << num_cents << " cents." << endl;

	return 0;
}
