#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int count_num_dependencies( const int& task_number, map < int, vector <int> >& adj_list, const int& num_tasks )
{
	vector <bool> visited( num_tasks + 1, false );

	int number_of_dependencies = 0;
	stack <int> stk;
	stk.push( task_number );

	while( !stk.empty() )
	{
		int cur = stk.top();
		stk.pop();

		vector <int>::iterator it = adj_list[cur].begin();
		while( it != adj_list[cur].end() )
		{
			if( !visited[*it] )
			{
				visited[*it] = true;
				stk.push( *it );
				number_of_dependencies++;
			}
			it++;
		}
	}

	return number_of_dependencies;
}

int main()
{
	int num_tasks;
	while( cin >> num_tasks )
	{
		if( num_tasks == 0 ) break;

		map < int, vector <int> > adj_list;
		for( int task_number = 1; task_number <= num_tasks; task_number++ )
		{
			int number_of_dependencies;
			cin >> number_of_dependencies;

			for( int dep_no = 0; dep_no < number_of_dependencies; dep_no++ )
			{
				int dep_id;
				cin >> dep_id;

				adj_list[task_number].push_back( dep_id );
			}
		}

		int max_number_of_dependencies = 0;
		int task_id = 0;

		for( int task_number = 1; task_number <= num_tasks; task_number++ )
			if( count_num_dependencies( task_number, adj_list, num_tasks ) > max_number_of_dependencies )
			{
				max_number_of_dependencies = count_num_dependencies( task_number, adj_list, num_tasks );
				task_id = task_number;
			}

		cout << task_id << endl;
	}

	return 0;
}
