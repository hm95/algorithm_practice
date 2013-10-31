#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col, int size )
{
	if( row >= 0 && col >=0 && row < size && col < size ) return true;
	return false;
}

int get_min_steps( int row, int col, vector < vector <int> > field )
{
	vector <bool> v_tmp( field.size(), false );
	vector < vector <bool> > visited( field.size(), v_tmp );
	visited[row][col] = true;

	queue < pair < pair <int, int>, int > > q;
	q.push( make_pair( make_pair( row, col ), 0 ) );

	while( !q.empty() )
	{
		pair < pair <int, int>, int > cur = q.front();
		q.pop();

		if( field[cur.first.first][cur.first.second] == 3 ) return cur.second;

		for( int i = 0; i < 4; i++ )
		{
			int temprow = cur.first.first + row_direction[i];
			int tempcol = cur.first.second + column_direction[i];

			if( is_in_range( temprow, tempcol, field.size() ) && !visited[temprow][tempcol] )
			{
				visited[temprow][tempcol] = true;
				q.push( make_pair( make_pair( temprow, tempcol ), cur.second + 1 ) );
			}
		}
	}
}

int main()
{
	int field_size;
	while( cin >> field_size )
	{
		vector <int> f_tmp( field_size, 0 );
		vector < vector <int> > field( field_size, f_tmp );

		for( int row = 0; row < field_size; row++ )
		{
			string line;
			cin >> line;

			for( int col = 0; col < field_size; col++ )
				field[row][col] = line[col] - '0';

		}

		int minimax = -1;
		for( int row = 0; row < field_size; row++ )
			for( int col = 0; col < field_size; col++ )
				if( field[row][col] == 1 )
					minimax = max( minimax, get_min_steps( row, col, field ) );
		
		cout << minimax << endl;
	}

	return 0;
}
