#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_dir[] = { 1, -1, 0, 0 };
int col_dir[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col )
{
	if( row >= 0 && col >= 0 && row < 9 && col < 9 ) return true;
	return false;
}

void colour( int row, int col, vector < vector <string> >& board, vector < vector <bool> >& visited )
{
	visited[row][col] = true;
	string type = board[row][col];

	stack < pair <int, int> > stk;
	stk.push( make_pair( row, col ) );

	while( !stk.empty() )
	{
		pair <int, int> cur = stk.top();
		stk.pop();

		for( int i = 0; i < 4; i++ )
		{
			pair <int, int> tmp;
			tmp.first = cur.first + row_dir[i];
			tmp.second = cur.second + col_dir[i];

			if( is_in_range( tmp.first, tmp.second ) && !visited[tmp.first][tmp.second] && ( board[tmp.first][tmp.second] == type || board[tmp.first][tmp.second] == "." ) )
			{
				visited[tmp.first][tmp.second] = true;
				stk.push( make_pair( tmp.first, tmp.second ) );
			}
		}
	}
}

int main()
{
	int num_go_boards;
	cin >> num_go_boards;

	for( int go_board_num = 0; go_board_num < num_go_boards; go_board_num++ )
	{
		vector <string> b_tmp( 9, "." );
		vector < vector <string> > board( 9, b_tmp );

		vector <bool> v_tmp( 9, false );
		vector < vector <bool> > visited_black( 9, v_tmp );
		vector < vector <bool> > visited_white( 9, v_tmp );

		string line;
		for( int row = 0; row < 9; row++ )
		{
			cin >> line;
			for( int col = 0; col < 9; col++ )
				board[row][col] = line[col];
		}

		for( int row = 0; row < 9; row++ )
			for( int col = 0; col < 9; col++ )
				if( !visited_white[row][col] && board[row][col] == "O" )
					colour( row, col, board, visited_white );

		for( int row = 0; row < 9; row++ )
			for( int col = 0; col < 9; col++ )
				if( !visited_black[row][col] && board[row][col] == "X" )
					colour( row, col, board, visited_black );

		int num_white = 0, num_black = 0;
		for( int row = 0; row < 9; row++ )
			for( int col = 0; col < 9; col++ )
			{
				if( visited_white[row][col] && !visited_black[row][col] ) num_white++;
				if( !visited_white[row][col] && visited_black[row][col] ) num_black++;
			}
				
		cout << "Black " << num_black << " White " << num_white << endl;
	}

	return 0;
}
