#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int NO_PATH = -1;

struct pos
{
	string name;
	int litres_blood;
};

int main()
{
	int num_test_cases;
	cin >> num_test_cases;

	for( int i = 0; i < num_test_cases; i++ )
	{
		int num_edges;
		cin >> num_edges;

		map< string, vector< pair< string, pair<int, int> > > > node_list;

		string from, to;
		for( int i = 0; i < num_edges; i++ )
		{
			int s_time, e_time;
			cin >> from >> to >> s_time >> e_time;

			node_list[from].push_back( make_pair( to, make_pair( s_time, (s_time + e_time) % 24 ) ) );
		}

		string start, end;
		cin >> start >> end;
		
		vector< pair< string, pair<int, int> > >::iterator vt = node_list[start].begin();

		pos root;
		root.name = start;
		root.litres_blood = 0;

		queue <pos> q;
		q.push( root );

		bool done = false;
		int min_litres = NO_PATH;

		while( !q.empty() && !done )
		{
			pos tmp = q.front();
			q.pop();

			if( tmp.name == end )
			{
				done = true;
				min_litres = tmp.litres_blood;
				continue;
			}
		
			vector< pair< string, pair<int, int> > >::iterator vt = node_list[tmp.name].begin();
			while( vt != node_list[tmp.name].end() )
			{
				if( vt->second.first >= 18 && vt->second.second <= 6 )
				{
					pos curr;
					curr.name = vt->first;
					vector< pair< string, pair<int, int> > >::iterator ct = node_list[curr.name].begin();

					while( ct != node_list[curr.name].end() )
					{
						if( ct->second.first <= 6 && ct->second.second <= 6 )
						{
							curr.litres_blood = tmp.litres_blood;
							break;
						}
						else curr.litres_blood = tmp.litres_blood + 1;
						ct++;
					}

					q.push( curr );
				}
				vt++;
			}
		}

		cout << "Test case " << i + 1 << "." << endl;
		if( min_litres == NO_PATH ) cout << "There is no route Vladimir can take." << endl;
		else cout << "Vladimir needs " << min_litres << " litre(s) of blood." << endl;

		node_list.clear();
		q = queue <pos> ();
	}

	return 0;
}
