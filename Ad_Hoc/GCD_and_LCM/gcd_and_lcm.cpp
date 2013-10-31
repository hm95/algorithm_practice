#include <iostream>
using namespace std;

int gcd( const int& a, const int& b )
{
	if( a % b == 0 ) return b;
	return gcd( b, a % b );
}

int lcm( const int& a, const int& b )
{
	return a * b / gcd( a, b );
}

int main()
{
	int a = 21, b = 6;
	cout << "The GCD of " << a << " and " << b << " is " << gcd( a, b ) << endl;
	cout << "The LCM of " << a << " and " << b << " is " << lcm( a, b ) << endl;

	return 0;
}
