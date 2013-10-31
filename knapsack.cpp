#include <iostream>
#include <vector>
using namespace std;

int knapsack( const int& capacity, vector <int> values, vector <int> weights )
{
	vector <int> max_value_temp( capacity + 1, 0 );
	vector < vector <int> > max_value( values.size() + 1, max_value_temp );

	for( int i = 1; i <= values.size(); i++ )
		for( int j = 1; j <= capacity; j++ )
		{
			if( weights[i - 1] <= j )
				max_value[i][j] = max( max_value[i - 1][j], values[i - 1] + max_value[i - 1][j - weights[i - 1]] );
			else
				max_value[i][j] = max_value[i - 1][j];
		}

	return max_value[values.size()][capacity];
}

int main()
{
	int num_items, capacity;
	cin >> num_items >> capacity;

	vector <int> values( num_items );
	for( int item_number = 0; item_number < num_items; item_number++ )
		cin >> values[item_number];
	
	vector <int> weights( num_items );
	for( int item_number = 0; item_number < num_items; item_number++ )
		cin >> weights[item_number];

	cout << "The maximum value that can fit within the knapsack's capacity is " << knapsack( capacity, values, weights ) << endl;

	return 0;
}
