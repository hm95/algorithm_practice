#include <iostream>
#include <vector>
using namespace std;

int mcs( vector <int> numbers )
{
	int cur_sum = 0, max_sum = 0;

	for( int i = 0; i < numbers.size(); i++ )
	{
		cur_sum += numbers[i];

		if( cur_sum < 0 )
			cur_sum = 0;

		max_sum = max( max_sum, cur_sum );
	}

	return max_sum;
}

int main()
{
	int size;
	cin >> size;

	vector <int> numbers( size );
	for( int i = 0; i < size; i++ )
		cin >> numbers[i];

	cout << "The sum of the MCS is " << mcs( numbers ) << endl;

	return 0;
}
