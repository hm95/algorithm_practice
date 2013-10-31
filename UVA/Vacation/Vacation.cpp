#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_maximum_cities( string mothers_recommendation, string fathers_recommendation )
{
	vector <int> num_cities_tmp( fathers_recommendation.size() + 1, 0 );
	vector < vector <int> > num_cities ( mothers_recommendation.size() + 1, num_cities_tmp );

	for( int i = 1; i <= mothers_recommendation.size(); i++ )
		for( int j = 1; j <= fathers_recommendation.size(); j++ )
		{
			if( mothers_recommendation[i - 1] == fathers_recommendation[j - 1] )
				num_cities[i][j] = 1 + num_cities[i - 1][j - 1];
			else
				num_cities[i][j] = max( num_cities[i - 1][j], num_cities[i][j - 1] );
		}
	
	return num_cities[mothers_recommendation.size()][fathers_recommendation.size()];
}

int main()
{
	int case_number = 1;
	string mothers_recommendation, fathers_recommendation;

	while( getline( cin, mothers_recommendation ) && getline( cin, fathers_recommendation ) && mothers_recommendation != "#" )
	{
		cout << "Case #" << case_number << ": you can visit at most " << get_maximum_cities( mothers_recommendation, fathers_recommendation ) << " cities." << endl;
		case_number++;
	}

	return 0;
}
