#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main()
{
	int num_connections, test_case_number = 1;
	while( cin >> num_connections && num_connections != 0 )
	{
		int from, to;
		map < int, vector <int> > connections;
		set <int> unique_nodes, visited;

		for( int connection_number = 0; connection_number < num_connections; connection_number++ )
		{
			cin >> from >> to;
			connections[from].push_back( to );
			connections[to].push_back( from );

			if( unique_nodes.find( from ) == unique_nodes.end() )
				unique_nodes.insert( from );

			if( unique_nodes.find( to ) == unique_nodes.end() )
				unique_nodes.insert( to );
		}

		int start, ttl;
		while( cin >> start >> ttl && start != 0 || ttl != 0 )
		{
			queue < pair <int, int> > q;
			q.push( make_pair( start, 0 ) );
			visited.insert( start );

			while( !q.empty() )
			{
				int cur = q.front().first;
				int cur_time = q.front().second;
				q.pop();

				vector <int>::iterator it = connections[cur].begin();
				while( it != connections[cur].end() )
				{
					if( visited.find( *it ) == visited.end() && cur_time + 1 <= ttl )
					{
						visited.insert( *it );
						q.push( make_pair( *it, 1 + cur_time ) );
					}
					it++;
				}
			}

			cout << "Case " << test_case_number << ": " << unique_nodes.size() - visited.size() << " nodes not reachable from node " << start << " with TTL = " << ttl << "." << endl;

			test_case_number++;
			visited.clear();
		}
	}

	return 0;
}
