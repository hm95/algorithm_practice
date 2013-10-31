#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 100;
const int MAX_VAL = 10;
const int NOT_KNOWN = -1;

class data
{
	private:
		int dp[MAX_NUM_ELEMENTS];
		int S[MAX_NUM_ELEMENTS];
		
	public:
		data();
		void calc_longest_increasing_subsequence();
		int longest_increasing_subsequence();
		void print_sequence();
};

void data::calc_longest_increasing_subsequence()
{
	cout << "The original sequence, S, is " << endl;
	print_sequence();

	cout << "The length of the longest increasing subsequence, S', is " << longest_increasing_subsequence() << endl;
}

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		S[i] = rand() % MAX_VAL;
}

int data::longest_increasing_subsequence()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
	{
		dp[i] = 1;
		for( int j = 0; j < i; j++ )
		{
			if( S[i] > S[j] )
				dp[i] = max( dp[i], dp[j] + 1 );
		}
	}
		
	int maxv = -1;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		maxv = max( maxv, dp[i] );

	return maxv; 
}

void data::print_sequence()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << S[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;
	myData.calc_longest_increasing_subsequence();
	
	return 0;
}
