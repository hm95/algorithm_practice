#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int get_maximum_value( const int& max_weight, const vector <int> values, const vector <int> weights )
{
    vector <int> temp( max_weight +  1, 0 );
    vector < vector <int> > max_values( values.size() + 1, temp );

    for( int i = 1; i <= values.size(); i++ )
        for( int j = 0; j <= max_weight; j++ )
        {
            if( weights[i - 1] <= j )
                max_values[i][j] = max( max_values[i - 1][j], values[i - 1] + max_values[i - 1][j - weights[i - 1]]);
            else
                max_values[i][j] = max_values[i - 1][j];
        }

    return max_values[values.size()][max_weight];
}

int main()
{
    int num_items, max_weight;
    cin >> num_items >> max_weight;

    vector <int> values( num_items ), weights( num_items );

    for( int i = 0; i < num_items; i++ )
        cin >> values[i];

    for( int i = 0; i < num_items; i++ )
        cin >> weights[i];
    
    int maximum_value = get_maximum_value( max_weight, values, weights );

    cout << "The maximum value is " << maximum_value << endl;

    return 0;
}
