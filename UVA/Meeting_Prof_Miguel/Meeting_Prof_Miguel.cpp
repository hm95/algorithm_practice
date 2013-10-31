#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map <int, string> num_map;

const int INFINITY = 9e8;

bool compare( const pair <int, int>& p1, const pair <int, int>& p2 )
{
	if( p1.first != p2.first ) return p1.first < p2.first;
	return num_map[p1.second] < num_map[p2.second];
}

int main()
{
	int num_lines;
	while( cin >> num_lines )
	{
		if( num_lines == 0 ) break;

		map <string, int> city_map;
		int num_cities = 1;

		vector < pair < pair <string, string>, int > > list_Y, list_M;

		for( int line_no = 0; line_no < num_lines; line_no++ )
		{
			int cost;
			string person, dir, from, to;
			cin >> person >> dir >> from >> to >> cost;

			if( !city_map[from] )
			{
				city_map[from] = num_cities;
				num_map[num_cities] = from;
				num_cities++;
			}
			if( !city_map[to] )
			{
				city_map[to] = num_cities;
				num_map[num_cities] = to;
				num_cities++;
			}
			if( person == "Y" )
			{
				list_Y.push_back( make_pair( make_pair( from, to ), cost ) );
				if( dir == "B" )
					list_Y.push_back( make_pair( make_pair( to, from ), cost ) );
			}
			else
			{
				list_M.push_back( make_pair( make_pair( from, to ), cost ) );
				if( dir == "B" )
					list_M.push_back( make_pair( make_pair( to, from ), cost ) );
			}
		}

		string yS, mS;
		cin >> yS >> mS;

		vector <int> g_tmp( num_cities, INFINITY );
		vector < vector <int> > graph_Y( num_cities, g_tmp ), graph_M = graph_Y;
		num_cities--;

		for( int i = 0; i < list_Y.size(); i++ )
			graph_Y[city_map[list_Y[i].first.first]][city_map[list_Y[i].first.second]] = min( graph_Y[city_map[list_Y[i].first.first]][city_map[list_Y[i].first.second]], list_Y[i].second );

		for( int i = 0; i < list_M.size(); i++ )
			graph_M[city_map[list_M[i].first.first]][city_map[list_M[i].first.second]] = min( graph_M[city_map[list_M[i].first.first]][city_map[list_M[i].first.second]], list_M[i].second );

		for( int i = 1; i <= num_cities; i++ )
			for( int j = 1; j <= num_cities; j++ )
				if( i == j )
					graph_Y[i][j] = graph_M[i][j] = 0;

		for( int k = 1; k <= num_cities; k++ )
			for( int i = 1; i <= num_cities; i++ )
				for( int j = 1; j <= num_cities; j++ )
				{
					graph_Y[i][j] = min( graph_Y[i][j], graph_Y[i][k] + graph_Y[k][j] );
					graph_M[i][j] = min( graph_M[i][j], graph_M[i][k] + graph_M[k][j] );
				}

		vector < pair <int, int> > list_spots;
		int startingY = city_map[yS], startingM = city_map[mS];
		int dist = INFINITY, min_v = INFINITY;

		if( startingY == startingM && startingY == 0 && startingM == 0 )
		{
			cout << "0 " << yS << endl; 
			continue;
		}
		else if( startingY == 0 || startingM == 0 ) dist = INFINITY;

		for( int node = 1; node <= num_cities; node++ ) 
		{
			if( graph_Y[startingY][node] + graph_M[startingM][node] <= dist ) 
				list_spots.push_back( make_pair( graph_Y[startingY][node] + graph_M[startingM][node], node ) );

			dist = min( dist, graph_Y[startingY][node] + graph_M[startingM][node] );
		}

		if( dist == INFINITY ) cout << "You will never meet." << endl;
		else
		{
			sort( list_spots.begin(), list_spots.end(), compare );
			cout << dist;
			for( int i = 0; i < list_spots.size(); i++ )
				if( list_spots[i].first == dist )
					cout << ' ' << num_map[list_spots[i].second];
			cout << endl;
		}

		graph_M.clear();
		graph_Y.clear();
		list_spots.clear();
		num_map.clear();
		city_map.clear();
	}
	
	return 0;
}
