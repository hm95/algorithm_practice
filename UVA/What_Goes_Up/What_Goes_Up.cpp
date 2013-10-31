#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> sequence;
	int value;

	while( cin >> value )
		sequence.push_back( value );

	vector <int> lis_length( sequence.size(), 1 );

	int max_lis_length = -1, lis_ending_index = -1;
	for( int i = 1; i < sequence.size(); i++ )
		for( int j = i - 1; j >= 0; j-- )
		{
			if( sequence[i] > sequence[j] )
				lis_length[i] = max( lis_length[i], 1 + lis_length[j] );

			if( lis_length[i] >= max_lis_length )
			{
				max_lis_length = lis_length[i];
				lis_ending_index = i;
			}
		}

	int next_val = lis_length[lis_ending_index];
	vector <int> lis;

	cout << max_lis_length << endl << "-" << endl;
	for( int i = lis_ending_index; i >= 0; i-- )
	{
		if( lis_length[i] == next_val )
		{
			lis.push_back( sequence[i] );
			next_val--;
		}

		if( next_val < 0 ) break;
	}

	for( int i = lis.size() - 1; i >= 0; i-- )
		cout << lis[i] << endl;

	return 0;
}
