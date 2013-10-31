#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_components, num_operations, max_current, sequence_num = 1;
	while( cin >> num_components >> num_operations >> max_current )
	{
		if( num_components == 0 && num_operations == 0 && max_current == 0 ) break;

		vector <int> cost, state;
		int device_num;

		for( int component_num = 0; component_num < num_components; component_num++ )
		{
			cin >> device_num;
			cost.push_back( device_num );
			state.push_back( 0 );
		}

		bool fuse_blown = false;
		int maximal_sum = 0, current_sum = 0;

		for( int operation_num = 0; operation_num < num_operations; operation_num++ )
		{
			cin >> device_num;
			device_num--;
			state[device_num] = !state[device_num];

			if( state[device_num] ) current_sum += cost[device_num];
			if( !state[device_num] ) current_sum -= cost[device_num];

			maximal_sum = max( maximal_sum, current_sum );
		}

		if( maximal_sum > max_current ) fuse_blown = true;

		cout << "Sequence " << sequence_num << endl;
		if( fuse_blown ) cout << "Fuse was blown." << endl;
		else
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maximal_sum << " amperes." << endl;
		}
		cout << endl;

		sequence_num++;
		state.clear();
		cost.clear();
	}

	return 0;
}
