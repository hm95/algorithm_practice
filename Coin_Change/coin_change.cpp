#include <iostream>
#include <vector>
using namespace std;

int num_ways( const vector <int>& coins, const int& num_cents )
{
    vector <int> num_ways( num_cents + 1, 0 );
    num_ways[0] = 1;

    for( int i = 0; i < coins.size(); i++ )
        for( int j = 0; j + coins[i] <= num_cents; j++ )
            num_ways[j + coins[i]] += num_ways[j];

    return num_ways[num_cents];
}

int main()
{
    int num_coins, num_cents;
    cin >> num_coins >> num_cents;

    vector <int> coins( num_coins );
    for( int i = 0; i < num_coins; i++ )
        cin >> coins[i];

    cout << "There are " << num_ways( coins, num_cents ) << " ways to make change for " << num_cents << " cents." << endl;

    return 0;
}
