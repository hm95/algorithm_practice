#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		int board_size, num_blocks;
		cin >> board_size >> num_blocks;

		vector <int> tmp;
		for( int i = 0; i < board_size; i++ )
			tmp.push_back( 1 );

		vector < vector <int> > grid;
		for( int i = 0; i < board_size; i++ )
			grid.push_back( tmp );

		for( int block_no = 0; block_no < num_blocks; block_no++ )
		{
			int starting_row, starting_col, ending_row, ending_col;
			cin >> starting_row >> starting_col >> ending_row >> ending_col;

			for( int row = starting_row - 1; row < ending_row; row++ )
				for( int col = starting_col - 1; col < ending_col; col++ )
					grid[row][col] = 0;
		}

		for( int row = 1; row < board_size; row++ )
			for( int col = 0; col < board_size; col++ )
				if( grid[row][col] )
					grid[row][col] += grid[row - 1][col];

		int max_val = -1;
		for( int row = 0; row < board_size; row++ )
			for( int col = 0; col < board_size; col++ )
			{
				int left_boundary, right_boundary;
				left_boundary = right_boundary = col;

				while( grid[row][right_boundary + 1] >= grid[row][col] && right_boundary < board_size - 1) right_boundary++;
				while( grid[row][left_boundary - 1] >= grid[row][col] && left_boundary > 0 ) left_boundary--;

				max_val = max( max_val, grid[row][col] * ( right_boundary - left_boundary + 1 ) );
			}

		cout << max_val << endl;

		grid.clear();
		tmp.clear();
	}

	return 0;
}
