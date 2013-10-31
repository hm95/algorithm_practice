#include <iostream>
#include <vector>
using namespace std;

int row_dir[] = { -1, 0, 0 };
int col_dir[] = { 0, 1, -1 };
string steps[] = { "forth", "right", "left" };
char destination[] = { 'I', 'E', 'H', 'O', 'V', 'A', '#' };

bool is_in_range( int cur_row, int cur_col, int num_rows, int num_cols )
{
	if( cur_row >= 0 && cur_row < num_rows && cur_col >= 0 && cur_col < num_cols ) return true;
	return false;
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	int num_rows, num_cols;
	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		cin >> num_rows >> num_cols;

		vector <char> tmp;
		for( int col = 0; col < num_cols; col++ )
			tmp.push_back( 0 );

		vector < vector <char> > path;
		for( int row = 0; row < num_rows; row++ )
			path.push_back( tmp );

		int cur_row, cur_col;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
			{
				cin >> path[row][col];
				if( path[row][col] == '@' )
				{
					cur_row = row;
					cur_col = col;
				}
			}

		vector <string> commands;
		for( int step_no = 0; step_no < 7; step_no++ )
			for( int step_dir = 0; step_dir < 3; step_dir++ )
				if( is_in_range( cur_row + row_dir[step_dir], cur_col + col_dir[step_dir], num_rows, num_cols ) && path[cur_row + row_dir[step_dir]][cur_col + col_dir[step_dir]] == destination[step_no] )
				{
					cur_row += row_dir[step_dir];
					cur_col += col_dir[step_dir];
					commands.push_back( steps[step_dir] );
					continue;
				}

		vector <string>::iterator ct = commands.begin();
		while( ct != commands.end() )
		{
			cout << *ct << ' ';
			ct++;
		}
		cout << endl;

		path.clear();
		tmp.clear();
		commands.clear();
	}

	return 0;
}
