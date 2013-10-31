#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int num_nodes, test_number = 1;
	while( cin >> num_nodes )
	{
		if( num_nodes == 0 ) break;

		map < int, vector <int> > adj_list;

		int starting_node;
		cin >> starting_node;

		int from, to;
		while( cin >> from >> to )
		{
			if( from == 0 && to == 0 ) break;

			adj_list[from].push_back( to );
		}

		vector <int> distances( num_nodes + 1, 0 );

		queue < pair <int, int> > q;
		q.push( make_pair( starting_node, 0 ) );

		while( !q.empty() )
		{
			pair <int, int> cur = q.front();
			q.pop();

			vector <int>::iterator it = adj_list[cur.first].begin();
			while( it != adj_list[cur.first].end() )
			{
				if( distances[*it] < cur.second + 1 )
				{
					distances[*it] = cur.second + 1;
					q.push( make_pair( *it, cur.second + 1 ) );
				}
				it++;
			}
		}

		int len_longest_path = -1, longest_path_index;
		for( int i = 1; i <= num_nodes; i++ )
			if( distances[i] > len_longest_path )
			{
				len_longest_path = distances[i];
				longest_path_index = i;
			}

		cout << "Case " << test_number << ": The longest path from " << starting_node << " has length " << len_longest_path << ", finishing at " << longest_path_index << "." << endl << endl;
		test_number++;
	}

	return 0;
}
