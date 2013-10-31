#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool has_3_element_subset( vector <int> list )
{
    set <int> pair_sums;

    for( int i = 0; i < list.size(); i++ )
        for( int j = 0; j < list.size(); j++ )
            if( i != j )
                pair_sums.insert( i + j );

    for( int i = 0; i < list.size(); i++ )
        if( pair_sums.find( -1 * list[i] ) != pair_sums.end() )
            return true;

    return false;
}

int main()
{
    int num_elements;
    cin >> num_elements;

    vector <int> list( num_elements );
    for( int i = 0; i < num_elements; i++ )
        cin >> list[i];

    cout << "There is " << ( has_3_element_subset( list ) ? "" : "not " ) << "a 3 element subset in the list that adds to zero." << endl;

    return 0;
}
