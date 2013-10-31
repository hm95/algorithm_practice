#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_VAL = 88723;
const int NOT_KNOWN = -1;

class data
{
	private:
		int dp[MAX_VAL + 1];
		int memo[MAX_VAL + 1];
		int n;
		
	public:
		data();
		void calc_minimum_steps_to_one();
		int minimum_steps_to_one_dp( int n );
		int minimum_steps_to_one_memo( int n );
};

data::data()
{
	n = rand() % MAX_VAL;

	for( int i = 0; i <= MAX_VAL; i++ )
		memo[i] = NOT_KNOWN;

	dp[1] = 0;
}

void data::calc_minimum_steps_to_one()
{
	cout << "The minimum number of transformations to turn " << n << " into 1, using Memoization, is " << minimum_steps_to_one_memo( n ) << endl;
	cout << "The minimum number of transformations to turn " << n << " into 1, using Dynamic Programming, is " << minimum_steps_to_one_dp( n ) << endl;
}

int data::minimum_steps_to_one_dp( int n )
{
	for( int i = 2; i <= n; i++ )
	{
		dp[i] = 1 + dp[ i - 1 ];
		if( i % 2 == 0 ) dp[i] = min( dp[i], 1 + dp[ i / 2 ] );
		if( i % 3 == 0 ) dp[i] = min( dp[i], 1 + dp[ i / 3 ] );
	}

	return dp[n];
}

int data::minimum_steps_to_one_memo( int n )
{
	if( n == 1 ) return 0;
	if( memo[n] != NOT_KNOWN ) return memo[n];

	int minv = 1 + minimum_steps_to_one_memo( n - 1 );
	if( n % 2 == 0 ) minv = min( minv, 1 + minimum_steps_to_one_memo( n / 2 ) );
	if( n % 3 == 0 ) minv = min( minv, 1 + minimum_steps_to_one_memo( n / 3 ) );
	memo[n] = minv;

	return minv;
}

int main()
{
	data myData;
	myData.calc_minimum_steps_to_one();
	
	return 0;
}
