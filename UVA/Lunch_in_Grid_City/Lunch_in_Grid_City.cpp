#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 9e8;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_no = 0; test_case_no < num_test_cases; test_case_no++ )
	{
		int rows, cols, cities;
		cin >> rows >> cols >> cities;

		vector < pair<int, int> > list_cities;
		vector < vector <int> > city_coord;
		vector <int> tmp;

		for( int i = 0; i < cols; i++ )
			tmp.push_back( 0 );

		for( int i = 0; i < rows; i++ )
			city_coord.push_back( tmp );

		for( int city_no = 0; city_no < cities; city_no++ )
		{
			int city_x, city_y;
			cin >> city_x >> city_y;

			city_coord[city_x - 1][city_y - 1] = 1;
			list_cities.push_back( make_pair( city_x, city_y ) );
		}

		int num_cities_to_right = cities;
		int num_cities_to_bot = cities;

		int num_cities_to_left = 0;
		int num_cities_to_top = 0;

		map <int, int> rmap;
		map <int, int> lmap;

		map <int, int> bmap;
		map <int, int> tmap;

		for( int i = 0; i < rows; i++ )
		{
			for( int j = 0; j < cols; j++ )
			{
				if( j == cols - 1 ) rmap[i] = num_cities_to_right;
				if( city_coord[j][i] == 1 ) num_cities_to_right--;

				if( city_coord[j][i] == 1 ) num_cities_to_left++;
				if( j == cols - 1 ) lmap[i] = num_cities_to_left;

				if( city_coord[i][j] == 1 ) num_cities_to_bot--;
				if( j == cols - 1 ) bmap[i] = num_cities_to_bot;

				if( j == cols - 1 ) tmap[i] = num_cities_to_top;
				if( city_coord[i][j] == 1 ) num_cities_to_top++;
			}
		}

		int dist = 0;
		vector < pair<int, int> >::iterator it = list_cities.begin();

		while( it != list_cities.end() )
		{
			dist += ( it->first - 1 ) + ( it->second - 1 );
			it++;
		}
		
		city_coord[0][0] = dist;

		for( int i = 0; i < rows; i++ )
		{
			for( int j = 0; j < cols; j++ )
			{
				if( i == 0 && j == 0 ) continue;
				if( i == 0 ) city_coord[i][j] = city_coord[i][j - 1] - ( rmap[j - 1] - lmap[j - 1] );
				else city_coord[i][j] = city_coord[i - 1][j] - bmap[i - 1] + tmap[i - 1];
			}
		}

		int minv = INF;
		for( int i = 0; i < rows; i++ )
			for( int j = 0; j < cols; j++ )
				minv = min( minv, city_coord[i][j] );

		int x_min, y_min;
		bool done = false;
		for( int i = 0; i < rows; i++ )
		{
			for( int j = 0; j < cols; j++ )
			{
				if( city_coord[i][j] == minv )
				{
					x_min = i + 1;
					y_min = j + 1;
					done = true;
					break;
				}
			}
			if( done ) break;
		}

		cout << "(Street: " << x_min << ", Avenue: " << y_min << ")" << endl;

		city_coord.clear();
		list_cities.clear();
		tmp.clear();
		rmap.clear();
		lmap.clear();
		tmap.clear();
		bmap.clear();
	}

	return 0;
}
