#include <iostream>
#include <vector>
using namespace std;

int get_lcs( const string& s1, const string& s2 )
{
    vector <int> temp( s2.size() + 1, 0 );
    vector < vector <int> > lcs( s1.size() + 1, temp );

    for( int i = 1; i <= s1.size(); i++ )
        for( int j = 1; j <= s2.size(); j++ )
        {
            if( s1[i - 1] == s2[j - 1] )
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max( lcs[i - 1][j - 1], max( lcs[i - 1][j], lcs[i][j - 1] ) );
        }

    return lcs[s1.size()][s2.size()];
}

int get_length_longest_palindromic_subsequence( const string& s1 )
{
    string s = s1, s2 = s1;
    reverse( s.begin(), s.end() );

    return get_lcs( s, s2 );
}

int main()
{
    string s1 = "abchjba";
    cout << "The length of the longest palindromic subsequence in " << s1 << " is " << get_length_longest_palindromic_subsequence( s1 ) << endl;

    return 0; 
}
