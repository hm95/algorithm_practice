#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	string line;
	getline( cin, line );

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		map < int, vector <string> > mapping;
		int length_of_string, num_strings;

		getline( cin, line );
		getline( cin, line );

		istringstream iss( line );
		iss >> length_of_string >> num_strings;

		for( int string_no = 0; string_no < num_strings; string_no++ )
		{
			getline( cin, line );

			int count = 0;
			for( int i = 0; i < line.length(); i++ )
				for( int j = i; j < line.length(); j++ )
					if( line[i] > line[j] )
						count++;

			mapping[count].push_back( line );
		}

		map < int, vector <string> >::iterator mi = mapping.begin();

		while( mi != mapping.end() )
		{
			vector <string>::iterator st = mapping[mi->first].begin();
			while( st != mapping[mi->first].end() )
			{
				cout << *st << endl;
				st++;
			}
			mi++;
		}

		if( test_no != num_test_cases - 1 ) cout << endl;
	}

	return 0;
}
