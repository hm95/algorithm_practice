#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void display_all_paths( vector < vector <int> > list_of_paths )
{
	sort( list_of_paths.begin(), list_of_paths.end() );

	vector < vector <int> >::iterator vvi = list_of_paths.begin();
	while( vvi != list_of_paths.end() )
	{
		vector <int>::iterator it = vvi->begin();
		while( it != vvi->end() )
		{
			if( it == vvi->end() - 1 ) cout << *it;
			else cout << *it << ' ';
			it++;
		}
		cout << endl;
		vvi++;
	}
}

void find_all_paths( int starting_vertex, int ending_vertex, map < int, vector <int> > city_map, vector <bool> visited, int& num_paths, queue <int> current_path, vector <bool> connected_to_firestation, vector < vector <int> >& list_of_paths )
{
	current_path.push( starting_vertex );
	visited[starting_vertex] = true;

	if( starting_vertex == ending_vertex )
	{
		vector <int> path;
		while( !current_path.empty() )
		{
			path.push_back( current_path.front() );
			current_path.pop();
		}
		list_of_paths.push_back( path );
		num_paths++;
	}

	vector <int>::iterator it = city_map[starting_vertex].begin();
	while( it != city_map[starting_vertex].end() )
	{
		if( !visited[*it] && connected_to_firestation[*it] )
			find_all_paths( *it, ending_vertex, city_map, visited, num_paths, current_path, connected_to_firestation, list_of_paths );
		it++;
	}
	
	visited[starting_vertex] = false;
}

void determine_firestation_connectivity( int starting_vertex, int ending_vertex, map < int, vector <int> > city_map, vector <bool>& connected_to_firestation )
{
	stack <int> stk;
	stk.push( starting_vertex );

	vector <bool> visited( 21, false );
	visited[starting_vertex] = true;

	while( !stk.empty() )
	{
		int current_vertex = stk.top();
		stk.pop();

		if( current_vertex == ending_vertex )
		{
			connected_to_firestation[starting_vertex] = true;
			return;
		}

		vector <int>::iterator it = city_map[current_vertex].begin();
		while( it != city_map[current_vertex].end() )
		{
			if( !visited[*it] )
			{
				visited[*it] = true;
				stk.push( *it );
			}
			it++;
		}
	}
}

int main()
{
	int firetruck_vertex, test_case = 1;
	while( cin >> firetruck_vertex )
	{
		map < int, vector <int> > city_map;

		int from, to, starting_vertex = 1, num_paths = 0;
		while( cin >> from >> to && from != 0 && to != 0 )
		{
			city_map[from].push_back( to );
			city_map[to].push_back( from );
		}

		queue <int> current_path;
		vector <bool> visited( 21, false ), connected_to_firestation = visited;
		vector < vector <int> > list_of_paths;

		for( int starting_vertex = 1; starting_vertex <= 20; starting_vertex++ )
			determine_firestation_connectivity( starting_vertex, firetruck_vertex, city_map, connected_to_firestation );

		find_all_paths( starting_vertex, firetruck_vertex, city_map, visited, num_paths, current_path, connected_to_firestation, list_of_paths );

		cout << "CASE " << test_case << ":" << endl;
		display_all_paths( list_of_paths );
		cout << "There are " << num_paths << " routes from the firestation to streetcorner " << firetruck_vertex << "." << endl;

		test_case++;
	}

	return 0;
}
