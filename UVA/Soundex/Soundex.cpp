#include <iostream>
#include <map>
using namespace std;

int main()
{
	map <char, char> mapping;
	mapping['B'] = '1';
	mapping['F'] = '1';
	mapping['P'] = '1';
	mapping['V'] = '1';

	mapping['C'] = '2';
	mapping['G'] = '2';
	mapping['J'] = '2';
	mapping['K'] = '2';
	mapping['Q'] = '2';
	mapping['S'] = '2';
	mapping['X'] = '2';
	mapping['Z'] = '2';

	mapping['T'] = '3';
	mapping['D'] = '3';

	mapping['L'] = '4';

	mapping['M'] = '5';
	mapping['N'] = '5';

	mapping['R'] = '6';

	mapping['A'] = '_';
	mapping['E'] = '_';
	mapping['I'] = '_';
	mapping['O'] = '_';
	mapping['U'] = '_';
	mapping['Y'] = '_';
	mapping['W'] = '_';
	mapping['H'] = '_';

	string word;
	while( cin >> word )
	{
		char last = '_';
		string encoded = "";

		for( int char_no = 0; char_no < word.size(); char_no++ )
			if( mapping[word[char_no]] != last )
			{
				if( mapping[word[char_no]] != '_' )
					encoded += mapping[word[char_no]];
				last = mapping[word[char_no]];
			}

		cout << encoded << endl;
	}

	return 0;
}
