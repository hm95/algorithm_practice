#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int INF = 9e8;

int rowdir[8] = { -2, -2, 2, 2, 1, 1, -1, -1 };
int coldir[8] = { -1, 1, -1, 1, 2, -2, 2, -2 };

struct pos
{
	string config;
	int dist;
	int x_co, y_co;
};

bool is_ok( int row, int col )
{
	if( row >= 0 && row <= 4 && col >= 0 && col <= 4 ) return true;
	return false;
}

string switch_chars( string orig, int original_x_val, int original_y_val, int new_x_val, int new_y_val )
{
	string switched_chars = orig;

	char covered_char = orig[ 5 * new_x_val + new_y_val ];
	switched_chars[ 5 * new_x_val + new_y_val ] = 'X';
	switched_chars[ 5 * original_x_val + original_y_val ] = covered_char;

	return switched_chars;
}

int main()
{
	int num_test_cases;
	cin >> num_test_cases;
	string first_string;
	getline( cin, first_string );

	string ending_config = "BBBBBWBBBBWWXBBWWWWBWWWWW";

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		vector < vector <char> > board;

		vector <char> t;
		for( int i = 0; i < 5; i++ )
			t.push_back( '0' );

		for( int i = 0; i < 5; i++ )
			board.push_back( t );

		char curr_char;
		int x_val, y_val;
		for( int rows = 0; rows < 5; rows++ )
		{
			string temp;
			getline( cin, temp );
			for( int i = 0; i < 5; i++ )
			{
				if( temp[i] == '1' ) board[rows][i] = 'B';
				else if( temp[i] == '0' ) board[rows][i] = 'W';
				else
				{
					x_val = rows;
					y_val = i;
					board[rows][i] = 'X';
				}
			}
		}

		string starting_config = "";
		for( int rows = 0; rows < 5; rows++ )
			for( int cols = 0; cols < 5; cols++ )
				starting_config += board[rows][cols];

		map <string, bool> visited;
		visited[starting_config] = true;
	
		pos root;
		root.config = starting_config;
		root.dist = 0;
		root.x_co = x_val;
		root.y_co = y_val;

		queue <pos> q;
		q.push( root );

		int minv = INF;
		while( !q.empty() )
		{
			pos tmp = q.front();
			q.pop();
			if( tmp.dist > 10 ) break;

			if( tmp.config == ending_config )
			{
				minv = tmp.dist;
				break;
			}

			for( int i = 0; i < 8; i++ )
			{
				pos curr;
				curr.dist = 1 + tmp.dist;
				curr.x_co = tmp.x_co + rowdir[i];
				curr.y_co = tmp.y_co + coldir[i];

				if( is_ok( curr.x_co, curr.y_co ) )
				{
					curr.config = switch_chars( tmp.config, tmp.x_co, tmp.y_co, curr.x_co, curr.y_co );

					if( !visited[curr.config] )
					{
						visited[curr.config] = true;
						q.push( curr );
					}
				}
			}
		}

		if( minv == INF ) cout << "Unsolvable in less than 11 move(s)." << endl;
		else cout << "Solvable in " << minv << " move(s)." << endl;

		visited.clear();
		board.clear();
	}

	return 0;
}
