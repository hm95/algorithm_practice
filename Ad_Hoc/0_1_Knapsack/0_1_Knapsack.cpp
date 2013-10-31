#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 10;
const int UNKNOWN = -1;
const int MAX_WEIGHT = 12;
const int MAX_VALUE = 10;

class data
{
	private:
		int memo[MAX_NUM_ELEMENTS][MAX_WEIGHT + 1];
		int V[MAX_NUM_ELEMENTS];
		int W[MAX_NUM_ELEMENTS];
		
	public:
		data();
		void calc_max_value( int MAX_WEIGHT );
		int Knapsack( int index, int maximum_weight );
};

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		W[i] = rand() % MAX_VALUE;

	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		V[i] = rand() % MAX_VALUE;

	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		for( int j = 0; j <= MAX_WEIGHT; j++ )
			memo[i][j] = UNKNOWN;
}

void data::calc_max_value( const int MAX_WEIGHT )
{
	cout << "The weights of the objects are " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << W[i] << " ";
	cout << endl;

	cout << "The values of the objects are " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << V[i] << " ";
	cout << endl;

	cout << "The maximum value of the objects, O', with total weight <= " << MAX_WEIGHT << " is " << Knapsack( MAX_NUM_ELEMENTS - 1, MAX_WEIGHT ) << endl;
}

int data::Knapsack( int index, int maximum_weight )
{
	if( memo[index][maximum_weight] != UNKNOWN )
		return memo[index][maximum_weight];

	int with_i = 0, without_i = 0;

	if( index == 0 )
	{
		if( W[index] <= maximum_weight )
			memo[index][maximum_weight] = V[index];
		else
			memo[index][maximum_weight] = 0;

		return memo[index][maximum_weight];
	}

	without_i = Knapsack( index - 1, maximum_weight );
	if( W[index] > maximum_weight )
	{
		memo[index][maximum_weight] = without_i;
		return memo[index][maximum_weight];
	}
	else
		with_i = V[index] + Knapsack( index - 1, maximum_weight - W[index] );

	memo[index][maximum_weight] = max( with_i, without_i );
	return memo[index][maximum_weight];

	// This is the basic recursive solution, without memoization in place
	/*
	int with_i = 0, without_i = 0;

	if( index == 0 )
	{
		if( W[index] <= maximum_weight )
			return V[index];
		else
			return 0;
	}

	without_i = Knapsack( index - 1, maximum_weight );
	if( W[index] > maximum_weight )
		return without_i;
	else
		with_i = V[index] + Knapsack( index - 1, maximum_weight - W[index] );

	return max( with_i, without_i );
	*/
}

int main()
{
	data myData;
	myData.calc_max_value( MAX_WEIGHT );
	
	return 0;
}
