#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int bfs( int starting_node, vector < vector <int> > adj_list, int num_nodes, vector <int> important_cities, vector <int> occurances )
{
	vector <int> costs( num_nodes + 1 , INFINITY );
	costs[starting_node] = 0;

	queue <int> q;
	q.push( starting_node );

	while( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		vector <int>::iterator it = adj_list[cur].begin();
		while( it != adj_list[cur].end() )
		{
			if( costs[*it] == INFINITY )
			{
				costs[*it] = costs[cur] + 1;
				q.push( *it );
			}
			it++;
		}
	}

	int ret = 0;
	for( int i = 1; i <= num_nodes; i++ )
		if( occurances[i] >= 2 )
			ret += costs[i];
	
	return ret;
}

int main()
{
	int num_tests_cases;
	cin >> num_tests_cases;

	for( int test_case_number = 0; test_case_number < num_tests_cases; test_case_number++ )
	{
		int num_nodes, num_lines;
		cin >> num_nodes >> num_lines;

		vector <int> a_tmp, important_cities, occurances( num_nodes + 1, 0 );
		vector < vector <int> > adj_list( num_nodes + 1, a_tmp );

		for( int line_number = 0; line_number < num_lines; line_number++ )
		{
			int cur_node, prev_node;
			cin >> prev_node;
			occurances[prev_node]++;

			while( cin >> cur_node && cur_node != 0 )
			{
				adj_list[prev_node].push_back( cur_node );
				adj_list[cur_node].push_back( prev_node );
				occurances[cur_node]++;
				prev_node = cur_node;
			}
		}

		for( int i = 0; i < occurances.size(); i++ )
			if( occurances[i] >= 2 )
				important_cities.push_back( i );

		int min_value = INFINITY, minimum_distances, best_node;
		for( int starting_node = 0; starting_node < important_cities.size(); starting_node++ )
		{
			minimum_distances = bfs( important_cities[starting_node], adj_list, num_nodes, important_cities, occurances );
			if( minimum_distances < min_value )
			{
				min_value = minimum_distances;
				best_node = important_cities[starting_node];
			}
		}

		cout << "Krochanska is in: " << best_node << endl;
	}
	
	return 0;
}
