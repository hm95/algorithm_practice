#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int N = 12, M = 10;
const int LEFT = -1, UP = -2, ADD = -3;

class data
{
	private:
		char S1[N];
		char S2[M];
		int LCS[N + 1][M + 1];
		int ptrs[N + 1][M + 1];
		
	public:
		data();
		void calc_longest_common_subsequence();
		vector <char> get_longest_common_subsequence();
		int longest_common_subsequence();
		void print_sequences();
};

data::data()
{
	for( int i = 0; i < N; i++ )
		S1[i] = ( rand() % 4 ) + 65;

	for( int i = 0; i < M; i++ )
		S2[i] = ( rand() % 4 ) + 65;

	for( int i = 0; i <= N; i++ )
	{
		LCS[i][0] = 0;
		ptrs[i][0] = UP;
	}

	for( int i = 0; i <= M; i++ )
	{
		LCS[0][i] = 0;
		ptrs[0][i] = LEFT;
	}
}

void data::calc_longest_common_subsequence()
{
	print_sequences();
	cout << "The length of the longest common subsequence, S3, is " << longest_common_subsequence() << endl;

	vector <char> lcs = get_longest_common_subsequence();
	reverse( lcs.begin(), lcs.end() );

	cout << "One longest common subsequence is '";
	for( int i = 0; i < lcs.size(); i++ )
		cout << lcs[i];
	cout << "'" << endl;
}

vector <char> data::get_longest_common_subsequence()
{
	vector <char> lcs;
	int i = N, j = M;

	while( i != 0 && j != 0 )
	{
		if( ptrs[i][j] == ADD )
		{
			lcs.push_back( S1[i - 1] );
			i--;
			j--;
		}
		else if( ptrs[i][j] == UP ) i--;
		else j--;
	}

	return lcs;
}

int data::longest_common_subsequence()
{
	int max_length = -1;

	for( int i = 1; i <= N; i++ )
	{
		for( int j = 1; j <= M; j++ )
		{
			if( S1[i - 1] == S2[j - 1] )
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				ptrs[i][j] = ADD;
			}
			else if( LCS[i - 1][j] > LCS[i][j - 1] )
			{
				LCS[i][j] = LCS[i - 1][j];
				ptrs[i][j] = UP;
			}
			else
			{
				LCS[i][j] = LCS[i][j - 1];
				ptrs[i][j] = LEFT;
			}
			max_length = max( max_length, LCS[i][j] );
		}
	}

	return max_length;
}

void data::print_sequences()
{
	cout << "The sequence, S1, is " << endl;
	for( int i = 0; i < N; i++ )
		cout << S1[i] << ' ';
	cout << endl;

	cout << "The sequence, S2, is " << endl;
	for( int i = 0; i < M; i++ )
		cout << S2[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;
	myData.calc_longest_common_subsequence();
	
	return 0;
}
