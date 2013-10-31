#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

vector < vector <char> > graph;
vector < vector < vector <bool> > > visited;

struct pos
{
	int row, col, cost, state;
};

int row_dir[3][4] = 
{
	{ 1, -1, 0, 0 },
	{ 2, -2, 0, 0 },
	{ 3, -3, 0, 0 }
};

int col_dir[3][4] = 
{
	{ 0, 0, 1, -1 },
	{ 0, 0, 2, -2 },
	{ 0, 0, 3, -3 }
};

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

bool no_obstacles( int starting_row, int starting_col, int ending_row, int ending_col )
{
	if( starting_row > ending_row ) swap( starting_row, ending_row );
	if( starting_col > ending_col ) swap( starting_col, ending_col );

	if( starting_row == ending_row )
	{
		for( int col = starting_col; col <= ending_col; col++ )
			if( graph[starting_row][col] == '#' )
				return false;
	}
	else
	{
		for( int row = starting_row; row <= ending_row; row++ )
			if( graph[row][starting_col] == '#' )
				return false;
	}

	return true;
}

int main()
{
	int num_tests_cases;
	cin >> num_tests_cases;

	int num_rows, num_cols;
	for( int test_case_num = 0; test_case_num < num_tests_cases; test_case_num++ )
	{
		cin >> num_rows >> num_cols;

		graph.resize( num_rows );
		for( int i = 0; i < num_rows; i++ )
			graph[i].resize( num_cols );

		string line;
		int starting_row, starting_col, ending_row, ending_col;
		for( int row = 0; row < num_rows; row++ )
		{
			cin >> line;
			for( int col = 0; col < num_cols; col++ )
			{
				graph[row][col] = line[col];

				if( graph[row][col] == 'S' )
					starting_row = row, starting_col = col;
				if( graph[row][col] == 'E' )
					ending_row = row, ending_col = col;
			}
		}

		visited.resize( num_rows );
		for( int i = 0; i < num_rows; i++ )
			visited[i].resize( num_cols );

		for( int i = 0; i < num_rows; i++ )
			for( int j = 0; j < num_cols; j++ )
				visited[i][j].resize( 3 );

		for( int i = 0; i < num_rows; i++ )
			for( int j = 0; j < num_cols; j++ )
				for( int k = 0; k < 3; k++ )
					visited[i][j][k] = false;

		visited[starting_row][starting_col][0] = true;

		pos root;
		root.row = starting_row, root.col = starting_col, root.cost = 0, root.state = 0;

		queue <pos> q;
		q.push( root );

		int min_dist = INFINITY;
		while( !q.empty() )
		{
			pos cur = q.front();
			q.pop();

			if( cur.row == ending_row && cur.col == ending_col )
			{
				min_dist = cur.cost;
				break;
			}

			for( int i = 0; i < 4; i++ )
			{
				pos temp;
				temp.row = cur.row + row_dir[cur.state][i];
				temp.col = cur.col + col_dir[cur.state][i];
				temp.state = ( cur.state + 1 ) % 3;
				temp.cost = cur.cost + 1;

				if( is_in_range( temp.row, temp.col, graph.size(), graph[0].size() ) && !visited[temp.row][temp.col][temp.state] && no_obstacles( cur.row, cur.col, temp.row, temp.col ) )
				{
					visited[temp.row][temp.col][temp.state] = true;
					q.push( temp );
				}
			}
		}

		if( min_dist == INFINITY ) cout << "NO" << endl;
		else cout << min_dist << endl;
	}

	return 0;
}
