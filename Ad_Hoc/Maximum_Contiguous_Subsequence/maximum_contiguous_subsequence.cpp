#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 10;
const int MAX_VAL = 10;
const int NEGATIVE_INFINITY = -9e8;

class data
{
	private:
		int S[MAX_NUM_ELEMENTS];
		int dp[MAX_NUM_ELEMENTS];
		
	public:
		data();
		void calc_maximum_contiguous_subsequence();
		int maximum_contiguous_subsequence();
		void print_sequence();
};

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		S[i] = 10 * rand() % ( 2 * MAX_VAL ) - MAX_VAL;
}

void data::calc_maximum_contiguous_subsequence()
{
	print_sequence();
	cout << "The sum of the maximum contiguous subsequence is " << maximum_contiguous_subsequence() << endl;
}

int data::maximum_contiguous_subsequence()
{
	dp[0] = S[0];
	int maxv = NEGATIVE_INFINITY;

	for( int i = 1; i < MAX_NUM_ELEMENTS; i++ )
	{
		dp[i] = max( dp[i - 1] + S[i], S[i] );
		maxv = max( maxv, dp[i] );
	}

	return maxv;
}

void data::print_sequence()
{
	cout << "The sequence is " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << S[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;
	myData.calc_maximum_contiguous_subsequence();
	
	return 0;
}
