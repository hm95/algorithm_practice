#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		int num_relatives;
		cin >> num_relatives;

		vector <int> relatives;
		for( int relative_no = 0; relative_no < num_relatives; relative_no++ )
		{
			int rel_dist;
			cin >> rel_dist;
			relatives.push_back( rel_dist );
		}

		sort( relatives.begin(), relatives.end() );
		int median = relatives[ (relatives.size() - 1)/ 2 ];

		int dist = 0;
		for( int relative_no = 0; relative_no < relatives.size(); relative_no++ )
			dist += abs( relatives[relative_no] - median );

		cout << dist << endl;
	}

	return 0;
}
