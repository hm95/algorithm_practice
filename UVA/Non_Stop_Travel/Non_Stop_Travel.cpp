#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int number_of_nodes, test_case_number = 1;
	while( cin >> number_of_nodes )
	{
		string line;
		getline( cin, line );

		if( number_of_nodes == 0 ) break;

		vector < pair <int, int> > tmp;
		vector < vector < pair <int, int> > > adj_list( number_of_nodes + 1, tmp );

		int num_vertices;
		for( int i = 0; i < number_of_nodes; i++ )
		{
			getline( cin, line );
			istringstream iss( line );
			iss >> num_vertices;

			for( int vertex_number = 0; vertex_number < num_vertices; vertex_number++ )
			{
				int to, cost;
				iss >> to >> cost;
				adj_list[i + 1].push_back( make_pair( to, cost ) );
			}
		}

		int starting_node, ending_node;
		getline( cin, line );
		istringstream iss( line );
		iss >> starting_node >> ending_node;
		getline( cin, line );

		vector <int> distances( number_of_nodes + 1, INFINITY ), directions( number_of_nodes + 1, 0 );
		distances[starting_node] = 0;

		priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
		pq.push( make_pair( 0, starting_node ) );

		while( !pq.empty() )
		{
			pair <int, int> cur = pq.top();
			pq.pop();

			int d1 = cur.first, v1 = cur.second;

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
						directions[v2] = v1;
						pq.push( make_pair( distances[v2], v2 ) );
					}
					it++;
				}
			}
		}

		vector <int> steps;
		int index = ending_node;
		while( index != starting_node )
		{
			steps.push_back( index );
			index = directions[index];
		}
		steps.push_back( starting_node );
		reverse( steps.begin(), steps.end() );

		cout << "Case " << test_case_number << ": Path = ";
		vector <int>::iterator it = steps.begin();
		while( it != steps.end() )
		{
			if( it == steps.end() - 1 ) cout << *it;
			else cout << *it << ' ';
			it++;
		}
		cout << "; " << distances[ending_node] << " second delay " << endl;
		test_case_number++;

		pq = priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > >();
		directions.clear();
		distances.clear();
		adj_list.clear();
		tmp.clear();
	}
	
	return 0;
}
