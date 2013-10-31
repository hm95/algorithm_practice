#include <iostream>
#include <vector>
using namespace std;

void top_sort( int start, vector < vector <int> > graph, vector <bool>& visited, vector <int>& TS_list )
{
	visited[start] = true;

	vector <int>::iterator it = graph[start].begin();
	while( it != graph[start].end() )
	{
		if( !visited[*it] )
			top_sort( *it, graph, visited, TS_list );
		it++;
	}

	TS_list.push_back( start );
}

void scc( int start, vector < vector <int> > graph, vector <bool>& visited )
{
	visited[start] = false;

	vector <int>::iterator it = graph[start].begin();
	while( it != graph[start].end() )
	{
		if( visited[*it] )
			scc( *it, graph, visited );
		it++;
	}
}

int main()
{
	int num_nodes, num_connections;
	cin >> num_nodes >> num_connections;

	vector <int> g_tmp;
	vector < vector <int> > graph( num_nodes, g_tmp ), graph_T = graph;
	
	int from, to;
	for( int connection_number = 0; connection_number < num_connections; connection_number++ )
	{
		cin >> from >> to;
		graph[from - 1].push_back( to - 1 );
		graph_T[to - 1].push_back( from - 1 );
	}

	vector <int> TS_list;
	vector <bool> visited( num_nodes, false );
	for( int node_num = 0; node_num < num_nodes; node_num++ )
		if( !visited[node_num] )
			top_sort( node_num, graph, visited, TS_list );
	
	int num_scc = 0;
	for( int node_num = TS_list.size() - 1; node_num >= 0; node_num-- )
		if( visited[TS_list[node_num]] )
		{
			scc( TS_list[node_num], graph_T, visited );
			num_scc++;
		}
	
	cout << "There are " << num_scc << " strongly connected components." << endl;

	return 0;
}
