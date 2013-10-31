#include <iostream>
#include <map>
using namespace std;

void generate_all_phone_numbers( int phone_number, string str, map <int, string> keypad )
{
    if( phone_number == 0 )
    {
        cout << str << endl;
        return;
    }

    if( keypad[phone_number % 10].size() == 0 )
        generate_all_phone_numbers( phone_number / 10, str, keypad );

    for( int i = 0; i < keypad[phone_number % 10].size(); i++ )
        generate_all_phone_numbers( phone_number / 10, keypad[phone_number % 10][i] + str, keypad );
}

int main()
{
    map <int, string> keypad;
    keypad[1] = "abc";
    keypad[2] = "def";
    keypad[3] = "ghi";
    keypad[4] = "jkl";
    keypad[5] = "mnop";
    keypad[7] = "qrs";
    keypad[8] = "tuv";
    keypad[9] = "wxyz";

    int phone_number = 638;
    generate_all_phone_numbers( phone_number, "", keypad );

    return 0;
}
