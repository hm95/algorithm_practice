#include <iostream>
#include <vector>
using namespace std;

int length_of_longest_common_subsequence( string s1, string s2 )
{
	vector <int> tmp;
	for( int i = 0; i <= s2.size(); i++ )
		tmp.push_back( 0 );

	vector < vector <int> > length;
	for( int i = 0; i <= s1.size(); i++ )
		length.push_back( tmp );

	for( int j = 1; j <= s1.size(); j++ )
		for( int i = 1; i <= s2.size(); i++ )
		{
			if( s1[j - 1] == s2[i - 1] ) length[j][i] = 1 + length[j - 1][i - 1];
			else length[j][i] = max( length[j - 1][i], length[j][i - 1] );
		}

	return length[s1.size()][s2.size()];
}

int main()
{
	string s1, s2;
	while( cin >> s1 >> s2 )
		cout << length_of_longest_common_subsequence( s1, s2 ) << endl;

	return 0;
}
