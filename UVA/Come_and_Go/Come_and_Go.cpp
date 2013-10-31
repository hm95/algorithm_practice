#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void topologically_sort( int start, vector < vector <int> > connection_list, vector <bool>& visited, vector <int>& sorted_connection_list )
{
	visited[start] = true;

	vector <int>::iterator it = connection_list[start].begin();
	while( it != connection_list[start].end() )
	{
		if( !visited[*it] )
			topologically_sort( *it, connection_list, visited, sorted_connection_list );
		it++;
	}

	sorted_connection_list.push_back( start );
}

void check_for_connectedness( int start, vector < vector <int> > connection_list, vector <bool>& visited )
{
	visited[start] = false;

	vector <int>::iterator it = connection_list[start].begin();
	while( it != connection_list[start].end() )
	{
		if( visited[*it] )
			check_for_connectedness( *it, connection_list, visited );
		it++;
	}
}

int main()
{
	int num_cities, num_intersections;
	while( cin >> num_cities >> num_intersections && num_cities != 0 && num_intersections != 0 )
	{
		vector <int> connection_list_tmp;
		vector < vector <int> > connection_list( num_cities, connection_list_tmp ), connection_list_T = connection_list;

		int from, to, bidirectional;
		for( int intersection_number = 0; intersection_number < num_intersections; intersection_number++ )
		{
			cin >> from >> to >> bidirectional;
			from--, to--;

			connection_list[from].push_back( to );
			connection_list_T[to].push_back( from );

			if( bidirectional == 2 )
			{
				connection_list[to].push_back( from );
				connection_list_T[from].push_back( to );
			}
		}

		vector <int> sorted_connection_list;
		vector <bool> visited( num_cities, false );

		for( int i = 0; i < visited.size(); i++ )
			if( !visited[i] )
				topologically_sort( i, connection_list, visited, sorted_connection_list );

		int num_connected_components = 0;
		for( int i = sorted_connection_list.size() - 1; i >= 0; i-- )
			if( visited[sorted_connection_list[i]] )
			{
				check_for_connectedness( sorted_connection_list[i], connection_list_T, visited );
				num_connected_components++;
			}

		if( num_connected_components == 1 ) cout << "1" << endl;
		else cout << "0" << endl;
	}

	return 0;
}
