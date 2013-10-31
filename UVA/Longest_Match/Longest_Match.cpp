#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int lcs( vector <string> s1, vector <string> s2 )
{
    vector <int> g_tmp( s1.size() + 1, 0 );
    vector < vector <int> > graph( s2.size() + 1, g_tmp );

    for( int i = 1; i <= s2.size(); i++ )
        for( int j = 1; j <= s1.size(); j++ )
        {
            if( s1[j - 1] == s2[i - 1] )
                graph[i][j] = 1 + graph[i - 1][j - 1];
            else
                graph[i][j] = max( graph[i - 1][j], graph[i][j - 1] );
        }

    return graph[s2.size()][s1.size()];
}

int main()
{
    int test_case_number = 1;
    string first, second;

    while( getline( cin, first ) && getline( cin, second ) )
    {
        cout << test_case_number << ". ";
        test_case_number++;

        if( first == "" || second == "" )
        {
            cout << "Blank!" << endl;
            continue;
        }

        for( int i = 0; i < first.size(); i++ )
            if( !isalnum( first[i] ) )
                first[i] = ' ';

        for( int i = 0; i < second.size(); i++ )
            if( !isalnum( second[i]) )
                second[i] = ' ';

        vector <string> s1, s2;
        istringstream iss( first ), bss( second );
        string tmp;

        while( iss >> tmp )
		s1.push_back( tmp );

        while( bss >> tmp )
            s2.push_back( tmp );

        cout << "Length of longest match: " << lcs( s1, s2 ) << endl;
    }

    return 0;
}
