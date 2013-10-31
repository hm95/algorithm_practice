#include <iostream>
#include <vector>
using namespace std;

int get_offset( const vector <int> nums )
{
    int low = 0, high = nums.size() - 1;

    while( nums[low] > nums[high] )
    {
        int mid = (low + high) / 2;
        if( nums[mid] > nums[high] ) low = mid + 1;
        else high = mid;
    }

    return low;
}

bool find( const vector <int> nums, const int& value )
{
    int low = 0, high = nums.size() - 1, offset = get_offset( nums );

    if( nums[offset] <= value && nums[high] >= value ) low = offset;
    else high = offset;

    while( low != high )
    {
        int mid = ( low + high ) / 2;
        if( nums[mid] >= value ) high = mid;
        else low = mid + 1;
    }

    if( nums[low] == value ) return true;
    return false;
}

int main()
{
    int number_items;
    cin >> number_items;

    vector <int> nums( number_items );
    for( int i = 0; i < number_items; i++ )
        cin >> nums[i];

    int value;
    cin >> value;

    cout << value << " was" << ( find( nums, value ) ? "" : " not" ) << " found." << endl;

    return 0;
}
