#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

bool is_bst( int root, map < int, pair <int, int> > tree )
{
    queue <int> q;
    q.push( root );

    while( !q.empty() )
    {
        int cur = q.front();
        q.pop();

        if( tree[cur].first != 0 )
        {
            if( tree[cur].first <= cur )
                q.push( tree[cur].first );
            else
                return false;
        }

        if( tree[cur].second != 0 )
        {
            if( tree[cur].second >= cur )
                q.push( tree[cur].second );
            else
                return false;
        }
    }

    return true;
}

int main()
{
    map < int, pair <int, int> > tree;

    int num_levels;
    cin >> num_levels;

    int rt, left, right;
    for( int i = 0; i < num_levels; i++ )
    {
        cin >> rt >> left >> right;
        tree[rt] = make_pair( left, right );
    }

    int root;
    cin >> root;

    cout << "This is " << ( is_bst( root, tree ) ? "" : "not " ) << "a BST" << endl;

    return 0; 
}
