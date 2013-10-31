#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	string line1, line2;
	getline( cin, line1 );

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		getline( cin, line1 );
		getline( cin, line1 );
		getline( cin, line2 );

		istringstream iss( line1 );
		istringstream bss( line2 );

		string val1, val2;
		map <string, string> mapping;

		while( iss >> val1 && bss >> val2 )
			mapping[val1] = val2;

		map <string, string>::iterator it = mapping.begin();
		while( it != mapping.end() )
		{
			cout << it->second << endl;
			it++;
		}

		if( test_no != num_test_cases - 1 ) cout << endl;
	}

	return 0;
}
