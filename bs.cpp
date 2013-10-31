#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int num_nums, num;
    cin >> num >> num_nums;

    vector <int> nums;
    for( int i = 0; i < num_nums; i++ )
    {
        cin >> num;
        nums.push_back(num);
    }

    bool found = find( num, nums );
    if( found ) cout << "FOUND" << endl;
    else cout << "NOT" << endl;

    return 0;
}
