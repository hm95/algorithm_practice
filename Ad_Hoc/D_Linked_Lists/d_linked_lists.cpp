#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map < int, vector <int> > get_lists( int root, map < int, vector < pair <int, int> > > tree )
{
	map < int, vector <int> > lists;

	queue < pair <int, int> > q;
	q.push( make_pair( root, 0 ) );

	while( !q.empty() )
	{
		pair <int, int> cur = q.front();
		q.pop();

		lists[cur.second].push_back( cur.first );

		vector < pair <int, int> >::iterator it = tree[cur.first].begin();
		while( it != tree[cur.first].end() )
		{
			q.push( make_pair( it->first, cur.second + 1 ) );
			q.push( make_pair( it->second, cur.second + 1 ) );
			it++;
		}
	}

	return lists;
}

int main()
{
	map < int, vector < pair <int, int> > > tree;

	int root, node, left, right;
	cin >> root;
	while( cin >> node >> left >> right )
		tree[node].push_back( make_pair( left, right ) );
	
	map < int, vector <int> > lists = get_lists( root, tree );

	for( int i = 0; i < lists.size(); i++ )
	{
		cout << "The nodes at level " << i << " are ";
		for( int j = 0; j < lists[i].size(); j++ )
			cout << lists[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	

	return 0;
}
