#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector <bool> right_diagonal( 15, true );
vector <bool> left_diagonal( 15, true );
vector <bool> column( 8, true );
vector <int> queen_col_values( 8, 0 );
vector <string> positions( 92 );
int queen_row, queen_col;
int num_solutions;

const int offset = 7;
const bool available = true; 

void put_queen_in_row( int row )
{
	for( int col = 0; col < 8; col++ )
	{
		if( column[col] == available && left_diagonal[row + col] == available && right_diagonal[row - col + offset] == available )
		{
			queen_col_values[col] = row;
			column[col] = !available;
			left_diagonal[row + col] = !available;
			right_diagonal[row - col + offset] = !available;

			if( row == 7 )
			{ 
				stringstream tmp;
				for( int i = 0; i < queen_col_values.size(); i++ )
					tmp << queen_col_values[i];

				positions[num_solutions] = tmp.str();
				num_solutions++;
			}
			else put_queen_in_row( row + 1 );

			column[col] = available;
			left_diagonal[row + col] = available;
			right_diagonal[row - col + offset] = available;
		}
	}
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	num_solutions = 0;
	put_queen_in_row( 0 );
	sort( positions.begin(), positions.end() );

	for( int test_case_number = 1; test_case_number <= num_test_cases; test_case_number++ )
	{
		cout << "SOLN COLUMN" << endl;
		cout << "# 1 2 3 4 5 6 7 8" << endl << endl;

		cin >> queen_row >> queen_col;
		num_solutions = 1;

		for( int i = 0; i < 92; i++ )
		{
			if( positions[i][queen_col - 1] - '0' != queen_row - 1 ) continue;

			cout << num_solutions << " ";
			for( int j = 0; j < 8; j++ )
			{
				cout << positions[i][j] + 1 - '0';
				if( j != 7 ) cout << " ";
			}
			num_solutions++;
			cout << endl;
		}

		if( test_case_number != num_test_cases )
			cout << endl;
	}

	return 0;
}
