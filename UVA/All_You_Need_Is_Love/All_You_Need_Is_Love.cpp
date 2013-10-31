#include <iostream>
using namespace std;

int bin_to_dec( const string& s )
{
	int ret = 0, mult = 1;

	for( int i = s.size() - 1; i >= 0; i-- )
	{
		ret += ( s[i] - '0' ) * mult;
		mult *= 2;
	}

	return ret;
}

int gcd( int a, int b )
{
	if( a % b == 0 ) return b;

	return gcd( b, a % b );
}

int main()
{
	int num_pairs;
	cin >> num_pairs;

	for( int pair_no = 1; pair_no <= num_pairs; pair_no++ )
	{
		string s1, s2, ret;
		cin >> s1 >> s2;

		int is1 = bin_to_dec( s1 ), is2 = bin_to_dec( s2 );
		if( gcd( is1, is2 ) != 1 ) ret = "All you need is love!";
		else ret = "Love is not all you need!";

		cout << "Pair #" << pair_no << ": " << ret << endl; 
	}
		
	return 0;
}
