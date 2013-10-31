#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 9e8;
const double PI = 3.141592653589793;

int calculate_geodesic_distance( double lat1, double lon1, double lat2, double lon2 )
{
	double dlon = lon2 - lon1;
	double dlat = lat2 - lat1;
	double a = ( sin( dlat / 2.0 ) ) * ( sin ( dlat / 2.0 ) ) + cos( lat1 ) * cos( lat2 ) * ( sin( dlon / 2.0 ) ) * ( sin( dlon /2.0 ) );
	double c = 2 * atan2( sqrt( a ), sqrt( 1 - a ) );
	
	return int( c * 6378.0 + 0.5 );
}

int main()
{
	int num_cities, num_connections, num_pairs, test_case_number = 1;
	while( cin >> num_cities >> num_connections >> num_pairs )
	{
		if( num_cities == 0 && num_connections == 0 && num_pairs == 0 ) break;
		if( test_case_number != 1 ) cout << endl;

		vector <int> g_tmp( num_cities, INF );
		vector < vector <int> > graph( num_cities, g_tmp );
		map <string, int> city_map;
		vector < pair <double, double> > list_of_cities( num_cities );

		double latitude, longitude;
		string city;

		for( int city_number = 0; city_number < num_cities; city_number++ )
		{
			cin >> city >> latitude >> longitude;
			city_map[city] = city_number;
			list_of_cities[city_number] = make_pair( latitude * PI / 180.0, longitude * PI / 180.0 );
		}

		string from, to;
		for( int connection_number = 0; connection_number < num_connections; connection_number++ )
		{
			cin >> from >> to;
			graph[city_map[from]][city_map[to]] = calculate_geodesic_distance( list_of_cities[city_map[from]].first, list_of_cities[city_map[from]].second, list_of_cities[city_map[to]].first, list_of_cities[city_map[to]].second );
		}

		for( int k = 0; k < num_cities; k++ )
			for( int i = 0; i < num_cities; i++ )
				for( int j = 0; j < num_cities; j++ )
					graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );

		cout << "Case #"  << test_case_number << endl;
		for( int pair_number = 0; pair_number < num_pairs; pair_number++ )
		{
			cin >> from >> to;
			if( graph[city_map[from]][city_map[to]] == INF ) cout << "no route exists" << endl;
			else cout << graph[city_map[from]][city_map[to]] << " km" << endl;
		}

		test_case_number++;
		graph.clear();
		list_of_cities.clear();
		city_map.clear();
	}

	return 0;
}
