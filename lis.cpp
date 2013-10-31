#include <iostream>
#include <vector>
using namespace std;

int lis( vector <int> numbers )
{
	vector <int> lis_lengths( numbers.size(), 1 );

	int max_length = 1;
	for( int i = 0; i < numbers.size(); i++ )
	{
		for( int j = i - 1; j >= 0; j-- )
			if( numbers[i] > numbers[j] )
				lis_lengths[i] = max( lis_lengths[i], lis_lengths[j] + 1 );

		max_length = max( max_length, lis_lengths[i] );
	}

	return max_length;
}

int main()
{
	int size;
	cin >> size;

	vector <int> numbers;

	int value;
	for( int i = 0; i < size; i++ )
	{
		cin >> value;
		numbers.push_back( value );
	}

	cout << "The length of the longest increasing subsequence is " << lis( numbers ) << endl;

	return 0;
}
