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
    keypad[5] = "mno";
    keypad[6] = "pqr";
    keypad[7] = "stu";
    keypad[8] = "vwx";
    keypad[9] = "yz";
    keypad[0] = "";

    int phone_number = 52;
    generate_all_phone_numbers( phone_number, "", keypad );

    return 0;
}
