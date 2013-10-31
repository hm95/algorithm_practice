#include <iostream>
#include <set>
#include <vector>
using namespace std;

int find_set( int a, vector <int>& parent, vector <int>& rank )
{
	if( parent[a] != a )
		parent[a] = find_set( parent[a], parent, rank );
	
	return parent[a];
}

void union_sets( int a, int b, vector <int>& parent, vector <int>& rank )
{
	int sA = find_set( a, parent, rank ), sB = find_set( b, parent, rank );

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

	vector <int> g_tmp;
	vector < vector <int> > graph( num_nodes, g_tmp );

	vector <int> parent( num_nodes ), rank( num_nodes, 0 );

	for( int i = 0; i < num_nodes; i++ )
		parent[i] = i;

	int from, to;
	for( int connection_number = 0; connection_number < num_connections; connection_number++ )
	{
		cin >> from >> to;
		from--, to--;
		union_sets( from, to, parent, rank );
	}
	
	set <int> unique;
	for( int i = 0; i < parent.size(); i++ )
		if( unique.find( parent[i] ) == unique.end() )
			unique.insert( parent[i] );

	cout << "There are " << unique.size() << " connected components." << endl;

	return 0;
}
