#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_direction[] = { 1, 1, 1, -1, -1, -1, 0, 0, };
int column_direction[] = { 1, -1, 0, 1, -1, 0, -1, 1, };

vector <char> sky_temp;
vector < vector <char> > sky;

bool is_in_sky( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

bool is_a_star( int row, int col )
{
	sky[row][col] = '.';

	stack < pair <int, int> > stk;
	stk.push( make_pair( row, col ) );

	bool is_star = true;

	while( !stk.empty() )
	{
		pair <int, int> spot = stk.top();
		stk.pop();

		for( int i = 0; i < 8; i++ )
		{
			int row_temp = spot.first + row_direction[i];
			int column_temp = spot.second + column_direction[i];

			if( is_in_sky( row_temp, column_temp, sky.size(), sky[0].size() ) && sky[row_temp][column_temp] == '*' )
			{
				sky[row_temp][column_temp] = '.';
				stk.push( make_pair( row_temp, column_temp ) );

				is_star = false;
			}
		}
	}
	
	return is_star;
}

int main()
{
	int num_rows, num_cols;
	while( cin >> num_rows >> num_cols && num_rows != 0 && num_cols != 0 )
	{
		for( int i = 0; i < num_cols; i++ )
			sky_temp.push_back( '.' );

		for( int j = 0; j < num_rows; j++ )
			sky.push_back( sky_temp );

		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
				cin >> sky[row][col];

		int num_stars = 0;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
				if( sky[row][col] == '*' && is_a_star( row, col ) )
					num_stars++;

		cout << num_stars << endl;
		sky.clear();
	}

	return 0;
}
