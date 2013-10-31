#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector <int> get_list_of_primes( const int& N )
{
	bool* is_prime = new bool[N + 1];
	memset( is_prime, 1, sizeof( bool ) * ( N + 1 ) ); 
	
	for( int i = 2; i <= sqrt( N ); i++ )
	{
		if( is_prime[i] )
			for( int j = i * i; j <= N; j += i )
				is_prime[j] = false;
	}

	vector <int> list_of_primes;
	for( int i = 3; i <= N; i++ )
		if( is_prime[i] == true )
			list_of_primes.push_back( i );

	return list_of_primes;
}

vector < pair <int, int> > get_twin_pairs_of_primes( vector <int> primes )
{
	vector < pair <int, int> > twin_prime_pairs;
	int num_primes = primes.size() - 1;

	for( int i = 0; i < num_primes; i++ )
		if( primes[i] == primes[i + 1] - 2 )
			twin_prime_pairs.push_back( make_pair( primes[i], primes[i] + 2 ) );

	return twin_prime_pairs;
}

int main()
{
	vector <int> list_of_primes = get_list_of_primes( 20000000 );
	vector < pair <int, int> > twin_pairs_of_primes = get_twin_pairs_of_primes( list_of_primes );

	int nth;
	while( cin >> nth )
		cout << "(" << twin_pairs_of_primes[nth - 1].first << ", " << twin_pairs_of_primes[nth - 1].second << ")" << endl;
	
	return 0;
}
