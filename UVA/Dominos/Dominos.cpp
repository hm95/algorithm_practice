#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <bool> visited;
vector <int> g_tmp;
vector < vector <int> > graph;
vector <int> list_of_root_nodes;

void topologically_sort( int starting_vertex )
{
	visited[starting_vertex] = true;

	vector <int>::iterator it = graph[starting_vertex].begin();
	while( it != graph[starting_vertex].end() )
	{
		if( !visited[*it] )
			topologically_sort( *it );
		it++;
	
	}

	list_of_root_nodes.push_back( starting_vertex );
}

void count_connected_components( int starting_vertex )
{
	visited[starting_vertex] = false;

	vector <int>::iterator it = graph[starting_vertex].begin();
	while( it != graph[starting_vertex].end() )
	{
		if( visited[*it] )
			count_connected_components( *it );
		it++;
	}
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	
	for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
	{
		int num_nodes, num_edges;
		cin >> num_nodes >> num_edges;

		visited.resize( num_nodes + 1 );
		graph.resize( num_nodes + 1 );

		for( int edge_number = 0; edge_number < num_edges; edge_number++ )
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back( to );
		}

		for( int node_num = 1; node_num <= num_nodes; node_num++ )
			if( !visited[node_num] )
				topologically_sort( node_num );

		int num_connected_components = 0;
		for( int i = list_of_root_nodes.size() - 1; i >= 0; i-- )
			if( visited[list_of_root_nodes[i]] )
			{
				num_connected_components++;
				count_connected_components( list_of_root_nodes[i] );
			}
			
		cout << num_connected_components << endl;

		graph.clear();
		visited.clear();
		g_tmp.clear();
	}

	return 0;
}
