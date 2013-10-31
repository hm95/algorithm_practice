#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int row_direction[3][4] = 
{
	{ 1, 0, -1, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
};

int col_direction[3][4] = 
{
	{ 0, 1, 0, -1 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
};

int direction_change[] = { 0, 1, -1 };

struct pos
{
	int row, col, cost, direction;
};

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row > 0 && col > 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

bool no_obstacles( vector < vector < vector <bool> > > graph, int starting_row, int starting_col, int ending_row, int ending_col, int direction )
{
	cout << starting_row << "," << starting_col << " ASDASD " << ending_row << "," << ending_col << endl;

	int srow = starting_row, scol = starting_col;
	if( starting_row > ending_row ) swap( starting_row, ending_row );
	if( starting_col > ending_col ) swap( starting_col, ending_col );

	if( starting_row == ending_row )
	{
		for( int col = starting_col; col <= ending_col; col++ )
		{
			if( col == scol ) continue;
			if( graph[starting_row][col][direction] || graph[starting_row - 1][col][direction] ) return false;
		}
	}
	else
	{
		for( int row = starting_row; row <= ending_row; row++ )
		{
			if( row == srow ) continue;
			if( graph[row][starting_col][direction] || graph[row][starting_col - 1][direction] ) return false;
		}
	}

	return true;
}

int main()
{
	map <string, int> direction_map;
	direction_map["south"] = 0;
	direction_map["east"] = 1;
	direction_map["north"] = 2;
	direction_map["west"] = 3;
	
	map <int, string> opp;
	opp[0] = "south";
	opp[1] = "east";
	opp[2] = "north";
	opp[3] = "west";

	int num_rows, num_cols;
	while( cin >> num_rows >> num_cols && num_rows != 0 && num_cols != 0 )
	{
		vector <bool> graph_temp2( 4, false );
		vector < vector <bool> > graph_temp( num_cols, graph_temp2 );
		vector < vector < vector <bool> > > graph( num_rows, graph_temp ), visited = graph;

		bool is_allowed;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
			{
				cin >> is_allowed;

				if( is_allowed )
				for( int i = 0; i < 4; i++ )
					graph[row][col][i] = true;
			}

		int starting_row, starting_col, ending_row, ending_col;
		cin >> starting_row >> starting_col >> ending_row >> ending_col;

		string starting_direction;
		cin >> starting_direction;
		int dir = direction_map[starting_direction];

		pos root;
		root.row = starting_row, root.col = starting_col, root.cost = 0, root.direction = dir;

		queue <pos> q;
		q.push( root );

		visited[starting_row][starting_col][dir] = true;

		int min_dist = -1;
		while( !q.empty() )
		{
			pos cur = q.front();
			q.pop();

			cout << "At " << cur.row << "," << cur.col << " facing " << opp[cur.direction] << endl;

			if( cur.row == ending_row && cur.col == ending_col )
			{
				min_dist = cur.cost;
				break;
			}

			for( int i = 0; i < 3; i++ )
			{
				for( int j = 3; j >= 1; j-- )
				{
					pos tmp;
					tmp.row =  cur.row + j * row_direction[i][cur.direction];
					tmp.col = cur.col + j * col_direction[i][cur.direction];
					tmp.direction = ( cur.direction + direction_change[i] + 4 ) % 4;
					tmp.cost = 1 + cur.cost;
					
					cout << "From " << cur.row << "," << cur.col << " facing " << opp[cur.direction] << " can get to " << 
					tmp.row << "," << tmp.col << " facing " << opp[tmp.direction] << endl;
					
					cout << is_in_range( 1, 4, num_rows, num_cols ) << endl;
					if( is_in_range( tmp.row, tmp.col, num_rows, num_cols ) && !graph[tmp.row + 1][tmp.col][tmp.direction] && !graph[tmp.row][tmp.col + 1][tmp.direction] && !graph[tmp.row][tmp.col][tmp.direction] && !graph[tmp.row - 1][tmp.col][tmp.direction] && !graph[tmp.row][tmp.col - 1][tmp.direction] && no_obstacles( graph, cur.row, cur.col, tmp.row, tmp.col, tmp.direction ) && !visited[tmp.row][tmp.col][tmp.direction] )
					{
						cout << "Pushing " << tmp.row << "," << tmp.col << " facing " << opp[tmp.direction] << " and the time is " << tmp.cost << endl;
						visited[tmp.row][tmp.col][tmp.direction] = true;
						q.push( tmp );
					}
				}
			//	cout << endl;
			}
		}

		cout << min_dist << endl;
	}

	return 0;
}
