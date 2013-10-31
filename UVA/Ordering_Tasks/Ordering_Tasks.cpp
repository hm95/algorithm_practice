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
	int num_nodes, num_edges;
	while( cin >> num_nodes >> num_edges )
	{
		if( num_nodes == 0 && num_edges == 0 ) break;

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
		for( int i = 0; i < TS_list.size(); i++ )
			cout << TS_list[i] << ' ';
		cout << endl;
	}

	return 0;
}
