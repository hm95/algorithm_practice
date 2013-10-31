#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int calc_cycle_length( int k )
{
	int count = 1;

	while( k != 1 )
	{
		if( k % 2 == 0 ) k /= 2;
		else k = ( k * 3 ) + 1;
		count++;
	}
	
	return count;
}

int main()
{
	int max_cycle_length;
	vector <int> nums (2);
	int orig1, orig2;

	while( cin >> orig1 >> orig2 )
	{
		max_cycle_length = -1;
		nums[0] = orig1;
		nums[1] = orig2;
		sort( nums.begin(), nums.end() );

		for( int k = nums[0]; k <= nums[1]; k++ )
			max_cycle_length = max( max_cycle_length, calc_cycle_length(k) );
		cout << orig1 << ' ' << orig2 << ' ' << max_cycle_length << endl;
	}

	return 0;
}
