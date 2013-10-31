#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int dijkstras( const int& start, const int& end, const int& number_nodes, vector < vector < pair <int, int> > > graph )
{
    vector <int> distances( number_nodes, INFINITY );

distances[start] = 0;
   

priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

pq.push( make_pair( start, 0 ) );
   
    while( !pq.empty() )
    {
        int c1 = pq.top().first;
        int d1 = pq.top().second;
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
    int start, end, number_nodes, number_connections;
	cin >> start >> end >> number_nodes >> number_connections;

    vector < pair <int, int> > graph_temp;
    vector < vector < pair <int, int> > > graph( number_nodes, graph_temp );

    int from, to, cost;
    for( int node_number = 0; node_number < number_nodes; node_number++ )
    {
        cin >> from >> to >> cost;
        graph[from].push_back( make_pair( to, cost ) );
    }

    int min_dist = dijkstras( start, end, number_nodes, graph );

    /*if( min_dist == INFINITY )

cout << ""Cannot reach node ” << end << “ from node “ << start << endl;
    else

cout << “Can reach node “ << end << “ from node “ << start << “ with a cost of “ << min_dist << endl;*/
	cout << min_dist << endl;

    return 0;
}
