#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

void connect( int row, int col, vector < vector <int> >& graph )
{
	int x = graph[row][col];
	stack < pair <int, int> > stk;
	stk.push( make_pair( row, col ) );

	while( !stk.empty() )
	{
		pair <int, int> cur = stk.top();
		stk.pop();

		graph[cur.first][cur.second] = -1;

		for( int i = 0; i < 4; i++ )
		{
			int row_temp = cur.first + row_direction[i];
			int col_temp = cur.second + column_direction[i];

			if( is_in_range( row_temp, col_temp, graph.size(), graph.size() ) && graph[row_temp][col_temp] == x )
				stk.push( make_pair( row_temp, col_temp ) );
		}
	}
}

int main()
{
	string s;
	while( getline( cin, s ) && s != "0" )
	{
		int side_length;
		istringstream iss( s );
		iss >> side_length; 

		vector <int> graph_tmp( side_length, side_length );
		vector < vector <int> > graph( side_length, graph_tmp );

		int row, col;
		for( int i = 1; i < side_length; i++ )
		{
			getline( cin, s );
			istringstream bss( s );

			while( bss >> row >> col )
				graph[row - 1][col - 1] = i;
		}

		int num_divisions = 0;
		for( int row = 0; row < side_length; row++ )
			for( int col = 0; col < side_length; col++ )
				if( graph[row][col] != -1 )
				{
					num_divisions++;
					connect( row, col, graph );
				}

		if( num_divisions == side_length ) cout << "good" << endl;
		else cout << "wrong" << endl;
	}

	return 0;
}
