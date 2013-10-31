#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool cmp( const string& s1, const string& s2 )
{
	if( s1.size() == s2.size() ) return s1 < s2;
	return s1.size() > s2.size();
}

int main()
{
	map <int, string> s_map;
	s_map[1] = "qaz";
	s_map[2] = "wsx";
	s_map[3] = "edc";
	s_map[4] = "rfvtgb";
	s_map[7] = "yhnujm";
	s_map[8] = "ik,";
	s_map[9] = "ol.";
	s_map[10] = "p;/";

	int num_bad_fingers, num_long_words;
	while( cin >> num_bad_fingers >> num_long_words )
	{
		map <char, bool> c_map;
		int bad_finger;

		for( int finger_no = 0; finger_no < num_bad_fingers; finger_no++ )
		{
			cin >> bad_finger;
			string bad_letters = s_map[bad_finger];

			for( int letter_no = 0; letter_no < bad_letters.size(); letter_no++ )
				c_map[bad_letters[letter_no]] = true;
		}

		vector <string> list_long_words;
		string word;
		int length_longest_words = -1;
		
		for( int word_no = 0; word_no < num_long_words; word_no++ )
		{
			bool can_type = true;

			cin >> word;
			for( int letter_no = 0; letter_no < word.size(); letter_no++ )
				if( c_map[word[letter_no]] == true )
					can_type = false;

			if( can_type )
			{
				list_long_words.push_back( word );
				int ws = word.size();
				length_longest_words = max( length_longest_words, ws );
			}
		}

		sort( list_long_words.begin(), list_long_words.end(), cmp );
		map <string, bool> word_list;
		
		int num_longest_words = 0;
		for( int i = 0; i < list_long_words.size(); i++ )
			if( list_long_words[i].size() == length_longest_words )
				num_longest_words++;

		cout << num_longest_words << endl;

		for( int i = 0; i < list_long_words.size(); i++ )
			if( list_long_words[i].size() == length_longest_words )
				if( word_list[list_long_words[i]] == 0 )
				{
					cout << list_long_words[i] << endl;
					word_list[list_long_words[i]] = 1;
				}

		list_long_words.clear();
		word_list.clear();
		c_map.clear();
	}

	return 0;
}
