#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> get_k_smallest( const int& k, vector <int>& list_nums )
{
    vector <int> k_smallest;
    priority_queue< int, vector <int>, greater <int> > pq;

    for( int i = 0; i < list_nums.size(); i++ )
        pq.push( list_nums[i] );

    for( int i = 0; i < k; i++ )
    {
        k_smallest.push_back( pq.top() );
        pq.pop();
    }

    return k_smallest;
}

int main()
{
    int k, num_elements, num;
    cin >> k >> num_elements;

    vector <int> list_nums;
    for( int i = 0; i < num_elements; i++ )
    {
        cin >> num;
        list_nums.push_back( num );
    }

    vector <int> k_smallest = get_k_smallest( k, list_nums );
    partial_sort( list_nums.begin(), list_nums.begin() + k, list_nums.end() );

    cout << "The " << k << " smallest elements are: " << endl;
    for( int i = 0; i < k_smallest.size(); i++ )
        cout << k_smallest[i] << " ";
    cout << endl;

    cout << "The " << k << " smallest elements are: " << endl;
    for( int i = 0; i < k; i++ )
        cout << list_nums[i] << " ";
    cout << endl;

    return 0;
}
