#include <iostream>
#include <vector>
using namespace std;

int get_mcs( const vector <int>& numbers )
{
    int max_sum = 0, cur_sum = 0;

    for( int i = 0; i < numbers.size(); i++ )
    {
        cur_sum += numbers[i];

        if( cur_sum < 0 )
            cur_sum = 0;

        max_sum = max( max_sum, cur_sum );
    }

    return max_sum;
}

int main()
{
    int num_items;
    cin >> num_items;

    vector <int> numbers( num_items );
    for( int i = 0; i < num_items; i++ )
        cin >> numbers[i];

    cout << "The maximum contiguous sum is " << get_mcs( numbers ) << endl;

    return 0; 
}
