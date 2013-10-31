#include <iostream>
#include <map>
#include <vector>
using namespace std;

void topological_sort( int start, map < int, vector <int> > graph, map <int, bool>& visited, vector <int>& sorted_list )
{
	visited[start] = true;

	vector <int>::iterator it = graph[start].begin();
	while( it != graph[start].end() )
	{
		if( !visited[*it] )
			topological_sort( *it, graph, visited, sorted_list );
		it++;
	}

	sorted_list.push_back( start );
}

int main()
{
	map < int, vector <int> > graph;

	int num_nodes;
	cin >> num_nodes;

	int node, num_dependencies;
	while( cin >> node >> num_dependencies )
	{
		int dependency;
		for( int dep_number = 0; dep_number < num_dependencies; dep_number++ )
		{
			cin >> dependency;
			graph[node].push_back( dependency );
		}
	}

	map <int, bool> visited;
	vector <int> sorted_list;

	map < int, vector <int> >::iterator it = graph.begin();
	while( it != graph.end() )
	{
		if( !visited[it->first] )
			topological_sort( it->first, graph, visited, sorted_list );
		it++;
	}
	
	cout << "The topologically sorted list is: ";
	for( int i = sorted_list.size() - 1; i >= 0; i-- )
		cout << sorted_list[i] << " ";
	cout << endl;

	return 0;
}
