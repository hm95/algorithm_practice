#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

void level_order_print( int root, map <int, vector <int> > tree )
{
    queue <int> q1, q2;
    q1.push( root );

    while( !q1.empty() )
    {
        int cur = q1.front();
        q1.pop();
        cout << cur << " ";

        for( int i = 0; i < tree[cur].size(); i++ )
            q2.push( tree[cur][i] );

        if( q1.empty() )
        {
            cout << endl;
            swap( q1, q2 );
        }
    }
}

int main()
{
    map < int, vector <int> > tree;

    int root, num_nodes;
    cin >> root >> num_nodes;

    for( int i = 0; i < num_nodes; i++ )
    {
        int node, num_children;
        cin >> node >> num_children;

        int child;
        for( int j = 0; j < num_children; j++ )
        {
            cin >> child;
            tree[node].push_back( child );
        }
    }

    level_order_print( root, tree );

    return 0;
}
