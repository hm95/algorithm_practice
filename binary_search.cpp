#include <iostream>
#include <vector>
using namespace std;

int get_offset( vector <int> values )
{
    int low = 0, high = values.size() - 1;

    while( values[low] > values[high] )
    {
        int mid = (low + high) / 2;
        if( values[mid] > values[high] ) low = mid + 1;
        else high = mid;
    }
    return low;
}

int index( vector <int> values, const int& value )
{
    int low = 0, high = values.size() - 1, offset = get_offset( values );
    if( values[offset] <= value && values[high] >= value )
        low = offset;
    else
        high = offset;

    while( low != high )
    {
        int mid = (low + high) / 2;
        if( values[mid] >= value ) high = mid;
        else low = mid + 1;
    }
    return low;
}

int imo( vector <int> array, int q )
{
  int low = 0, high = array.size() - 1, mid;

  while( low < high )
  {
    mid = (low + high) / 2;
    if( array[mid] >= q ) high = mid;
    else low = mid + 1;
  }

  if( array[low] < q ) low++;
  return low;
}

int main()
{
    int num_nums;
    cin >> num_nums;
    num_nums = 0;

    vector <int> values( num_nums );

    for( int i = 0; i < num_nums; i++ )
        cin >> values[i];

    for( int i = 0; i < num_nums; i++ )
        cout << values[i] << " found at index " << imo( values, values[i] ) << endl;
    cout << imo(values, 11);

    return 0;
}
