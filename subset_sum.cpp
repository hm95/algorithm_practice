#include <iostream>
#include <vector>
using namespace std;

int get_max( vector <int> values, int sum )
{
    vector <int> tmp( sum + 1, 0 );
    vector < vector <int> > maxs( values.size() + 1, tmp );

    for( int i = 1; i <= values.size(); i++ )
        for( int j = 0; j <= sum; j++ )
        {
            if( values[i - 1] <= j )
                maxs[i][j] = max( maxs[i - 1][j], values[i - 1] + maxs[i - 1][j - values[i - 1]] );
            else
                maxs[i][j] = maxs[i - 1][j];
        }

    for( int i = 0; i <= values.size(); i++ )
    {
        for( int j = 0; j <= sum; j++ )
            cout << maxs[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for( int i = 0; i < values.size(); i++ )
        cout << values[i] << " ";
    cout << endl;

    return maxs[values.size()][sum];
}

int main()
{
    int num_items, sum;
    cin >> num_items >> sum;

    vector <int> values( num_items );
    for( int i = 0; i < num_items; i++ )
        cin >> values[i];

    /*if( get_max( values, sum ) == sum )
        cout << "NP not." << endl;
    else
        cout << "NP." << endl;*/
    cout << get_max( values, sum ) << endl;

    return 0;
}
