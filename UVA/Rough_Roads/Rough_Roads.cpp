#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int test_case_number = 1, num_nodes, number_edges;
	while( cin >> num_nodes >> number_edges )
	{
		int starting_node = 0, ending_node = num_nodes - 1;

		pair <int, int> temp_pair;
		vector < pair <int, int > > temp_vector_of_pairs( 0, temp_pair );
		vector < vector < pair <int, int> > > adj_list( num_nodes, temp_vector_of_pairs );

		int from, to, cost;
		for( int edge_number = 0; edge_number < number_edges; edge_number++ )
		{
			cin >> from >> to >> cost;
			adj_list[from].push_back( make_pair( to, cost ) );
			adj_list[to].push_back( make_pair( from, cost ) );
		}

		int round = 0;

		vector <int> tmp( 2, INFINITY );
		vector < vector <int> > distances( num_nodes, tmp );
		distances[starting_node][0] = 0;

		priority_queue < pair < pair <int, int>, int >, vector < pair < pair <int, int>, int > >, greater < pair < pair <int, int>, int > > > pq;
		pq.push( make_pair( make_pair( 0, starting_node ), 0 ) );

		while( !pq.empty() )
		{
			int vertex1 = pq.top().first.second, distance1 = pq.top().first.first, length1 = pq.top().second;
			pq.pop();

			if( vertex1 == ending_node ) break;
			if( distance1 <= distances[vertex1][1] )
			{
				vector < pair <int, int> >::iterator it = adj_list[vertex1].begin();
				while( it != adj_list[vertex1].end() )
				{
					int vertex2 = it->first, distance2 = it->second;
					if( vertex2 == ending_node && length1 == 0 ) distance2 = INFINITY;
					if( round == 0 )
					{
						if( distances[vertex2][0] > distances[vertex1][0] + distance2 )
						{
							distances[vertex2][1] = distances[vertex1][0] + distance2;
							pq.push( make_pair( make_pair( distances[vertex2][1], vertex2), length1 + 1 ) );
						}
					}
					else
					{
						if( distances[vertex2][1] > distances[vertex1][1] + distance2 )
						{
							distances[vertex2][1] = distances[vertex1][1] + distance2;
							pq.push( make_pair( make_pair( distances[vertex2][1], vertex2), length1 + 1 ) );
						}
					}
					it++;
				}
			}

			if( round == 0 ) round = 1;
		}

		cout << "Set #" << test_case_number << endl;
		if( distances[ending_node][1] == INFINITY ) cout << "?" << endl;
		else cout << distances[ending_node][1] << endl;

		test_case_number++;
		pq = priority_queue < pair < pair <int, int>, int >, vector < pair < pair <int, int>, int > >, greater < pair < pair <int, int>, int > > > ();
		adj_list.clear();
		distances.clear();
	}

	return 0;
}
