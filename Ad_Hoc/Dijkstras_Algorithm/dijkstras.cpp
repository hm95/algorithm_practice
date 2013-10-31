#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int dijkstras( const int& start, const int& end, map < int, vector < pair <int, int> > > graph, vector <int> distances )
{
	distances[start] = 0;

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
	pq.push( make_pair( start, distances[start] ) );

	while( !pq.empty() )
	{
		int c1 = pq.top().first, d1 = pq.top().second;
		pq.pop();

		if( c1 == end ) break;

		vector < pair <int, int> >::iterator it = graph[c1].begin();
		while( it != graph[c1].end() )
		{
			int c2 = it->first, d2 = it->second;
			if( d1 + d2 < distances[c2] )
			{
				distances[c2] = d1 + d2;
				pq.push( make_pair( c2, distances[c2] ) );
			}
			it++;
		}
	}

	return distances[end];
}

int main() 
{
	int num_nodes, num_pairs;
	cin >> num_nodes >> num_pairs;

	vector <int> distances( num_nodes, INFINITY );
	map < int, vector < pair <int, int> > > graph;

	int from, to, cost;
	for( int i = 0; i < num_pairs; i++ )
	{
		cin >> from >> to >> cost;
		graph[from].push_back( make_pair( to, cost ) );
	}

	int start, end;
	cin >> start >> end;
	cout << "The minimum distance from node " << start << " to node " << end << " is " << dijkstras( start, end, graph, distances ) << endl;

	return 0;
}
