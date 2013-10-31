#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
	{
		map < int, vector <int> > danced_with;

		int num_people, num_dancing_couples;
		cin >> num_people >> num_dancing_couples;

		int partner_1, partner_2;
		for( int dancing_couple_number = 0; dancing_couple_number < num_dancing_couples; dancing_couple_number++ )
		{
			cin >> partner_1 >> partner_2;
			danced_with[partner_1].push_back( partner_2 );
			danced_with[partner_2].push_back( partner_1 );
		}

		for( int person = 1; person < num_people; person++ )
		{
			int giovanni_number;

			queue < pair <int, int> > q;
			q.push( make_pair( person, 0 ) );

			map <int, bool> visited;
			visited[person] = true;

			while( !q.empty() )
			{
				pair <int, int> cur = q.front();
				q.pop();

				if( cur.first == 0 )
				{
					giovanni_number = cur.second;
					break;
				}

				vector <int>::iterator it = danced_with[cur.first].begin();
				while( it != danced_with[cur.first].end() )
				{
					if( !visited[*it] )
					{
						visited[*it] = true;
						q.push( make_pair( *it, cur.second + 1 ) );
					}
					it++;
				}
			}

			cout << giovanni_number << endl;
		}

		if( test_case_number != num_test_cases - 1 ) cout << endl;
	}

	return 0;
}
