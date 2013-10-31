#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <int> connections_temp;
vector < vector <int> > connections;
vector <bool> visited;

void knock_them_over( int domino_number )
{
	visited[domino_number] = true;

	stack <int> stk;
	stk.push( domino_number );

	while( !stk.empty() )
	{
		int dom = stk.top();
		stk.pop();

		vector <int>::iterator it = connections[dom].begin();
		while( it != connections[dom].end() )
		{
			if( !visited[*it] )
			{
				visited[*it] = true;
				stk.push( *it );
			}
			it++;
		}
	}
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int test_case_number = 0; test_case_number < num_test_cases; test_case_number++ )
	{
		int num_dominos, num_connections, num_dominos_knocked_over;
		cin >> num_dominos >> num_connections >> num_dominos_knocked_over;

		for( int i = 0; i < num_dominos; i++ )
		{
			connections.push_back( connections_temp );
			visited.push_back( false );
		}

		int from, to;
		for( int connection_number = 0; connection_number < num_connections; connection_number++ )
		{
			cin >> from >> to;
			connections[from - 1].push_back( to - 1 );
		}

		int domino_number;
		for( int knocked_over_domino_number = 0; knocked_over_domino_number < num_dominos_knocked_over; knocked_over_domino_number++ )
		{
			cin >> domino_number;

			if( !visited[domino_number - 1] )
				knock_them_over( domino_number - 1 );
		}

		int total_num_dominos_knocked_over = 0;
		for( int domino_num = 0; domino_num < num_dominos; domino_num++ )
			if( visited[domino_num] )
				total_num_dominos_knocked_over++;

		cout << total_num_dominos_knocked_over << endl;

		connections.clear(), visited.clear();
	}

	return 0;
}
