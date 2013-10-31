#include <iostream>
using namespace std;

int gcd( int A, int B )
{
    if( A % B == 0 ) return B;
    return gcd( B, A % B );
}

int lcm( int A, int B )
{
    return (A * B) / gcd( B, A % B );
}

int main()
{
    int A = 54, B = 78;
    cout << "The GCD of " << A << " and " << B << " is " << gcd( A, B ) << endl;
    cout << "The LCM of " << A << " and " << B << " is " << lcm( A, B ) << endl;

    return 0;
}
