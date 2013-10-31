#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector <int> get_primes( const int& N )
{
	vector <bool> is_prime( N + 1, true );

	for( int i = 2; i <= sqrt( N ); i++ )
		if( is_prime[i] )
			for( int j = i * i; j <= N; j += i )
				is_prime[j] = false;
	
	vector <int> list_of_primes;
	for( int i = 2; i <= N; i++ )
		if( is_prime[i] )
			list_of_primes.push_back( i );
		
	return list_of_primes;
}

int main()
{
	int N = 100;
	vector <int> primes = get_primes( N );

	cout << "All the primes less than or equal to " << N << " are: ";

	vector <int>::iterator it = primes.begin();
	while( it != primes.end() )
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	return 0;
}
