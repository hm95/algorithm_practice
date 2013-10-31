#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void print_primes_under_n( const int& n )
{
    vector <bool> prime( n + 1, true );
    prime[0] = prime[1] = false;

    for( int i = 2; i <= sqrt( n ); i++ )
        if( prime[i] )
            for( int j = 2 * i; j <= n; j += i )
                prime[j] = false;

    for( int i = 1; i <= n; i++ )
        if( prime[i] )
            cout << i << " is prime." << endl;
}

int main()
{
    int n = 100;
    print_primes_under_n( n );

    return 0; 
}
