#include <iostream>
#include <vector>
using namespace std;

void compute_string_transformation( string a, string b )
{
	vector <int> g_tmp( a.size() + 1 );
	vector < vector <int> > graph( b.size() + 1, g_tmp );

	for( int row = 0; row <= b.size(); row++ )
		graph[row][0] = row;

	for( int col = 0; col <= a.size(); col++ )
		graph[0][col] = col;

	for( int i = 1; i <= b.size(); i++ )
		for( int j = 1; j <= a.size(); j++ )
		{
			if( a[j - 1] == b[i - 1] )
				graph[i][j] = min( 1 + min( graph[i - 1][j], graph[i][j - 1] ), graph[i - 1][j - 1] );
			else
				graph[i][j] = 1 + min( min( graph[i - 1][j], graph[i][j - 1] ), graph[i - 1][j - 1] );
		}

	cout << graph[b.size()][a.size()] << endl;

	int row = b.size(), col = a.size();
	vector <char> transformed_a, transformed_b;

	while( row > 0 && col > 0 )
	{
		if( graph[row][col] <= graph[row - 1][col] && graph[row][col] <= graph[row][col - 1] )
		{
			transformed_a.push_back( b[row - 1] ), transformed_b.push_back( a[col - 1] );
			row--, col--;
		}
		else if( graph[row - 1][col] <= graph[row][col - 1] && graph[row - 1][col] <= graph[row - 1][col - 1] )
		{
			transformed_a.push_back( b[row - 1] ), transformed_b.push_back( '-' );
			row--;
		}
		else
		{
			transformed_a.push_back( '-' ), transformed_b.push_back( a[col - 1] );
			col--;
		}
	}

	if( row == 0 )
		for( int c = col; c > 0; c-- )
			transformed_a.push_back( '-' ), transformed_b.push_back( a[c - 1] );

	if( col == 0 )
		for( int r = row; r > 0; r-- )
			transformed_a.push_back( b[r - 1] ), transformed_b.push_back( '-' );

	int number_of_deletions = 0;
	int step = 1;
	for( int i = transformed_a.size() - 1; i >= 0; i-- )
	{
		if( transformed_a[i] == transformed_b[i] )
			continue;

		cout << step << ' ';
		if( transformed_a[i] == '-' )
		{
			cout << "Delete " << transformed_a.size() - i - number_of_deletions << endl;
			number_of_deletions++, step++;
			continue;
		}
		else if( transformed_b[i] == '-' ) cout << "Insert ";
		else cout << "Replace ";
		step++;

		cout << transformed_a.size() - i - number_of_deletions << "," << transformed_a[i] << endl;
	}
}

int main()
{
	string a, b;
	bool first = true;

	while( getline( cin, a ) && getline( cin, b ) )
	{
		if( !first ) cout << endl;
		if( first ) first = false;

		compute_string_transformation( a, b );
	}

	return 0;
}
