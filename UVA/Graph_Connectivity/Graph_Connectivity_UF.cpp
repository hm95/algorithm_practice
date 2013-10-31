#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int find_set( int A, vector <int>& parent )
{
	if( parent[A] != A )
		parent[A] = find_set( parent[A], parent );
	
	return parent[A];
}

void union_sets( int A, int B, vector <int>& parent, vector <int>& rank )
{
	int sA = find_set( A, parent ), sB = find_set( B, parent );

	if( rank[sA] < rank[sB] ) parent[sA] = sB;
	else parent[sB] = sA;

	if( rank[sA] == rank[sB] ) rank[sA]++;
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

		vector <int> parent;
		vector <int> rank;

		for( int i = 0; i < num_nodes; i++ )
		{
			rank.push_back( 0 );
			parent.push_back( i );
		}

		while( getline( cin, line ) && line != "" )
			union_sets( line[0] - 'A', line[1] - 'A', parent, rank );

		set <int> unique_components;
		int num_connected_components = 0;

		for( int i = 0; i < num_nodes; i++ )
			if( unique_components.find( parent[i] ) == unique_components.end() )
			{
				unique_components.insert( parent[i] );
				num_connected_components++;
			}

		cout << num_connected_components << endl;
		if( graph_no != num_graphs -1 ) cout << endl;
	}

	return 0;
}
