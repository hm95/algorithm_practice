#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

struct pos
{
	int node;
	char colour;
};

int main()
{
	int n, l;
	bool first = true;

	while( cin >> n )
	{
		if( first ) first = false;
		else cout << endl;

		if( n == 0 ) break;

		cin >> l;
		map <int, vector<int> > node_map;
		map <int, char> colour;

		int from, to;
		for( int i = 0; i < l; i++ )
		{
			cin >> from >> to;
			node_map[from].push_back( to );
			node_map[to].push_back( from );
		}
	
		map <int, vector<int> >::iterator it = node_map.begin();

		bool visited[n];
		memset( visited, 0, sizeof( visited ) );

		pos start;
		start.colour = 'b';
		start.node = it->first;

		queue <pos> q;
		q.push( start );

		bool bi = true, done = false;

		while( !q.empty() && !done )
		{
			pos tmp = q.front();
			q.pop();
			char cur_colour = tmp.colour;

			if( cur_colour == 'b' ) cur_colour = 'w';
			else cur_colour = 'b';

			vector <int>::iterator it = node_map[tmp.node].begin();

			while( it != node_map[tmp.node].end() )
			{
				pos curr;
				curr.node = *it;
				it++;

				if( !visited[curr.node] )
				{
					curr.colour = cur_colour;
					visited[curr.node] = true;
					colour[curr.node] = cur_colour;
					q.push( curr );
				}
			}
		}

		bool d = false;
		while( it != node_map.end() && !d )
		{
			vector <int>::iterator vt = node_map[it->first].begin();
			char c = colour[it->first];
			while( vt != node_map[it->first].end() )
			{
				if( colour[*vt] == c )
				{
					bi = false;
					d = true;
					break;
				}
				vt++;
			}
			it++;
		}

		if( bi ) cout << "BICOLORABLE.";
		else cout << "NOT BICOLORABLE.";

		node_map.clear();
		colour.clear();
	}

	return 0;
}
