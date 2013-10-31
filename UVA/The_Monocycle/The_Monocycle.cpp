#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

struct pos
{
	int row, column, cost, state, rotation;
};

bool is_in_range( int row, int column, int num_rows, int num_columns )
{
	if( row >= 0 && column >= 0 && row < num_rows && column < num_columns ) return true;
	return false;
}

int row_direction[4][3] = 
{
	{ -1, 0, 0 },
	{ 0, 0, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 0 }
};

int column_direction[4][3] = 
{
	{ 0, 0, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 0 },
	{ -1, 0, 0 }
};

int state_direction[] = { 0, 1, -1 };

int rotation_direction[] = { 1, 0, 0 };

int main()
{
	int num_rows, num_columns, test_case_number = 1;
	while( cin >> num_rows >> num_columns )
	{
		if( num_rows == 0 && num_columns == 0 ) break;

		if( test_case_number != 1 ) cout << endl;

		vector <char> g_tmp( num_columns, 0 );
		vector < vector <char> > graph( num_rows, g_tmp );

		int starting_row, starting_column, ending_row, ending_column;
		for( int row = 0; row < num_rows; row++ )
			for( int column = 0; column < num_columns; column++ )
			{
				cin >> graph[row][column];

				if( graph[row][column] == 'S' )
					starting_row = row, starting_column = column;
				else if( graph[row][column] == 'T' )
					ending_row = row, ending_column = column;
			}

		vector <bool> v_tmp( 5, false );
		vector < vector <bool> > v_tmp2( 4, v_tmp );
		vector < vector < vector <bool> > > v_tmp3( num_columns, v_tmp2 );
		vector < vector < vector < vector <bool> > > > visited( num_rows, v_tmp3 );

		pos root;
		root.row = starting_row, root.column = starting_column, root.cost = 0, root.state = 0, root.rotation = 0;

		queue <pos> q;
		q.push( root );
		visited[root.row][root.column][root.state][root.rotation] = true;

		int min_dist = INFINITY; 
		while( !q.empty() )
		{
			pos current = q.front();
			q.pop();

			if( current.row == ending_row && current.column == ending_column && current.rotation == 0 )
			{
				min_dist = current.cost;
				break;
			}

			for( int i = 0; i < 3; i++ )
			{
				pos tmp;
				tmp.row = current.row + row_direction[current.state][i];
				tmp.column = current.column + column_direction[current.state][i];
				tmp.state = ( ( current.state + state_direction[i] ) % 4 );
				tmp.cost = current.cost + 1;
				tmp.rotation = ( ( current.rotation + rotation_direction[i] ) % 5 );
				if( tmp.state == -1 ) tmp.state = 3;

				if( is_in_range( tmp.row, tmp.column, num_rows, num_columns ) && !visited[tmp.row][tmp.column][tmp.state][tmp.rotation] && graph[tmp.row][tmp.column] != '#' )
				{
					visited[tmp.row][tmp.column][tmp.state][tmp.rotation] = true;
					q.push( tmp );
				}
			}
		}

		cout << "Case #" << test_case_number << endl;
		if( min_dist == INFINITY ) cout << "destination not reachable" << endl;
		else cout << "minimum time = " << min_dist << " sec" << endl;

		test_case_number++;
	}

	return 0;
}
