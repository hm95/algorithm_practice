#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
	{
		int num_nodes, num_edges;

		cin >> num_nodes >> num_edges;
		vector <int> g_tmp( num_nodes, INFINITY );
		vector < vector <int> > graph( num_nodes, g_tmp );

		int from, to;
		for( int edge_number = 0; edge_number < num_edges; edge_number++ )
		{
			cin >> from >> to; 
			graph[from][to] = graph[to][from] = 1;
		}

		int starting_node, ending_node;
		cin >> starting_node >> ending_node;

		for( int i = 0; i < num_nodes; i++ )
			for( int j = 0; j < num_nodes; j++ )
				if( i == j )
					graph[i][j] = 0;

		for( int k = 0; k < num_nodes; k++ )
			for( int i = 0; i < num_nodes; i++ )
				for( int j = 0; j < num_nodes; j++ )
					graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );

		int max_dist = -1;
		for( int node = 0; node < num_nodes; node++ )
			max_dist = max( max_dist, graph[starting_node][node] + graph[node][ending_node] );

		cout << "Case " << test_case_number + 1 << ": " << max_dist << endl;
	}

	return 0;
}
