#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

bool one_step_diff( string a, string b )
{
	int num_diff = 0;
	for( int i = 0; i < a.size(); i++ )
		if( a[i] != b[i] ) num_diff++;
	
	return num_diff == 1;
}

int shortest_transformation( string start, string end, map < int, vector <string> > words )
{
	set <string> visited;
	visited.insert( start );

	queue < pair <string, int> > q;
	q.push( make_pair( start, 0 ) );

	while( !q.empty() )
	{
		pair <string, int> cur = q.front();
		q.pop();

		if( cur.first == end ) return cur.second;

		vector <string>::iterator it = words[cur.first.size()].begin();
		while( it != words[cur.first.size()].end() )
		{
			if( one_step_diff( cur.first, *it ) && visited.find( *it ) == visited.end() )
			{
				visited.insert( *it );
				q.push( make_pair( *it, cur.second + 1 ) );
			}
			it++;
		}
	}
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	string line;
	getline( cin, line );
	getline( cin, line );

	for( int test_case_no = 0; test_case_no < num_test_cases; test_case_no++ )
	{
		map < int, vector <string> > words;
		while( getline( cin, line ) && line != "*" )
			words[line.size()].push_back( line );

		while( getline( cin, line ) && line != "" )
		{
			string start, end;
			istringstream iss( line );
			iss >> start >> end;

			cout << start << ' ' << end << ' ' << shortest_transformation( start, end, words ) << endl;
		}
		cout << endl;
	}

	return 0;
}
