#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INF = 9e8;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		int num_fire_stations, num_intersections;
		cin >> num_fire_stations >> num_intersections;

		vector <int> fire_stations;
		int fire_station_location;

		for( int i = 0; i < num_fire_stations; i++ )
		{
			cin >> fire_station_location;
			fire_stations.push_back( fire_station_location );
		}
		
		map < int, vector < pair <int, int> > > adj_list;

		for( int i = 0; i < num_intersections; i++ )
		{
			int from, to, cost;
			cin >> from >> to >> cost;

			adj_list[from].push_back( make_pair( to, cost ) );
			adj_list[to].push_back( make_pair( from, cost ) );
		}

		vector <int> tmp( num_intersections + 1, INF );
		for( int i = 0; i < num_fire_stations; i++ )
		{
			priority_queue < pair <int, int> > pq;
			pq.push( make_pair( fire_stations[i], 0 ) );
			tmp[fire_stations[i]] = 0;

			while( !pq.empty() )
			{
				pair <int, int> cur = pq.top();
				pq.pop();

				vector < pair <int, int> >::iterator it = adj_list[cur.first].begin();
				while( it != adj_list[cur.first].end() )
				{
					if( tmp[it->first] > tmp[cur.first] + it->second )
					{
						tmp[it->first] = tmp[cur.first] + it->second;
						pq.push( make_pair( it->first, tmp[it->first] ) );
					}
					it++;
				}
			}
		}

		vector <int> dist;
		pair <int, int> best;
		best.first = 0, best.second = INF;

		for( int i = 1; i <= num_intersections; i++ )
		{
			dist = tmp;

			priority_queue < pair <int, int> > pq;
			pq.push( make_pair( i, 0 ) );
			dist[i] = 0;

			while( !pq.empty() )
			{
				pair <int, int> cur = pq.top();
				pq.pop();

				vector < pair <int, int> >::iterator it = adj_list[cur.first].begin();
				while( it != adj_list[cur.first].end() )
				{
					if( dist[it->first] > dist[cur.first] + it->second )
					{
						dist[it->first] = dist[cur.first] + it->second;
						pq.push( make_pair( it->first, dist[it->first] ) );
					}
					it++;
				}
			}

			int val = -1;
			for( int j = 1; j <= num_intersections; j++ )
				val = max( val, dist[j] );
				
			if( val < best.second )
			{
				best.first = i;
				best.second = val;
			}
		}

		cout << best.first << endl;
		cout << best.second << endl;
	}

	return 0;
}
