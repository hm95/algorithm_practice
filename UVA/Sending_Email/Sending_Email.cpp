#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 9e8;

int get_min_dist( int starting_node, int ending_node, vector < vector < pair <int, int> > > adj_list, int num_nodes )
{
	vector <int> distances( num_nodes, INF );
	distances[starting_node] = 0;

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int > > > pq;
	pq.push( make_pair( 0, starting_node ) );

	while( !pq.empty() )
	{
		pair <int, int> cur = pq.top();
		pq.pop();

		int v1 = cur.second, d1 = cur.first;
		
		if( v1 == ending_node ) break;

		if( d1 <= distances[v1] )
		{
			vector < pair <int, int> >::iterator it = adj_list[v1].begin();
			while( it != adj_list[v1].end() )
			{
				int v2 = it->first, d2 = it->second;
				if( distances[v2] > distances[v1] + d2 )
				{
					distances[v2] = distances[v1] + d2;
					pq.push( make_pair( distances[v2], v2 ) );
				}
				it++;
			}
		}
	}

	return distances[ending_node];
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_no = 1; test_case_no <= num_test_cases; test_case_no++ )
	{
		int num_nodes, num_edges, starting_node, ending_node;
		cin >> num_nodes >> num_edges >> starting_node >> ending_node;

		vector < vector < pair <int, int> > > adj_list;

		pair <int, int> pr = make_pair( 0, 0 );
		vector < pair <int, int> > vp( 0, pr );

		for( int i = 0; i < num_nodes; i++ )
			adj_list.push_back( vp );

		for( int edge_no = 0; edge_no < num_edges; edge_no++ )
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			adj_list[from].push_back( make_pair( to, cost ) );
			adj_list[to].push_back( make_pair( from, cost ) );
		}
	
		cout << "Case #" << test_case_no << ": ";
		int dist = get_min_dist( starting_node, ending_node, adj_list, num_nodes );
		if( dist == INF ) cout << "unreachable" << endl;
		else cout << dist << endl;
	}

	return 0;
}
