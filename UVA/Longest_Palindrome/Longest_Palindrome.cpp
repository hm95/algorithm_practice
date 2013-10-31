#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longest_common_subsequence( string a, string b )
{
	vector <int> row( b.size() + 1, 0 );
	vector < vector <int> > lcs( a.size() + 1, row );

	for( int i = 1; i <= a.size(); i++ )
		for( int j = 1; j <= b.size(); j++ )
		{
			if( a[i - 1] == b[j - 1] ) lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else lcs[i][j] = max( lcs[i - 1][j], lcs[i][j - 1] );
		}
	
	return lcs[a.size()][b.size()];
}

int main()
{
	int num_strings;
	cin >> num_strings;

	string current_string;
	getline( cin, current_string );

	while( getline( cin, current_string ) )
	{
		if( current_string == "" ) cout << 0 << endl;
		else
		{
			string reversed_string = current_string;
			reverse( reversed_string.begin(), reversed_string.end() );

			cout << longest_common_subsequence( current_string, reversed_string ) << endl;
		}
	}

	return 0;
}
