#include <algorithm>
#include <iostream>
#include <map>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int scale_separation[] = { 2, 2, 1, 2, 2, 2 };

vector <string> union_strings( const vector <string>& list1, const vector <string>& list2 )
{
	if( list1.size() == 0 ) return list2;
	if( list2.size() == 0 ) return list1;

	set <string> string_occurrences;
	vector <string> unioned_strings;

	for( int i = 0; i < list1.size(); i++ )
		string_occurrences.insert( list1[i] );
	
	for( int i = 0; i < list2.size(); i++ )
		if( string_occurrences.find( list2[i] ) != string_occurrences.end() )
			unioned_strings.push_back( list2[i] );

	return unioned_strings;
}
	
int main()
{
	vector <string> list_notes;
	list_notes.push_back("C");
	list_notes.push_back("C#");
	list_notes.push_back("D");
	list_notes.push_back("D#");
	list_notes.push_back("E");
	list_notes.push_back("F");
	list_notes.push_back("F#");
	list_notes.push_back("G");
	list_notes.push_back("G#");
	list_notes.push_back("A");
	list_notes.push_back("A#");
	list_notes.push_back("B");

	map <string, vector <string> > notes_to_keys;
	for( int key = 0; key < list_notes.size(); key++ )
	{
		int i = key;
		for( int note_num = 0; note_num < 7; note_num++ )
		{
			notes_to_keys[list_notes[i]].push_back( list_notes[key] );
			i = ( i + scale_separation[note_num] ) % 12;
		}
	}

	vector <string> notes;
	string chars;
	while( getline( cin, chars ) && chars != "END" )
	{
		stringstream ss;
		for( int i = 0; i < chars.size(); i++ )
		{
			if( chars[i] == ' ' )
			{
				notes.push_back( ss.str() );
				ss.str("");
			}
			else ss << chars[i];
		}
		notes.push_back( ss.str() );

		vector <string> list_possible_keys;
		for( int curr_letter = 0; curr_letter < notes.size(); curr_letter++ )
			if( notes[curr_letter] != " " )
				list_possible_keys = union_strings( list_possible_keys, notes_to_keys[notes[curr_letter]] );

		vector <string>::iterator vt = list_possible_keys.begin();
		while( vt != list_possible_keys.end() )
		{
			cout << *vt << ' ';
			vt++;
		}
		cout << endl;

		notes.clear();
		list_possible_keys.clear();
	}

	return 0;
}
