#include <iostream>
using namespace std;

int gcd( int a, int b )
{
    if( a % b == 0 ) return b;
    return gcd( b, a % b );
}

int lcm( int a, int b )
{
    return ( a * b ) / gcd( a, b );
}

int main()
{
    int a = 8, b = 12;

    cout << "The gcd of " << a << " and " << b << " is " << gcd( a, b ) << endl;
    cout << "The lcm of " << a << " and " << b << " is " << lcm( a, b ) << endl;

    return 0;
}
