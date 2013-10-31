#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

struct pos
{
	int row, col, cost;
};

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

int main()
{
	int num_rows, num_cols;
	while( cin >> num_rows >> num_cols && num_rows != 0 && num_cols != 0 )
	{
		vector <bool> v_tmp( num_cols, false );
		vector < vector <bool> > visited( num_rows, v_tmp );

		int num_rows_with_bombs;
		cin >> num_rows_with_bombs;

		for( int row_with_bomb = 0; row_with_bomb < num_rows_with_bombs; row_with_bomb++ )
		{
			int row_number, number_of_bombs_on_row, bomb_column;
			cin >> row_number >> number_of_bombs_on_row;

			for( int bomb_number = 0; bomb_number < number_of_bombs_on_row; bomb_number++ )
			{
				cin >> bomb_column;
				visited[row_number][bomb_column] = true;
			}
		}

		int starting_row, starting_col, ending_row, ending_col, time;
		cin >> starting_row >> starting_col >> ending_row >> ending_col;
		
		pos root;
		root.row = starting_row, root.col = starting_col, root.cost = 0;

		queue <pos> q;
		q.push( root );

		while( !q.empty() )
		{
			pos cur = q.front();
			q.pop();

			if( cur.row == ending_row && cur.col == ending_col )
			{
				time = cur.cost;
				break;
			}

			for( int i = 0; i < 4; i++ )
			{
				pos tmp;
				tmp.row = cur.row + row_direction[i];
				tmp.col = cur.col + column_direction[i];
				tmp.cost = 1 + cur.cost;

				if( is_in_range( tmp.row, tmp.col, num_rows, num_cols ) && !visited[tmp.row][tmp.col] )
				{
					visited[tmp.row][tmp.col] = true;
					q.push( tmp );
				}
			}
		}

		cout << time << endl;
	}

	return 0;
}
