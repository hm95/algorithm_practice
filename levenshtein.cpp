#include <iostream>
#include <vector>
using namespace std;

int levenshtein( string a, string b ) 
{
    vector <int> tmp( a.size() + 1, 0 );
    vector < vector <int> > lev( b.size() + 1, tmp );

    for( int i = 0; i <= a.size(); i++ )
        lev[0][i] = i;

    for( int i = 0; i <= b.size(); i++ )
        lev[i][0] = i;

    for( int i = 1; i <= b.size(); i++ )
        for( int j = 1; j <= a.size(); j++ )
        {
            if( a[j - 1] == b[i - 1] )
                lev[i][j] = min( lev[i - 1][j - 1], 1 + min( lev[i - 1][j], lev[i][j - 1] ) );
            else
                lev[i][j] = 1 + min( lev[i - 1][j - 1], min( lev[i - 1][j], lev[i][j - 1] ) );
        }

    return lev[b.size()][a.size()];
}

int main()
{
    cout << "Levenshtein of " << levenshtein( "shalt", "should" ) << endl;

    return 0;
}
