#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int row_direction[] = { 1, -1, 0, 0, 0, 0 };
int column_direction[] = { 0, 0, 1, -1, 0, 0 };
int layer_direction[] = { 0, 0, 0, 0, 1, -1 };

struct pos
{
	int cost, row, col, layer;
};

bool is_ok( int row, int col, int layer, int num_rows, int num_cols, int num_layers )
{
	if( row >= 0 && col >= 0 && layer >= 0 && row < num_rows && col < num_cols && layer < num_layers ) return true;
	return false;
}

int main()
{
	int num_layers, num_rows, num_cols;
	while( cin >> num_layers >> num_rows >> num_cols )
	{
		if( num_layers == 0 && num_rows == 0 && num_cols == 0 ) break;

		vector <char> g_tmp_layers( num_layers );
		vector < vector <char> > g_tmp_cols( num_cols, g_tmp_layers );
		vector < vector < vector <char> > > graph( num_rows, g_tmp_cols );

		vector <bool> v_tmp_layers( num_layers );
		vector < vector <bool> > v_tmp_cols( num_cols, v_tmp_layers );
		vector < vector < vector <bool> > > visited( num_rows, v_tmp_cols );

		char val;
		int starting_row, starting_col, starting_layer, ending_row, ending_col, ending_layer;

		for( int layer = 0; layer < num_layers; layer++ )
			for( int row = 0; row < num_rows; row++ )
				for( int col = 0; col < num_cols; col++ )
				{
					cin >> val;
					graph[row][col][layer] = val;

					if( val == 'S' ) starting_row = row, starting_col = col, starting_layer = layer;
					else if( val == 'E' ) ending_row = row, ending_col = col, ending_layer = layer;
				}

		pos root;
		root.cost = 0, root.row = starting_row, root.col = starting_col, root.layer = starting_layer; 

		queue <pos> q;
		q.push( root );

		int min_dist = INFINITY;
		visited[starting_row][starting_col][starting_layer] = true;

		while( !q.empty() )
		{
			pos cur = q.front();
			q.pop();

			if( cur.row == ending_row && cur.col == ending_col && cur.layer == ending_layer )
			{
				min_dist = cur.cost;
				break;
			}

			for( int i = 0; i < 6; i++ )
			{
				pos tmp;
				tmp.row = cur.row + row_direction[i];
				tmp.col = cur.col + column_direction[i];
				tmp.layer = cur.layer + layer_direction[i];
				tmp.cost = 1 + cur.cost;

				if( is_ok( tmp.row, tmp.col, tmp.layer, num_rows, num_cols, num_layers ) && !visited[tmp.row][tmp.col][tmp.layer] && graph[tmp.row][tmp.col][tmp.layer] != '#' )
				{
					visited[tmp.row][tmp.col][tmp.layer] = true;
					q.push( tmp );
				}
			}
		}

		if( min_dist == INFINITY ) cout << "Trapped!" << endl;
		else cout << "Escaped in " << min_dist << " minute(s)." << endl;
	}

	return 0;
}
