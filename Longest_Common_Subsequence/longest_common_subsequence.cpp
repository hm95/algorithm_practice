#include <iostream>
#include <vector>
using namespace std;

int lcs( const string& s1, const string& s2 )
{
    vector <int> temp( s2.size() + 1, 0 );
    vector < vector <int> > lcs_len( s1.size() + 1, temp );

    for( int i = 1; i <= s1.size(); i++ )
        for( int j = 1; j <= s2.size(); j++ )
        {
            if( s1[i - 1] == s2[j - 1] )
                lcs_len[i][j] = 1 + lcs_len[i - 1][j - 1];
            else
                lcs_len[i][j] = max( lcs_len[i - 1][j - 1], max( lcs_len[i - 1][j], lcs_len[i][j - 1] ) );
        }

    return lcs_len[s1.size()][s2.size()];
}

int main()
{
    string s1 = "abcde", s2 = "ace";
    cout << "The length of the longest common subsequence between " << s1 << " and " << s2 << " is " << lcs( s1, s2 ) << endl;

    return 0; 
}
