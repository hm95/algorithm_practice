#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find_set( int A, vector <int>& parent )
{
	if( parent[A] != A )
		parent[A] = find_set( parent[A], parent );

	return parent[A];
}

void make_set( int A, int B, vector <int>& parent, vector <int>& rank )
{
	int sA = find_set( A, parent ), sB = find_set( B, parent );

	if( rank[sA] < rank[sB] )
		parent[sA] = sB;
	else
		parent[sB] = sA;
	
	if( rank[sA] == rank[sB] )
		rank[sA]++;
}

int main()
{
	int num_nodes, num_connections; 
	cin >> num_nodes >> num_connections;

	vector <int> rank( num_nodes, 0 ), parent( num_nodes );
	for( int node_number = 0; node_number < num_nodes; node_number++ )
		parent[node_number] = node_number;

	int from, to;
	for( int connection_number = 0; connection_number < num_connections; connection_number++ )
	{
		cin >> from >> to;
		make_set( from, to, parent, rank );
	}
	
	set <int> unique_connected_components;
	for( int node_number = 0; node_number < num_nodes; node_number++ )
		if( unique_connected_components.find( parent[node_number] ) == unique_connected_components.end() )
			unique_connected_components.insert( parent[node_number] );

	cout << "There are " << unique_connected_components.size() << " connected components." << endl;

	return 0;
}
