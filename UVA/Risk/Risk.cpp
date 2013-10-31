#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int min_dist( int from, int to, map < int, vector <int> > adj_list )
{
	vector <bool> visited( 20, false );

	visited[from] = true;
	queue < pair <int, int> > q;
	q.push( make_pair( from, 0 ) );

	while( !q.empty() )
	{
		pair <int, int> tmp = q.front();
		q.pop();

		if( tmp.first == to ) return tmp.second;

		vector <int>::iterator it = adj_list[tmp.first].begin();

		while( it != adj_list[tmp.first].end() )
		{
			if( !visited[*it] )
			{
				visited[*it] = true;
				q.push( make_pair( *it, tmp.second + 1 ) );
			}
			it++;
		}
	}
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_no = 1; test_no <= num_test_cases; test_no++ )
	{
		map < int, vector <int> > adj_list;
		for( int from = 1; from <= 19; from++ )
		{
			int num_neighbours;
			cin >> num_neighbours;
			for( int neighbour_num = 0; neighbour_num < num_neighbours; neighbour_num++ )
			{
				int to;
				cin >> to;
				
				adj_list[from].push_back( to );
				adj_list[to].push_back( from );
			}
		}

		int num_pairs;
		cin >> num_pairs;

		cout << "Test Set #" << test_no << endl;
		for( int pair_no = 0; pair_no < num_pairs; pair_no++ )
		{
			int from, to;
			cin >> from >> to;
			cout << from << " to " << to << ": " << min_dist( from, to, adj_list ) << endl;
		}
		cout << endl;
	}

	return 0;
}
