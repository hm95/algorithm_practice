#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_dir[] = { -1, -1, 0, 0, 1, 1 };
int col_dir[] = { -1, 0, -1, 1, 0, 1 };

bool is_in_range( const int& row, const int& col, vector < vector <char> > grid )
{
	if( row >= 0 && col >= 0 && row < grid.size() && col < grid.size() ) return true;
	return false;
}

bool can_connect( const int& cur_row, const int& cur_col, vector < vector <char> >& grid, vector < vector <bool> >& visited )
{
	visited[cur_row][cur_col] = true;
	stack < pair <int, int> > stk;
	stk.push( make_pair( cur_row, cur_col ) );

	while( !stk.empty() )
	{
		pair <int, int> tmp = stk.top();
		stk.pop();

		if( tmp.first == grid.size() - 1 ) return true;

		for( int i = 0; i < 6; i++ )
		{
			int row = tmp.first + row_dir[i];
			int col = tmp.second + col_dir[i];

			if( is_in_range( row, col, grid ) && !visited[row][col] && grid[row][col] == 'b' )
			{
				visited[row][col] = true;
				stk.push( make_pair( row, col ) );
			}
		}
	}

	return false;
}

int main()
{
	int board_size, test_no = 1;
	while( cin >> board_size )
	{
		if( board_size == 0 ) break;

		vector <bool> v_tmp;
		vector <char> g_tmp;

		for( int i = 0; i < board_size; i++ )
		{
			v_tmp.push_back( 0 );
			g_tmp.push_back( 0 );
		}

		vector < vector <bool> > visited;
		vector < vector <char> > grid;
		for( int i = 0; i < board_size; i++ )
		{
			visited.push_back( v_tmp );
			grid.push_back( g_tmp );
		}

		string line;
		for( int row = 0; row < board_size; row++ )
		{
			cin >> line;
			for( int col = 0; col < board_size; col++ )
				grid[row][col] = line[col];
		}

		bool b_wins = false;
		for( int col = 0; col < board_size; col++ )
			if( grid[0][col] == 'b' && !visited[0][col] )
				b_wins = max( b_wins, can_connect( 0, col, grid, visited ) );

		cout << test_no << ' ';
		if( b_wins ) cout << 'B' << endl;
		else cout << 'W' << endl;

		test_no++;
	}

	return 0;
}
