#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int column, int num_rows, int num_columns )
{
	if( row >= 0 && column >= 0 && row < num_rows && column < num_columns ) return true;
	return false;
}

int find_continent_area( int row, int column, vector < vector <char> >& world_map, char land )
{
	int num_nodes = 1;
	world_map[row][column] = 0;

	stack < pair <int, int> > stk;
	stk.push( make_pair( row, column ) );

	while( !stk.empty() )
	{
		pair <int, int> cur = stk.top();
		stk.pop();

		for( int i = 0; i < 4; i++ )
		{
			int adjacent_row = cur.first + row_direction[i];
			int adjacent_column = cur.second + column_direction[i];

			if( adjacent_column == world_map[0].size() ) adjacent_column = 0;
			if( adjacent_column == -1 ) adjacent_column = world_map[0].size() - 1;

			if( is_in_range( adjacent_row, adjacent_column, world_map.size(), world_map[0].size() ) && world_map[adjacent_row][adjacent_column] == land )
			{
				world_map[adjacent_row][adjacent_column] = 0;
				stk.push( make_pair( adjacent_row, adjacent_column ) );
				num_nodes++;
			}
		}
	}

	return num_nodes;
}

int main()
{
	int num_rows, num_columns;
	while( cin >> num_rows >> num_columns )
	{
		vector <char> g_tmp( num_columns, 0 );
		vector < vector <char> > world_map( num_rows, g_tmp );

		for( int row = 0; row < num_rows; row++ )
			for( int column = 0; column < num_columns; column++ )
				cin >> world_map[row][column];

		int starting_row, starting_column;
		cin >> starting_row >> starting_column;

		char land = world_map[starting_row][starting_column];

		for( int row = 0; row < num_rows; row++ )
			for( int column = 0; column < num_columns; column++ )
				if( world_map[row][column] != land )
					world_map[row][column] = 0;

		find_continent_area( starting_row, starting_column, world_map, land );

		int maximum_continent_area = 0;
		for( int row = 0; row < num_rows; row++ )
			for( int column = 0; column < num_columns; column++ )
				if( world_map[row][column] == land )
					maximum_continent_area = max( maximum_continent_area, find_continent_area( row, column, world_map, land ) );

		cout << maximum_continent_area << endl;
	}

	return 0;
}
