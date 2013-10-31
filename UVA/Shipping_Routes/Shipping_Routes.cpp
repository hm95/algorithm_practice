#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INFINITY = 9e8;
map < string, vector <string> > adj_list;

int get_number_shipping_routes( string from, string to )
{
    map <string, bool> visited;
    visited[from] = true;

    queue < pair <string, int> > q;
    q.push( make_pair( from, 0 ) );

    while( !q.empty() )
    {
        pair <string, int> cur = q.front();
        q.pop();

        if( cur.first == to ) return cur.second;

        vector <string>::iterator it = adj_list[cur.first].begin();
        while( it != adj_list[cur.first].end() )
        {
            if( !visited[*it] )
            {
                visited[*it] = true;
                q.push( make_pair( *it, 1 + cur.second ) );
            }
            it++;
        }
    }

    return INFINITY;
}

int main()
{
    int num_test_cases;
    cin >> num_test_cases;
    cout << "SHIPPING ROUTES OUTPUT" << endl;

    for( int test_case_number = 1; test_case_number <= num_test_cases; test_case_number++ )
    {
        cout << endl << "DATA SET " << test_case_number << endl << endl;

        int num_nodes, num_edges, num_pairs;
        cin >> num_nodes >> num_edges >> num_pairs;

        string node;
        for( int node_number = 0; node_number < num_nodes; node_number++ )
            cin >> node;

        string from, to;
        for( int edge_number = 0; edge_number < num_edges; edge_number++ )
        {
            cin >> from >> to;
            adj_list[from].push_back( to );
            adj_list[to].push_back( from );
        }

        int shipment_size;
        for( int pair_number = 0; pair_number < num_pairs; pair_number++ )
        {
            cin >> shipment_size >> from >> to;
            int num_shipping_legs = get_number_shipping_routes( from, to );

            if( num_shipping_legs == INFINITY ) cout << "NO SHIPMENT POSSIBLE" << endl;
            else cout << "$" << 100 * shipment_size * num_shipping_legs << endl;;
        }

        adj_list.clear();
    }
    cout << endl << "END OF OUTPUT" << endl;

    return 0;
}