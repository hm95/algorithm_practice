#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col, int nrow, int ncol )
{
	if( row >= 0 && row < nrow && col >= 0 && col < ncol ) return true;
	return false;
}

struct pos
{
	int row, col, cost;
};

bool operator<( const pos& p1, const pos& p2 )
{
	return p1.cost > p2.cost;
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	for( int test_case_no = 0; test_case_no < num_test_cases; test_case_no++ )
	{
		int num_rows, num_cols;
		cin >> num_rows >> num_cols;

		vector <int> tmp;
		for( int col = 0; col < num_cols; col++ )
			tmp.push_back( 0 );

		vector < vector <int> > grid;
		for( int row = 0; row < num_rows; row++ )
			grid.push_back( tmp );

		map < pair <int, int>, int > dist;
		for( int row = 0; row < num_rows; row++ )
			for( int col = 0; col < num_cols; col++ )
			{
				cin >> grid[row][col];
				dist[ make_pair( row, col ) ] = INFINITY;
			}
		
		pos root;
		root.row = root.col = 0;
		root.cost = grid[0][0];

		priority_queue <pos> pq;
		pq.push( root );
		
		while( !pq.empty() )
		{
			pos curr = pq.top();
			pq.pop();

			if( curr.row == num_rows - 1 && curr.col == num_cols - 1 ) break;

			for( int i = 0; i < 4; i++ )
			{
				pos tmp;
				tmp.row = curr.row + row_direction[i];
				tmp.col = curr.col + column_direction[i];

				if( is_in_range( tmp.row, tmp.col, num_rows, num_cols ) && curr.cost + grid[tmp.row][tmp.col] < dist[ make_pair( tmp.row, tmp.col ) ] )
				{
					dist[ make_pair( tmp.row, tmp.col ) ] = tmp.cost = curr.cost + grid[tmp.row][tmp.col];
					pq.push( tmp );
				}
			}
		}

		cout << dist[ make_pair( num_rows - 1, num_cols - 1 ) ] << endl;
	}

	return 0;
}
