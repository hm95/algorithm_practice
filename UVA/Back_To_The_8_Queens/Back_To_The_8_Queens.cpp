#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector <bool> left_diag( 15, true );
vector <bool> right_diag( 15, true );
vector <bool> column( 8, true );
vector <int> queen_values_in_column( 8, 0 );
map < int, vector <int> > list_of_answers;

const int offset = 7;
const bool available = true;
int num_solutions;

void put_queen_in_row( int row )
{
	for( int col = 0; col < 8; col++ )
		if( column[col] == available && left_diag[row + col] == available && right_diag[row - col + offset] == available )
		{
			column[col] = !available;
			left_diag[row + col] = !available;
			right_diag[row - col + offset] = !available;
			queen_values_in_column[col] = row;

			if( row == 7 )
			{
				for( int i = 0; i < 8; i++ )
					list_of_answers[num_solutions].push_back( queen_values_in_column[i] );
				num_solutions++;
			}
			else put_queen_in_row( row + 1 );

			column[col] = available;
			left_diag[row + col] = available;
			right_diag[row - col + offset] = available;
		}
}

int main()
{
	string row_values;
	int case_number = 1;
	while( getline( cin, row_values ) )
	{
		vector <int> rows;
		for( int i = 0; i < 8; i++ )
			rows.push_back( row_values[2 * i] - '0' - 1 );

		num_solutions = 0;
		int min_diff = 8;
		put_queen_in_row( 0 );

		for( int i = 0; i < num_solutions; i++ )
		{
			int diff = 0;

			for( int j = 0; j < list_of_answers[i].size(); j++ )
				if( list_of_answers[i][j] != rows[j] )
					diff++;

			min_diff = min( min_diff, diff );
		}

		cout << "Case " << case_number << ": " << min_diff << endl;

		list_of_answers.clear();
		left_diag.clear();
		right_diag.clear();
		column.clear();
		case_number++;
	}

	return 0;
}
