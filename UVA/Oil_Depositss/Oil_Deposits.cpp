#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_direction[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int column_direction[] = { 0, 1, -1, 1, -1, 0, 1, -1 };

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

void connect_adjacent_oil_fields( int row, int col, vector < vector <char> >& graph )
{
	stack < pair <int, int> > stk;
	stk.push( make_pair( row, col ) );

	while( !stk.empty() )
	{
		pair <int, int> cur = stk.top();
		stk.pop();

		for( int i = 0; i < 8; i++ )
		{
			int temp_row = cur.first + row_direction[i];
			int temp_col = cur.second + column_direction[i];

			if( is_in_range( temp_row, temp_col, graph.size(), graph[0].size() ) && graph[temp_row][temp_col] == '@' )
			{
				graph[temp_row][temp_col] = '*';
				stk.push( make_pair( temp_row, temp_col ) );
			}
		}
	}
}

int main()
{
	int num_rows, num_cols;
	while( cin >> num_rows >> num_cols )
	{
		if( num_rows == 0 && num_cols == 0 ) break;

		vector <char> g_tmp( num_cols );
		vector < vector <char> > graph( num_rows, g_tmp );

		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
				cin >> graph[row][col];

		int num_oil_deposits = 0;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
				if( graph[row][col] == '@' )
				{
					graph[row][col] = '*';
					num_oil_deposits++;
					connect_adjacent_oil_fields( row, col, graph );
				}

		cout << num_oil_deposits << endl;
	}

	return 0;
}
