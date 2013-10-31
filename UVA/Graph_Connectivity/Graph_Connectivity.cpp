#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

void dfs( char name, map < char, vector <char> >& graph, vector <bool>& visited )
{
	stack <char> stk;
	stk.push( name );

	while( !stk.empty() )
	{
		char top = stk.top();
		stk.pop();

		vector <char>::iterator it = graph[top].begin();
		while( it != graph[top].end() )
		{
			if( !visited[*it - 'A'] )
			{
				visited[*it - 'A'] = true;
				stk.push( *it );
			}
			it++;
		}
	}
}

int main()
{
	int num_graphs;
	cin >> num_graphs;

	string line;
	getline( cin, line );
	getline( cin, line );

	for( int graph_no = 0; graph_no < num_graphs; graph_no++ )
	{
		getline( cin, line );
		int num_nodes = line[0] - 'A' + 1;
		map < char, vector <char> > graph;

		while( getline( cin, line ) && line != "" )
		{
			graph[line[0]].push_back(line[1]);
			graph[line[1]].push_back(line[0]);
		}

		vector <bool> visited( num_nodes, false );
		int num_connected_components = 0;

		for( int node_no = 0; node_no < num_nodes; node_no++ )
			if( !visited[node_no] )
			{
				visited[node_no] = true;
				num_connected_components++;
				dfs( node_no + 'A', graph, visited );
			}

		cout << num_connected_components << endl;
		if( graph_no != num_graphs - 1 ) cout << endl;
	}

	return 0;
}
