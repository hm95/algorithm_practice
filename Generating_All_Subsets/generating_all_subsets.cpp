#include <iostream>
using namespace std;

void generate_all_subsets( int index, string str, string orig )
{
    if( str != "" )
        cout << str << endl;

    while( index < orig.size() )
    {
        generate_all_subsets( index + 1, str + orig[index], orig );
        index++;
    }
}

int main()
{
    string s = "1234";
    generate_all_subsets( 0, "", s );

    return 0;
}
