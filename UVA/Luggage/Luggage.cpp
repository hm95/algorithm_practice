#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	int num_test_cases;
	string input_line;

	cin >> num_test_cases;
	getline( cin, input_line );

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		getline( cin, input_line );

		int sum = 0, val;
		vector <int> weights;
		istringstream iss( input_line );

		while( iss >> val )
		{
			weights.push_back( val );
			sum += val;
		}

		if( sum % 2 != 0 ) cout << "NO" << endl;
		else
		{
			bool can_make_partition_of[sum + 1];
			for( int i = 0; i <= sum; i++ )
				can_make_partition_of[i] = false;

			can_make_partition_of[0] = true;

			for( int i = 0; i < weights.size(); i++ )
				for( int j = sum - weights[i]; j >= 0; j-- )
					if( can_make_partition_of[j] )
						can_make_partition_of[j + weights[i]] = true;

			if( can_make_partition_of[sum / 2] ) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

		weights.clear();
		input_line.clear();
	}

	return 0;
}
