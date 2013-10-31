#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_rows, num_cols;
	while( cin >> num_rows >> num_cols )
	{
		if( num_rows == 0 && num_cols == 0 ) break;

		vector <int> tmp;
		for( int i = 0; i < num_cols; i++ )
			tmp.push_back( 0 );

		vector < vector <int> > grid;
		for( int i = 0; i < num_rows; i++ )
			grid.push_back( tmp );

		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
			{
				int val;
				cin >> val;
				grid[row][col] = !val;
			}

		for( int row = 1; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
				if( grid[row][col] )
					grid[row][col] += grid[row - 1][col];

		int max_val = -1;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
			{
				int left_boundary, right_boundary;
				left_boundary = right_boundary = col;

				while( right_boundary < num_cols - 1 && grid[row][right_boundary + 1] >= grid[row][col] ) right_boundary++;
				while( left_boundary > 0 && grid[row][left_boundary - 1] >= grid[row][col] ) left_boundary--;

				max_val = max( max_val, grid[row][col] * ( right_boundary - left_boundary + 1 ) );
			}

		cout << max_val << endl;

		grid.clear();
		tmp.clear();
	}

	return 0;
}
