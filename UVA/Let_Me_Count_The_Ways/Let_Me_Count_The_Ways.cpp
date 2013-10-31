#include <iostream>
#include <vector>
using namespace std;

long long num_ways_to_produce( long long num_cents, vector <long long> coins )
{
	vector <long long> num_ways( num_cents + 1, 0 );
	num_ways[0] = 1;

	for( long long i = 0; i < coins.size(); i++ )
		for( long long j = 0; j + coins[i] <= num_cents; j++ )
			num_ways[j + coins[i]] += num_ways[j];

	return num_ways[num_cents];
}

int main()
{
	vector <long long> coins;
	coins.push_back( 1 );
	coins.push_back( 5 );
	coins.push_back( 10 );
	coins.push_back( 25 );
	coins.push_back( 50 );

	long long num_cents;
	while( cin >> num_cents )
	{
		long long num_ways = num_ways_to_produce( num_cents, coins );

		if( num_ways != 1 )
			cout << "There are " << num_ways_to_produce( num_cents, coins ) << " ways to produce " << num_cents << " cents change." << endl;
		else
			cout << "There is only 1 way to produce " << num_cents << " cents change." << endl;
	}

	return 0;
}
