#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool in_range( const int& row, const int& col, const int& num_rows, const int& num_cols )
{
	if( row >= 0 && row < num_rows && col >= 0 && col < num_cols ) return true;
	return false;
}

int main()
{
	map <char, int> next_step_row;
	next_step_row['S'] = 1;
	next_step_row['N'] = -1;
	next_step_row['E'] = 0;
	next_step_row['W'] = 0;

	map <char, int> next_step_col;
	next_step_col['S'] = 0;
	next_step_col['N'] = 0;
	next_step_col['E'] = 1;
	next_step_col['W'] = -1;

	int num_rows, num_cols, starting_col;
	while( cin >> num_rows >> num_cols >> starting_col )
	{
		if( num_cols == 0 && num_rows == 0 ) break;

		vector <char> tmp;
		for( int i = 0; i < num_cols; i++ )
			tmp.push_back( 0 );

		vector < vector <char > > path;
		for( int i = 0; i < num_rows; i++ )
			path.push_back( tmp );

		for( int i = 0; i < num_rows; i++ )
		{
			for( int j = 0; j < num_cols; j++ )
			{
				char c;
				cin >> c;
				path[i][j] = c;
			}
		}

		int num_total_steps = 1;
		int num_steps_before_loop = 0;
		int num_steps_in_loop = 0;

		int cur_x = 0;
		int cur_y = starting_col - 1;

		map < pair <int, int>, int > steps;
		bool done = false;
		bool has_loop = false;

		while( !done )
		{
			steps[ make_pair( cur_x, cur_y ) ] = num_total_steps;

			int temp_x_val = cur_x, temp_y_val = cur_y;
			temp_x_val += next_step_row[path[cur_x][cur_y]];
			temp_y_val += next_step_col[path[cur_x][cur_y]];
			cur_x = temp_x_val, cur_y = temp_y_val;

			if( !in_range( cur_x, cur_y, num_rows, num_cols ) ) done = true;
			else
			{
				num_total_steps++;
				if( steps[ make_pair( cur_x, cur_y ) ] != 0 )
				{
					num_steps_in_loop = num_total_steps - steps[ make_pair( cur_x, cur_y ) ];
					num_steps_before_loop = num_total_steps - num_steps_in_loop - 1;

					has_loop = true;
					done = true;
				}
			}
		}

		if( !has_loop ) cout << num_total_steps << " step(s) to exit" << endl;
		else cout << num_steps_before_loop << " step(s) before a loop of " << num_steps_in_loop << " step(s)" << endl;

		path.clear();
	}

	return 0;
}
