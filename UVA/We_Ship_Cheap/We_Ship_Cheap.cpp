#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int num_edges;
	while( cin >> num_edges )
	{
		map < string, vector <string> > adj_list;

		string from, to;
		for( int edge_number = 0; edge_number < num_edges; edge_number++ )
		{
			cin >> from >> to;
			adj_list[from].push_back( to );
			adj_list[to].push_back( from );
		}

		string starting_vertex, ending_vertex;
		cin >> starting_vertex >> ending_vertex;

		map <string, string> directions;

		queue < pair <string, int> > q;
		q.push( make_pair( starting_vertex, 0 ) );

		map <string, bool> visited;
		visited[starting_vertex] = true;

		bool has_route = false;
		while( !q.empty() )
		{
			pair <string, int> cur = q.front();
			q.pop();

			if( cur.first == ending_vertex )
			{
				has_route = true;
				break;
			}

			vector <string>::iterator it = adj_list[cur.first].begin();
			while( it != adj_list[cur.first].end() )
			{
				if( !visited[*it] )
				{
					directions[*it] = cur.first;
					visited[*it] = true;
					q.push( make_pair( *it, cur.second + 1 ) );
				}
				it++;
			}
		}

		if( !has_route ) cout << "No route" << endl << endl;
		else
		{
			vector <string> steps;
			string index = ending_vertex;
			while( index != starting_vertex )
			{
				steps.push_back( index );
				index = directions[index];
			}
			steps.push_back( starting_vertex );

			reverse( steps.begin(), steps.end() );

			vector <string>::iterator it = steps.begin();
			while( it != steps.end() - 1 )
			{
				cout << *it << ' ' << *(it + 1) << endl;
				it++;
			}
			cout << endl;
		}
	}

	return 0;
}
