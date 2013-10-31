#include <iostream>
#include <sstream>
using namespace std;

string rev( string str )
{
    string temp, res = "";
    stringstream iss( str );

    while( iss >> temp )
    {
        for( int i = temp.size() - 1; i >= 0; i-- )
            res += temp[i];

        res += ' ';
    }

    return res;
}

int main()
{
    string str = "";
    getline( cin, str );

    cout << "The original string is " << str << endl;
    cout << "The reversed string is " << rev( str ) << endl;

    return 0;
}
