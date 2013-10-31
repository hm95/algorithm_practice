#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map <string, bool> forbidden_combos;
map <string, bool> visited;

int button_press_direction[] = { -1, 1 };

int get_min_num_button_presses( string starting_combo, string ending_combo )
{
	visited[starting_combo] = true;

	queue < pair <string, int> > q;
	q.push( make_pair( starting_combo, 0 ) );

	while( !q.empty() )
	{
		pair <string, int> cur = q.front();
		q.pop();

		if( cur.first == ending_combo ) return cur.second;

		string temp_combo;
		for( int i = 0; i < 4; i++ )
			for( int j = 0; j < 2; j++ )
			{
				temp_combo = cur.first;
				int c = temp_combo[i] - '0';
				c = ( c + button_press_direction[j] + 10 ) % 10;
				temp_combo[i] = c + '0';

				if( !visited[temp_combo] && !forbidden_combos[temp_combo] )
				{
					visited[temp_combo] = true;
					q.push( make_pair( temp_combo, 1 + cur.second ) );
				}
			}
	}

	return -1;
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
	{
		string s1, s2, s3, s4, e1, e2, e3, e4;
		cin >> s1 >> s2 >> s3 >> s4 >> e1 >> e2 >> e3 >> e4;

		string starting_combo, ending_combo;
		starting_combo = s1 + s2 + s3 + s4;
		ending_combo = e1 + e2 + e3 + e4;

		int num_forbidden_combos;
		cin >> num_forbidden_combos;

		char digit;
		string combo;
		for( int forbidden_combo_number = 0; forbidden_combo_number < num_forbidden_combos; forbidden_combo_number++ )
		{
			combo = "";
			for( int i = 0; i < 4; i++ )
			{
				cin >> digit;
				combo += digit;
			}

			forbidden_combos[combo] = true;
		}

		cout << get_min_num_button_presses( starting_combo, ending_combo ) << endl;

		visited.clear();
		forbidden_combos.clear();
	}

	return 0;
}
