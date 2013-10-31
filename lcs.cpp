#include <iostream>
#include <vector>
using namespace std;

int lcs( string a, string b )
{
    vector <int> tmp( a.size() + 1, 0 );
    vector < vector <int> > lev( b.size() + 1, tmp );

    for( int i = 1; i <= b.size(); i++ )
        for( int j = 1; j <= a.size(); j++ )
        {
            if( a[j - 1] == b[i - 1] )
                lev[i][j] = 1 + lev[i - 1][j - 1];
            else
                lev[i][j] = max( lev[i - 1][j], lev[i][j - 1] );
        }

    return lev[b.size()][a.size()];
}

int main()
{
    cout << lcs( "hello", "jiggello" ) << endl;

    return 0;
}
