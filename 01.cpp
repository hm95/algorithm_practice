#include <iostream>
#include <vector>
using namespace std;

int knap( const int& capacity, vector <int> values, vector <int> weights )
{
    vector <int> v_tmp( capacity + 1, 0 );
    vector < vector <int> > kval( weights.size() + 1, v_tmp );

    for( int i = 1; i <= weights.size(); i++ )
        for( int j = 0; j <= capacity; j++ )
        {
            if( weights[i - 1] > j )
                kval[i][j] = kval[i - 1][j];
            else
                kval[i][j] = max( kval[i - 1][j], values[i - 1] + kval[i - 1][j - weights[i - 1]] );
        }

    return kval[values.size()][capacity];
}

int main()
{
    int num_items, capacity;
    cin >> num_items >> capacity;

    vector <int> values( num_items ), weights( num_items );

    for( int i = 0; i < num_items; i++ )
        cin >> values[i];

    for( int i = 0; i < num_items; i++ )
        cin >> weights[i];

    cout << "MAX " << knap( capacity, values, weights ) << endl;

    return 0;
}
