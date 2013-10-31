#include <iostream>
#include <map>
#include <vector>
using namespace std;

void generate_all_phone_numbers( int phone_number, vector <char> str, map <int, string> keypad )
{
	if( phone_number == 0 )
	{
		for( int i = 0; i < str.size(); i++ )
			cout << str[i] << " ";
		cout << endl;
		return;
	}

	string letters = keypad[phone_number % 10];
	phone_number /= 10;
	if( letters == "" ) generate_all_phone_numbers( phone_number, str, keypad );

	for( int i = 0; i < letters.size(); i++ )
	{
		vector <char> tmp;
		tmp.push_back( letters[i] );
		for( int i = 0; i < str.size(); i++ )
			tmp.push_back( str[i] );

		generate_all_phone_numbers( phone_number, tmp, keypad );
	}
}

int main()
{
	vector <char> str;
	map <int, string> keypad;
	keypad[1] = "abc";
	keypad[2] = "def";
	keypad[3] = "ghi";
	keypad[4] = "jkl";
	keypad[6] = "mno";
	keypad[7] = "pqrs";
	keypad[8] = "tuv";
	keypad[9] = "wxyz";

	int phone_number = 101;
	generate_all_phone_numbers( phone_number, str, keypad );

	return 0;
}
