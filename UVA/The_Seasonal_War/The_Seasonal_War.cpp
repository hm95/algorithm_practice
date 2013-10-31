#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row_dir[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int col_dir[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int is_in_range( const int& row, const int& col, const int& board_size )
{
	if( row >= 0 && col >= 0 && row < board_size && col < board_size ) return true;
	return false;
}

void visit( const int& row, const int& col, vector < vector <int> >& grid, vector < vector <int> >& visited )
{
	visited[row][col] = true;
	queue < pair <int, int> > q;
	q.push( make_pair( row, col ) );

	while( !q.empty() )
	{
		pair <int, int> tmp = q.front();
		q.pop();

		for( int i = 0; i < 8; i++ )
		{
			int row = tmp.first + row_dir[i];
			int col = tmp.second + col_dir[i];

			if( is_in_range( row, col, grid.size() ) && !visited[row][col] && grid[row][col] == 1 )
			{
				visited[row][col] = true;
				q.push( make_pair( row, col ) );
			}
		}
	}
}

int main()
{
	int board_size, img_no = 1;
	while( cin >> board_size )
	{
		vector <int> tmp;
		vector <string> line_val;
		for( int i = 0; i < board_size; i++ )
		{
			tmp.push_back( 0 );

			string s;
			cin >> s;
			line_val.push_back( s );
		}

		vector < vector <int> > grid, visited;
		for( int i = 0; i < board_size; i++ )
		{
			visited.push_back( tmp );
			grid.push_back( tmp );
		}

		for( int i = 0; i < board_size; i++ )
			for( int j = 0; j < board_size; j++ )
				grid[i][j] = line_val[i][j] - '0';

		int num_war_eagles = 0;
		for( int i = 0; i < board_size; i++ )
			for( int j = 0; j < board_size; j++ )
				if( grid[i][j] == 1 && !visited[i][j] )
				{
					visit( i, j, grid, visited );
					num_war_eagles++;
				}

		cout << "Image number " << img_no << " contains " << num_war_eagles << " war eagles." << endl;

		img_no++;
		visited.clear();
		grid.clear();
		tmp.clear();
	}

	return 0;
}
