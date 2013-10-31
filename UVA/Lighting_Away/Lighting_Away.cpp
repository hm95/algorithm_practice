#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

void dfs( int node_no, map < int, vector <int> >& graph, vector <int>& TS_list, vector <bool>& visited )
{
	if( visited[node_no] ) return;

	visited[node_no] = true;

	vector <int>::iterator it = graph[node_no].begin();
	while( it != graph[node_no].end() )
	{
		dfs( *it, graph, TS_list, visited );
		it++;
	}

	TS_list.push_back( node_no );
}

int main()
{
	int num_test_cases, num_nodes, num_edges;
	cin >> num_test_cases;
	for( int test_case_number = 1; test_case_number <= num_test_cases; test_case_number++ )
	{
		cin >> num_nodes >> num_edges;

		map < int, vector <int> > graph;
		int from, to;
		for( int edge_no = 0; edge_no < num_edges; edge_no++ )
		{
			cin >> from >> to;
			graph[from].push_back( to );
		}

		vector <bool> visited( num_nodes + 1, false );
		vector <int> TS_list;

		for( int node_no = 1; node_no <= num_nodes; node_no++ )
			dfs( node_no, graph, TS_list, visited );

		reverse( TS_list.begin(), TS_list.end() );
		visited.assign( num_nodes + 1, false );

		int num_components = 0;
		for( int i = 0; i < TS_list.size(); i++ )
			if( !visited[TS_list[i]] )
			{
				dfs( TS_list[i], graph, TS_list, visited );
				num_components++;
			}
		
		cout << "Case " << test_case_number << ": " << num_components << endl;
	}

	return 0;
}
