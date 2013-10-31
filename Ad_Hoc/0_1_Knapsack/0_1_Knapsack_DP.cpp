#include <iostream>
#include <vector>
using namespace std;

int find_knapsack_value( vector <int> weights, vector <int> values, int capacity )
{
	vector <int> knapsack_value_temp( capacity + 1, 0 );
	vector < vector <int> > knapsack_value( weights.size() + 1, knapsack_value_temp );

	for( int i = 0; i <= values.size(); i++ )
		knapsack_value[i][0] = 0;

	for( int i = 0; i <= capacity; i++ )
		knapsack_value[0][i] = 0;

	for( int i = 1; i <= values.size(); i++ )
		for( int j = 0; j <= capacity; j++ )
		{
			if( weights[i - 1] <= j )
				knapsack_value[i][j] = max( knapsack_value[i - 1][j], values[i - 1] + knapsack_value[i - 1][j - weights[i - 1]] );
			else
				knapsack_value[i][j] = knapsack_value[i - 1][j];
		}

	return knapsack_value[values.size()][capacity];
}

int main()
{
	int capacity, num_objects;
	cin >> capacity >> num_objects;

	vector <int> values, weights;
	int tmp;
	for( int i = 0; i < num_objects; i++ )
	{
		cin >> tmp;
		values.push_back( tmp );
	}

	for( int i = 0; i < num_objects; i++ )
	{
		cin >> tmp;
		weights.push_back( tmp );
	}

	cout << "Maximum is " << find_knapsack_value( weights, values, capacity ) << endl;

	return 0;
}
