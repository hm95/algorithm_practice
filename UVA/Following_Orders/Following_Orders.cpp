#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

void top_sort( char starting_node, vector <char>& TS_list, map <char, bool>& visited, map < char, vector <char> > graph )
{
	visited[starting_node] = true;

	vector <char>::iterator ct = graph[starting_node].begin();
	while( ct != graph[starting_node].begin() )
	{
		if( !visited[*ct] )
			top_sort( *ct, TS_list, visited, graph );
		ct++;
	}

	TS_list.push_back( *ct );
}

int main()
{
	string line1, line2;
	while( getline( cin, line1 ) && line1 != "" )
	{
		getline( cin, line2 );

		istringstream iss( line1 );
		istringstream bss( line2 );

		map < char, vector <char> > graph;
		map <char, bool> visited;
		char node; 
		/*while( iss >> node )
		{
			graph[node].push_back( '0' );
		}*/

		char from, to;
		while( bss >> from >> to )
			graph[from].push_back( to );

		vector <char> TS_list;

		map < char, vector <char> >::iterator it = graph.begin();
		while( it != graph.end() )
		{
			if( !visited[it->first] )
				top_sort( it->first, TS_list, visited, graph );
			it++;
		}

		for( int i = 0; i < TS_list.size(); i++ )
			cout << TS_list[i] << ' ';
		cout << endl;
	}

	return 0;
}
