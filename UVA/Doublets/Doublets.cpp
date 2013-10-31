#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct pos
{
	string value;
	int cost;
};

bool is_doublet( string a, string b )
{
	if( a.size() != b.size() ) return false;

	bool num_diff = 0;
	for( int i = 0; i < a.size(); i++ )
		if( a[i] != b[i] )
			num_diff++;

	return num_diff == 1;
}

void calculate_optimal_path( string a, string b, map <string, bool> dictionary )
{
	map <string, bool> visited;
	visited[a] = true;

	queue < pair <string, string> > q;
	q.push( make_pair( a, "" ) );

	bool done = false;
	string steps;

	while( !q.empty() )
	{
		pair <string, string> cur = q.front();
		q.pop();

		if( cur.first == b )
		{
			done = true;
			steps = cur.second;
			break;
		}

		for( int i = 0; i < cur.first.size(); i++ )
		{
			string tmp_word = cur.first;
			for( int j = 0; j < 26; j++ )
			{
				int d = cur.first[i] - 'a';
				d = ( d + j ) % 26;
				char c = d + 'a';
				tmp_word[i] = c;

				if( !visited[tmp_word] && dictionary[tmp_word] && is_doublet( cur.first, tmp_word ) )
				{
					visited[tmp_word] = true;
					q.push( make_pair( tmp_word, cur.second + " " + cur.first ) );
				}
			}
		}
	}

	if( !done ) cout << "No solution." << endl << endl;
	else
	{
		string val;
		istringstream iss( steps );

		while( iss >> val )
			cout << val << endl;
		cout << b << endl << endl;
	}
}

int main()
{
	string word, a, b;
	map <string, bool> dictionary;

	while( getline( cin, word ) && word != "" )
		dictionary[word] = true;
	
	while( getline( cin, word ) )
	{
		istringstream iss( word );
		iss >> a >> b;

		if( !dictionary[a] || !dictionary[b] ) cout << "No solution." << endl << endl;
		else calculate_optimal_path( a, b, dictionary );
	}

	return 0;
}
