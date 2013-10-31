#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <set>
using namespace std;

void inorder( int root, map < int, pair <int, int> > tree )
{
    cout << "Inorder" << endl;
    stack <int> stk;
    stk.push( root );

    set <int> visited;

    while( !stk.empty() )
    {
        int cur = stk.top();
        pair <int, int> children = tree[cur];

        if( children.first && visited.find(children.first) == visited.end() )
        {
            stk.push( children.first );
            continue;
        }

        cout << cur << endl;
        visited.insert( cur );
        stk.pop();

        if( children.second && visited.find(children.second) == visited.end() )
        {
            stk.push( children.second );
            continue;
        }
    }
}

void preorder( int root, map < int, pair <int, int> > tree )
{
    cout << "Preorder" << endl;

    stack <int> stk;
    stk.push( root );

    set <int> visited;

    while( !stk.empty() )
    {
        int cur = stk.top();
        pair <int, int> children = tree[cur];

        cout << cur << endl;
        visited.insert( cur );
        stk.pop();

        if( children.second && visited.find(children.second) == visited.end() )
            stk.push( children.second );

        if( children.first && visited.find(children.first) == visited.end() )
            stk.push( children.first );
    }
}

void postorder( int root, map < int, pair <int, int> > tree )
{
    cout << "Postorder" << endl;
    stack <int> stk;
    stk.push( root );

    set <int> visited;

    while( !stk.empty() )
    {
        int cur = stk.top();
        pair <int, int> children = tree[cur];

        if( children.first && visited.find(children.first) == visited.end() )
        {
            stk.push( children.first );
            continue;
        }

        if( children.second && visited.find(children.second) == visited.end() )
        {
            stk.push( children.second );
            continue;
        }

        cout << cur << endl;
        visited.insert( cur );
        stk.pop();
    }
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

    inorder( root, tree );
    preorder( root, tree );
    postorder( root, tree );

    return 0; 
}
