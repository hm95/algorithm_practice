#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector <string> list_words;
    set <string> dictionary;
    string str;

    while( cin >> str && str != "XXXXXX" )
        dictionary.insert( str );

    while( cin >> str && str != "XXXXXX" )
        list_words.push_back( str );

    for( int i = 0; i < list_words.size(); i++ )
    {
        bool at_least_one = false;
        sort( list_words[i].begin(), list_words[i].end() );
        do {
            if( dictionary.find( list_words[i] ) != dictionary.end() )
            {
                at_least_one = true;
                cout << list_words[i] << endl;
            }
        } while( next_permutation( list_words[i].begin(), list_words[i].end() ) );

        if( !at_least_one ) cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    
    return 0; 
}
