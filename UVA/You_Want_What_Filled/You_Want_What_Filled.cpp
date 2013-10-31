#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool compare( const pair <char, int>& p1, const pair <char, int>& p2 )
{
	if( p1.second != p2.second ) return p1.second > p2.second;
	return p1.first < p2.first;
}

bool is_in_range( int row, int column, int num_rows, int num_columns )
{
	if( row >= 0 && column >= 0 && row < num_rows && column < num_columns ) return true;
	return false;
}

pair <char, int> size_of_hole( int row, int column, vector < vector <char> >& graph ) 
{
	int num_connected = 1;
	char c = graph[row][column];
	graph[row][column] = '.';

	stack < pair <int, int> > stk;
	stk.push( make_pair( row, column ) );

	while( !stk.empty() )
	{
		pair <int, int> cur = stk.top();
		stk.pop();

		for( int i = 0; i < 4; i++ )
		{
			int adjacent_cell_row = cur.first + row_direction[i];
			int adjacent_cell_column = cur.second + column_direction[i];

			if( is_in_range( adjacent_cell_row, adjacent_cell_column, graph.size(), graph[0].size() ) && graph[adjacent_cell_row][adjacent_cell_column] == c )
			{
				graph[adjacent_cell_row][adjacent_cell_column] = '.';
				stk.push( make_pair( adjacent_cell_row, adjacent_cell_column ) );
				num_connected++;
			}
		}
	}

	return make_pair( c, num_connected );
}

int main()
{
	int num_rows, num_columns, test_case_number = 1;
	while( cin >> num_rows >> num_columns )
	{
		if( num_rows == 0 && num_columns == 0 ) break;
		
		vector <char> g_tmp( num_columns, 0 );
		vector < vector <char> > graph( num_rows, g_tmp );

		string line;
		for( int row = 0; row < num_rows; row++ )
		{
			cin >> line;
			for( int column = 0; column < num_columns; column++ )
				graph[row][column] = line[column];
		}

		vector < pair <char, int> > list_of_holes;
		for( int row = 0; row < num_rows; row++ )
			for( int column = 0; column < num_columns; column++ )
				if( graph[row][column] != '.' )
					list_of_holes.push_back( size_of_hole( row, column, graph ) );

		sort( list_of_holes.begin(), list_of_holes.end(), compare );

		cout << "Problem " << test_case_number << ":" << endl;
		vector < pair <char, int> >::iterator it = list_of_holes.begin();
		while( it != list_of_holes.end() )
		{
			cout << it->first << ' ' << it->second << endl;
			it++;
		}

		test_case_number++;
	}

	return 0;
}
