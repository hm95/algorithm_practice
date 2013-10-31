#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

void generate_subsets( int index, string str, string ret, vector <string>& subsets, int case_number, string which_case )
{
	if( str.size() != 0 )
	{
		if( case_number == 0 ) subsets.push_back( str );
		else if( case_number == 1 )
		{
			if( str.size() >= which_case[0] - '0' && str.size() <= which_case[2] - '0' )
				subsets.push_back( str );
		}
		else
		{
			if( str.size() == which_case[0] - '0' )
				subsets.push_back( str );
		}
	}

	while( index < ret.size() )
	{
		stringstream ss;
		ss << str << ret[index];
		index++;
		generate_subsets( index, ss.str(), ret, subsets, case_number, which_case );
	}
}

bool cmp( const string& s1, const string& s2 )
{
	if( s1.size() == s2.size() ) return s1 < s2;
	return s1.size() < s2.size();
}

int main()
{
	string which_case;
	getline( cin, which_case );

	int num_tests = which_case[0] - '0';
	bool first = true;

	for( int test_no = 0; test_no < num_tests; test_no++ )
	{
		if( first )
		{
			getline( cin, which_case );
			first = false;
		}
		else cout << endl;

 		getline( cin, which_case );

		int case_number;
		if( which_case[0] == '*' ) case_number = 0;
		else if( which_case[0] != 0 && which_case[2] != 0 ) case_number = 1;
		else case_number = 2;

		map <int, string> newspapers;
		string newspaper_name = "BEGIN";
		int count = 0;
		string ret = "";

		while( getline( cin, newspaper_name ) && newspaper_name != "" )
		{
			newspapers[count] = newspaper_name;
			count++;
			ret += count + '0';
		}

		vector <string> subsets;
		generate_subsets( 0, "", ret, subsets, case_number, which_case );

		vector <string>::iterator it = subsets.begin();
		sort( subsets.begin(), subsets.end(), cmp );

		int sz = 0;
		bool first_word = true;
		bool first_line = true;

		while( it != subsets.end() )
		{
			if( sz != it->size() )
			{
				if( !first_line ) cout << endl;
				if( first_line ) first_line = false;

				cout << "Size " << it->size() << endl;
				sz = it->size();
				first_word = true;
			}

			string t = *it;
			for( int i = 0; i < it->size(); i++ )
			{
				if( !first_word ) cout << ", " << newspapers[t[i] - '0' - 1];
				else
				{
					first_word = false;
					cout << newspapers[t[i] - '0' - 1];
				}
			}
			cout << endl;
			first_word = true;
			it++;
		}
		cout << endl;
		
		newspapers.clear();
		subsets.clear();
	}

	return 0;
}
