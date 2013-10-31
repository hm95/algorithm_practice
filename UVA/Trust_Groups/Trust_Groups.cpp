#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

vector <bool> visited;
vector <int> g_tmp;
vector < vector <int> > graph, graph_transpose;
vector <int> list_of_roots;

void topological_sort( int starting_node )
{
	visited[starting_node] = true;

	vector <int>::iterator it = graph[starting_node].begin();
	while( it != graph[starting_node].end() )
	{
		if( !visited[*it] )
			topological_sort( *it );
		it++;
	}

	list_of_roots.push_back( starting_node );
}

void determine_number_connected_components( int starting_node )
{
	visited[starting_node] = false;

	vector <int>::iterator it = graph_transpose[starting_node].begin();
	while( it != graph_transpose[starting_node].end() )
	{
		if( visited[*it] )
			determine_number_connected_components( *it );
		it++;
	}
}

int main()
{
	int num_people, num_connections;
	while( cin >> num_people >> num_connections )
	{
		if( num_people == 0 && num_connections == 0 ) break;

		map <string, int> name_map;
		string first, last;

		visited.resize( num_people );
		graph.resize( num_people ), graph_transpose.resize( num_people );

		for( int person_number = 0; person_number < num_people; person_number++ )
		{
			cin >> first >> last;
			name_map[first + last] = person_number;
		}

		string p1_first, p1_last, p2_first, p2_last;
		for( int connection_number = 0; connection_number < num_connections; connection_number++ )
		{
			cin >> p1_first >> p1_last >> p2_first >> p2_last;
			graph[name_map[p1_first + p1_last]].push_back( name_map[p2_first + p2_last] );
			graph_transpose[name_map[p2_first + p2_last]].push_back( name_map[p1_first + p1_last] );
		}

		for( int starting_vertex = 0; starting_vertex < num_people; starting_vertex++ )
			if( !visited[starting_vertex] )
				topological_sort( starting_vertex );

		int num_connected_components = 0;
		for( int i = list_of_roots.size() - 1; i >= 0; i-- )
		{
			if( visited[list_of_roots[i]] )
			{
				determine_number_connected_components( list_of_roots[i] );
				num_connected_components++;
			}
		}

		cout << num_connected_components << endl;

		graph_transpose.clear();
		graph.clear();
		name_map.clear();
		list_of_roots.clear();
		visited.clear();
	}

	return 0;
}
