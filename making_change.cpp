#include <iostream>
#include <vector>
using namespace std;

int num_ways( vector <int> coins, const int& num_cents )
{
	vector <int> ways( num_cents + 1, 0 );
	ways[0] = 1;

	for( int i = 0; i < coins.size(); i++ )
		for( int j = 0; j + coins[i] <= num_cents; j++ )
			ways[j + coins[i]] += ways[j];

	return ways[num_cents];
}

int main()
{
	int num_coins, num_cents;
	cin >> num_coins >> num_cents;

	vector <int> coins( num_coins );
	for( int coin_num = 0; coin_num < num_coins; coin_num++ )
		cin >> coins[coin_num];

	cout << "There are " << num_ways( coins, num_cents ) << " ways to make change for " << num_cents << " cents." << endl;

	return 0;
}
