#include <iostream>
#include <vector>
using namespace std;

void find_X9091_program( string s1, string s2 )
{
	vector <int> g_tmp( s1.size() + 1 );
	vector < vector <int> > graph( s2.size() + 1, g_tmp );

	for( int row = 0; row <= s2.size(); row++ )
		graph[row][0] = row;

	for( int col = 0; col <= s1.size(); col++ )
		graph[0][col] = col;

	for( int i = 1; i <= s2.size(); i++ )
		for( int j = 1; j <= s1.size(); j++ )
		{
			if( s1[j - 1] == s2[i - 1] )
				graph[i][j] = min( 1 + min( graph[i - 1][j], graph[i][j - 1] ), graph[i - 1][j - 1] );
			else
				graph[i][j] = 1 + min( min( graph[i - 1][j], graph[i][j - 1] ), graph[i - 1][j - 1] );
		}

	int row = s2.size(), col = s1.size();
	vector <char> a, b;

	while( row > 0 && col > 0 )
	{
		if( graph[row][col] <= graph[row - 1][col] && graph[row][col] <= graph[row][col - 1] )
		{
			a.push_back( s2[row - 1] ), b.push_back( s1[col - 1] );
			row--, col--;
		}
		else if( graph[row - 1][col] <= graph[row][col - 1] && graph[row - 1][col] <= graph[row - 1][col - 1] )
		{
			a.push_back( s2[row - 1] ), b.push_back( '-' );
			row--;
		}
		else
		{
			a.push_back( '-' ), b.push_back( s1[col - 1] );
			col--;
		}
	}

	if( row == 0 )
		for( int c = col; col > 0; col-- )
			a.push_back( '-' ), b.push_back( s1[col - 1] );

	if( col == 0 )
		for( int r = row; row > 0; row-- )
			a.push_back( s2[row - 1] ), b.push_back( '-' );

	int number_of_deletions = 0;
	for( int i = a.size() - 1; i >= 0; i-- )
	{
		if( a[i] == b[i] )
			continue;
		else if( a[i] == '-' )
		{
			cout << "D" << b[i];
			if( a.size() - i - number_of_deletions < 10 ) cout << "0";
			cout << a.size() - i - number_of_deletions;

			number_of_deletions++;
			continue;
		}
		else if( b[i] == '-' ) cout << "I" << a[i];
		else cout << "C" << a[i];

		if( a.size() - i - number_of_deletions < 10 ) cout << "0";
		cout << a.size() - i - number_of_deletions;
	}
	cout << 'E' << endl;
}

int main()
{
	string s1, s2;

	while( cin >> s1 >> s2 && s1 != "#" )
		find_X9091_program( s1, s2 );

	return 0;
}
