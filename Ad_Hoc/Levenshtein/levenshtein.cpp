#include <iostream>
#include <vector>
using namespace std;

const int INF = 9e8;

int levenshtein( const string& a, const string& b )
{
	vector <int> l_temp( b.size() + 1, INF );
	vector < vector <int> > len( a.size() + 1, l_temp );

	for( int row = 0; row <= a.size(); row++ )
		len[row][0] = row;

	for( int col = 0; col <= b.size(); col++ )
		len[0][col] = col;

	for( int row = 1; row <= a.size(); row++ )
		for( int col = 1; col <= b.size(); col++ )
		{
			if( a[row - 1] == b[col - 1] )
				len[row][col] = min( len[row - 1][col - 1] , 1 + min( len[row - 1][col], len[row][col - 1] ) );
			else
				len[row][col] = 1 + min( len[row - 1][col - 1] , min( len[row - 1][col], len[row][col - 1] ) );
		}

	return len[a.size()][b.size()];
}

int main()
{
	string a, b;
	cin >> a >> b;

	cout << "To transform " << a << " into " << b << " takes " << levenshtein( a, b ) << " steps." << endl;

	return 0;
}
