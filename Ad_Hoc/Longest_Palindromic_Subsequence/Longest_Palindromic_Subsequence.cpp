#include <iostream>
#include <vector>
using namespace std;

int lps( string sequence )
{
	vector <int> lps_length_temp( sequence.size() + 1, 0 );
	vector < vector <int> > lps_length( sequence.size() + 1, lps_length_temp );

	for( int i = 1; i <= sequence.size(); i++ )
		for( int j = 1; j <= sequence.size(); j++ )
		{
			if( sequence[i - 1] == sequence[sequence.size() - i] )
				lps_length[i][j] = 1 + lps_length[i - 1][j - 1];
			else
				lps_length[i][j] = max( lps_length[i -1][j], lps_length[i][j - 1] );
		}

	return lps_length[sequence.size()][sequence.size()];
}

int main()
{
	string sequence;
	cin >> sequence;

	cout << "The sequence is " << sequence << endl;
	cout << "The length of the longest palindromic subsequence is " << lps( sequence ) << endl;

	return 0;
}
