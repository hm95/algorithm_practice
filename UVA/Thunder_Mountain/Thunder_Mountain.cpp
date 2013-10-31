#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const double INF = 9e7;

double dist( int x1, int y1, int x2, int y2 )
{
	double x_one = x1, y_one = y1, x_two = x2, y_two = y2;
 	return abs( pow( pow( (y_two - y_one), 2.0 ) + pow( (x_two - x_one), 2.0 ) , 0.5 ) );
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_no = 1; test_no <= num_test_cases; test_no++ )
	{
		int num_cities;
		cin >> num_cities;

		vector <int> x_vals, y_vals;
		for( int city_num = 0; city_num < num_cities; city_num++ )
		{
			int x_coord, y_coord;
			cin >> x_coord >> y_coord;

			x_vals.push_back( x_coord );
			y_vals.push_back( y_coord );
		}

		vector <double> tmp;
		for( int i = 0; i < num_cities; i++ )
			tmp.push_back( INF );

		vector < vector <double> > distances;
		for( int i = 0; i < num_cities; i++ )
			distances.push_back( tmp );

		for( int i = 0; i < x_vals.size(); i++ )
			for( int j = 0; j < x_vals.size(); j++ )
				if( i != j && dist( x_vals[i], y_vals[i], x_vals[j], y_vals[j] ) <= 10.00 )
					distances[i][j] =  distances[j][i] = dist( x_vals[i], y_vals[i], x_vals[j], y_vals[j] );

		for( int k = 0; k < num_cities; k++ )
			for( int i = 0; i < num_cities; i++ )
				for( int j = 0; j < num_cities; j++ )
					distances[i][j] = min( distances[i][j], distances[i][k] + distances[k][j] );

		double max_dist = -1;
		for( int i = 0; i < x_vals.size(); i++ )
			for( int j = 0; j < x_vals.size(); j++ )
				if( i != j )
					max_dist = max( max_dist, distances[i][j] );

		cout << "Case #" << test_no << ":" << endl;
		if( max_dist == INF ) cout << "Send Kurdy" << endl;
		else cout << fixed << showpoint << setprecision (4) << max_dist << endl;

		distances.clear();
		x_vals.clear();
		y_vals.clear();
	}

	return 0;
}
