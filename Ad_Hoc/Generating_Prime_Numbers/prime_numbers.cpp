#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector <int> get_first_n_primes( const int& N )
{
	vector <bool> is_prime( N + 1, true );

	for( int i = 2; i <= sqrt( N ); i++ )
	{
		if( !is_prime[i] ) continue;
		for( int j = i * i; j <= N; j += i )
			is_prime[j] = false;
	}

	vector <int> primes;
	for( int i = 2; i <= N; i++ )
		if( is_prime[i] )
			primes.push_back( i );

	return primes;
}

int main()
{
	int N = 211;
	vector <int> list_of_primes = get_first_n_primes( N );

	cout << "The first " << list_of_primes.size() << " primes are ";
	for( int i = 0; i < list_of_primes.size(); i++ )
		cout << list_of_primes[i] << " ";
	cout << endl;

	return 0;
}
