#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string word;
	vector <string> text1, text2;

	while( cin >> word && word != "#" )
		text1.push_back( word );

	while( cin >> word && word != "#" )
		text2.push_back( word );

	vector <int> lcs_tmp( text1.size() + 1, 0 );
	vector < vector <int> > length_of_lcs( text2.size() + 1, lcs_tmp );

	vector <string> s_tmp( text1.size() + 1, "" );
	vector < vector <string> > steps( text2.size() + 1, s_tmp );

	for( int i = 1; i <= text2.size(); i++ )
		for( int j = 1; j <= text1.size(); j++ )
		{
			if( text1[j - 1] == text2[i - 1] )
			{
				length_of_lcs[i][j] = 1 + length_of_lcs[i - 1][j - 1];
				steps[i][j] = "TAKE";
			}
			else if( length_of_lcs[i - 1][j]  > length_of_lcs[i][j - 1] )
			{
				length_of_lcs[i][j] = length_of_lcs[i - 1][j];
				steps[i][j] = "UP";
			}
			else
			{
				length_of_lcs[i][j] = length_of_lcs[i][j - 1];
				steps[i][j] = "LEFT";
			}
		}

	vector <string> longest_common_subsequence;
	int row = text2.size(), col = text1.size();

	while( row > 0 && col > 0 )
	{
		if( steps[row][col] == "TAKE" )
		{
			longest_common_subsequence.push_back( text2[row - 1] );
			row--, col--;
		}
		else if( steps[row][col] == "UP" ) row--;
		else col--;
	}

	for( int i = longest_common_subsequence.size() - 1; i >= 0; i-- )
	{
		cout << longest_common_subsequence[i];
		if( i != 0 ) cout << ' ';
	}
	cout << endl;

	return 0;
}
