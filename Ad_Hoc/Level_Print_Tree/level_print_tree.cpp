#include <iostream>
#include <map>
#include <queue>
using namespace std;

void print_level_by_level( int root, map < int, vector < pair <int, int> > > tree )
{
	queue <int> q1, q2;
	q1.push( root );

	while( !q1.empty() )
	{
		int cur = q1.front();
		q1.pop();

		cout << cur << " ";

		vector < pair <int, int> >::iterator it = tree[cur].begin();
		while( it != tree[cur].end() )
		{
			q2.push( it->first );
			q2.push( it->second );
			it++;
		}

		if( q1.empty() )
		{
			swap( q1, q2 );
			cout << endl;
		}
	}
}

int main()
{
	map < int, vector < pair <int, int> > > tree;

	int root;
	cin >> root;

	int node, left, right;
	while( cin >> node >> left >> right )
		tree[node].push_back( make_pair( left, right ) );

	print_level_by_level( root, tree );

	return 0;
}
