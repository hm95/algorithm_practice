#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int sequence_length;
	while( cin >> sequence_length )
	{
		if( sequence_length == 0 ) break;

		int current_value;
		vector <int> sequence;
		for( int i = 0; i < sequence_length; i++ )
		{
			cin >> current_value;
			sequence.push_back( current_value );
		}

		int cur_sum = 0, max_sum = 0;
		for( int i = 0; i < sequence_length; i++ )
		{
			cur_sum += sequence[i];
			if( cur_sum < 0 ) cur_sum = 0;

			max_sum = max( max_sum, cur_sum );
		}

		if( max_sum != 0 ) cout << "The maximum winning streak is " << max_sum << "." << endl;
		else cout << "Losing streak." << endl;
	}
	
	return 0;
}
