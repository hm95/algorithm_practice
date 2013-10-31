#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && row < num_rows && col >= 0 && col < num_cols ) return true;
	return false;
}

struct pos
{
	int row, col, time;
};

const int INFINITY = 9e8;

vector <char> graph_temp;
vector < vector <char> > graph;

vector <int> time_temp;
vector < vector <int> > times;

void find_fire_times( int starting_row, int starting_column )
{
	pos root;
	root.row = starting_row, root.col = starting_column, root.time = 0;

	vector < vector <char> > graph_t = graph;
	graph_t[root.row][root.col] = '#';

	queue <pos> q;
	q.push( root );

	while( !q.empty() )
	{
		pos cur = q.front();
		q.pop();

		times[cur.row][cur.col] = min( times[cur.row][cur.col], cur.time );

		for( int i = 0; i < 4; i++ )
		{
			pos tmp;
			tmp.row = cur.row + row_direction[i];
			tmp.col = cur.col + column_direction[i];
			tmp.time = 1 + cur.time;

			if( is_in_range( tmp.row, tmp.col, graph_t.size(), graph_t[0].size() ) && graph_t[tmp.row][tmp.col] != '#' )
			{
				graph_t[tmp.row][tmp.col] = '#';
				q.push( tmp );
			}
		}
	}
}

int find_escape_time( int starting_row, int starting_column )
{
	pos root;
	root.row = starting_row, root.col = starting_column, root.time = 0;
	graph[root.row][root.col] = '#';

	queue <pos> q;
	q.push( root );

	while( !q.empty() )
	{
		pos cur = q.front();
		q.pop();

		if( cur.row == graph.size() - 1 || cur.col == graph[0].size() - 1 || cur.row == 0 || cur.col == 0 ) return 1 + cur.time;

		for( int i = 0; i < 4; i++ )
		{
			pos tmp;
			tmp.row = cur.row + row_direction[i];
			tmp.col = cur.col + column_direction[i];
			tmp.time = 1 + cur.time;

			if( is_in_range( tmp.row, tmp.col, graph.size(), graph[0].size() ) && graph[tmp.row][tmp.col] != '#' && tmp.time < times[tmp.row][tmp.col] )
			{
				graph[tmp.row][tmp.col] = '#';
				q.push( tmp );
			}
		}
	}

	return INFINITY;
}

int main()
{
	int num_test_cases;
	while( cin >> num_test_cases )
	{

		for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
		{
			int num_rows, num_cols;
			cin >> num_rows >> num_cols;

			for( int col = 0; col < num_cols; col++ )
			{
				graph_temp.push_back( '.' );
				time_temp.push_back( INFINITY );
			}

			for( int row = 0; row < num_rows; row++ )
			{
				graph.push_back( graph_temp );
				times.push_back( time_temp );
			}

			int joe_starting_row, joe_starting_column;
			vector < pair <int, int> > list_fires;

			for( int row = 0; row < num_rows; row++ )
			{
				string line;
				cin >> line;

				for( int col = 0; col < num_cols; col++ )
				{
					graph[row][col] = line[col];

					if( graph[row][col] == 'J' )
						joe_starting_row = row, joe_starting_column = col;
					if( graph[row][col] == 'F' )
						list_fires.push_back( make_pair( row, col ) );
				}
			}

			for( int i = 0; i < list_fires.size(); i++ )
				find_fire_times( list_fires[i].first, list_fires[i].second );

			int min_time = find_escape_time( joe_starting_row, joe_starting_column );
			if( min_time == INFINITY ) cout << "IMPOSSIBLE" << endl;
			else cout << min_time << endl;

			graph.clear(), graph_temp.clear(), time_temp.clear(), times.clear();
		}
	}

	return 0;
}
