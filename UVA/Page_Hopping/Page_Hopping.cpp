#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int from, to, test_case_number = 1;
	while( cin >> from >> to )
	{
		if( from == 0 && to == 0 ) break;

		int max_node = max( from, to );

		vector <int> g_tmp( 101, INFINITY );
		vector < vector <int> > graph( 101, g_tmp );
		vector <bool> found( 101, false );

		int num_nodes = 0;
		if( !found[from] )
		{
			found[from] = true;
			num_nodes++;
		}
		if( !found[to] )
		{
			found[to] = true;
			num_nodes++;
		}

		graph[from][to] = 1;

		while( cin >> from >> to )
		{
			if( from == 0 && to == 0 ) break;
			max_node = max( max_node, max( from, to ) );

			if( !found[from] )
			{
				found[from] = true;
				num_nodes++;
			}
			if( !found[to] )
			{
				found[to] = true;
				num_nodes++;
			}

			graph[from][to] = 1;
		}

		for( int k = 1; k <= max_node; k++ )
			for( int i = 1; i <= max_node; i++ )
				for( int j = 1; j <= max_node; j++ )
					graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );

		double average_path_length = 0.0;
		for( int row = 1; row <= max_node; row++ )
			for( int col = 1; col <= max_node; col++ )
				if( row != col && found[row] && found[col] )
					average_path_length += graph[row][col];

		average_path_length /= ( num_nodes * (num_nodes - 1) );
		cout << fixed << setprecision( 3 ) << "Case " << test_case_number << ": average length between pages = " << average_path_length << " clicks" << endl;

		test_case_number++;
	}
}
