#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int num_nodes, num_edges, test_case_number = 1;
	while( cin >> num_nodes >> num_edges )
	{
		if( num_nodes == 0 && num_edges == 0 ) break;
		
		vector <int> g_tmp( num_nodes + 1, 0 );
		vector < vector <int> > graph( num_nodes + 1, g_tmp );

		for( int edge_no = 0; edge_no < num_edges; edge_no++ )
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from][to] = graph[to][from] = cost;
		}

		int starting_vertex, ending_vertex, num_people;
		cin >> starting_vertex >> ending_vertex >> num_people;

		int num_trips;
		if( starting_vertex == ending_vertex ) num_trips = 0;
		else
		{
			for( int k = 1; k <= num_nodes; k++ )
				for( int i = 1; i <= num_nodes; i++ )
					for( int j = 1; j <= num_nodes; j++ )
						graph[i][j] = max( min( graph[i][k], graph[k][j] ), graph[i][j] );

			if( num_people % ( graph[starting_vertex][ending_vertex] - 1 ) == 0 ) num_trips = ( num_people / ( graph[starting_vertex][ending_vertex] - 1 ) );
			else num_trips = ( num_people / ( graph[starting_vertex][ending_vertex] - 1 ) ) + 1;
		}

		cout << "Scenario #" << test_case_number << endl;
		cout << "Minimum Number of Trips = " << num_trips << endl << endl;
		test_case_number++;
	}	

	return 0;
}
