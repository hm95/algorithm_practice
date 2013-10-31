#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int value, list, list_number;
};


class compareNodes {
    public:
        bool operator()( node& n1, node& n2 )
        {
            if( n1.value < n2.value ) return true;
            return false;
        }
};

vector <int> two_way_merge( int num_elements, map <int, vector <int> > map_lists )
{
    vector <int> merged_list;

    int list1_index = 0, list2_index = 0;

    for( int i = 0; i < map_lists[0].size() + map_lists[1].size(); i++ )
    {
        if( list1_index > map_lists[0].size() - 1 )
            merged_list.push_back( map_lists[1][list2_index++] );
        else if( list2_index > map_lists[1].size() - 1 )
            merged_list.push_back( map_lists[0][list1_index++] );
        else if( map_lists[0][list1_index] < map_lists[1][list2_index] )
            merged_list.push_back( map_lists[0][list1_index++] );
        else
            merged_list.push_back( map_lists[1][list2_index++] );
    }

    return merged_list;
}

vector <int> n_way_merge( int num_elements, map <int, vector <int> > map_lists )
{
    vector <int> merged_list;

    priority_queue < node, vector <node>, compareNodes > pq;

    for( int i = 0; i < map_lists.size(); i++ )
    {
        node n;
        n.value = map_lists[i][0];
        n.list = i;
        n.list_number = 0;

        pq.push( n );
    }

    while( !pq.empty() )
    {
        node cur = pq.top();
        pq.pop();

        node n;
        if( map_lists[cur.list].size() > cur.list_number + 1 )
        {
            n.value = map_lists[cur.list][cur.list_number + 1];
            n.list = cur.list;
            n.list_number = cur.list_number + 1;
            pq.push( n );
        }

        merged_list.push_back( map_lists[cur.list][cur.list_number] );
    }

    return merged_list;
}


int main()
{
    int num_lists;
    cin >> num_lists;

    map <int, vector <int> > map_lists;

    for( int i = 0; i < num_lists; i++ )
    {
        int num_elements;
        cin >> num_elements;

        vector <int> cur_list( num_elements );
        for( int j = 0; j < num_elements; j++ )
            cin >> cur_list[j];

        map_lists[i] = cur_list;
    }

    vector <int> merged_list;
    if( num_lists == 2 ) merged_list = two_way_merge( num_lists, map_lists );
    else merged_list = n_way_merge( num_lists, map_lists );

    for( int i = 0; i < merged_list.size(); i++ )
        cout << merged_list[i] << " ";
    cout << endl;

    return 0;
}
