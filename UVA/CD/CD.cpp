#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int optimal_cd_length( vector <int> track_lengths, int cd_size )
{
	vector <int> cd_lengths_temp( cd_size + 1, 0 );
	vector < vector <int> > cd_lengths( track_lengths.size() + 1, cd_lengths_temp );

	for( int track_number = 1; track_number <= track_lengths.size(); track_number++ )
		for( int length = 0; length <= cd_size; length++ )
		{
			if( track_lengths[track_number - 1] <= length )
				cd_lengths[track_number][length] = max( cd_lengths[track_number - 1][length], track_lengths[track_number - 1] + cd_lengths[track_number - 1][length - track_lengths[track_number - 1]] );
			else
				cd_lengths[track_number][length] = cd_lengths[track_number - 1][length];
		}
	
	stack <int> stk;
	int capacity = cd_size;
	for( int track_number = track_lengths.size(); track_number >= 1; track_number-- )
	{
		if( cd_lengths[track_number][capacity] <= capacity )
			if( cd_lengths[track_number][capacity] != cd_lengths[track_number - 1][capacity] )
			{
				stk.push( track_lengths[track_number - 1] );
				capacity -= track_lengths[track_number - 1];
			}
	}

	while( !stk.empty() )
	{
		cout << stk.top() << " ";
		stk.pop();
	}

	return cd_lengths[track_lengths.size()][cd_size];
}

int main()
{
	int cd_size, num_tracks;
	while( cin >> cd_size >> num_tracks )
	{
		vector <int> track_lengths;
		int value;

		for( int track_number = 0; track_number < num_tracks; track_number++ )
		{
			cin >> value;
			track_lengths.push_back( value );
		}

		cout << "sum:" << optimal_cd_length( track_lengths, cd_size ) << endl;
	}

	return 0;
}
