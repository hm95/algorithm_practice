#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

struct pos
{
	int row, col;
	bool has_one_left;
	char value;
};

int row_direction[] = { 1, -1, 0, 0 };
int column_direction[] = { 0, 0, 1, -1 };

bool is_in_range( int row, int col, int num_rows, int num_cols )
{
	if( row >= 0 && col >= 0 && row < num_rows && col < num_cols ) return true;
	return false;
}

void check_for_winner( int row, int col, vector < vector <char> > board, bool& white_winning_path, bool& black_winning_apath, bool& white_one_step_away, bool& black_one_step_away )
{
	pos root;
	root.row = row, root.col = col, root.has_one_left = true, root.value = board[row][col];

	stack <pos> stk;
	stk.push( root );

	map < pair < pair <int, int>, bool > , bool > visited;
	visited[ make_pair( make_pair( root.row, root.col ), root.has_one_left ) ] = true;

	while( !stk.empty() )
	{
		pos cur = stk.top();
		stk.pop();

		if( root.value == 'W' && cur.col == board.size() - 1 )
		{
			if( cur.has_one_left )
			{
				white_winning_path = true;
				return;
			}
			else white_one_step_away = true;
		}
		if( root.value == 'B' && cur.row == board.size() - 1 )
		{
			if( cur.has_one_left )
			{
				black_winning_apath = true;
				return;
			}
			else black_one_step_away = true;
		}

		for( int i = 0; i < 4; i++ )
		{
			pos tmp;
			tmp.row = cur.row + row_direction[i];
			tmp.col = cur.col + column_direction[i];
			tmp.has_one_left = cur.has_one_left;

			if( is_in_range( tmp.row, tmp.col, board.size(), board.size() ) && board[tmp.row][tmp.col] == root.value && !visited[ make_pair ( make_pair( tmp.row, tmp.col ), tmp.has_one_left ) ] )
			{
				tmp.value = board[tmp.row][tmp.col];
				visited[ make_pair( make_pair( tmp.row, tmp.col ), tmp.has_one_left ) ] = true;
				stk.push( tmp );
			}
			else if( is_in_range( tmp.row, tmp.col, board.size(), board.size() ) && board[tmp.row][tmp.col] == 'U' && tmp.has_one_left && !visited[ make_pair ( make_pair( tmp.row, tmp.col ), false ) ] )
			{
				tmp.value = board[tmp.row][tmp.col], tmp.has_one_left = false;
				visited[ make_pair( make_pair( tmp.row, tmp.col ), tmp.has_one_left ) ] = true;
				stk.push( tmp );
			}
		}
	}
}

int main()
{
	int board_size;
	while( cin >> board_size && board_size != 0 )
	{
		vector <char> board_temp( board_size );
		vector < vector <char> > board( board_size, board_temp );

		string line;
		for( int row = 0; row < board_size; row++ )
		{
			cin >> line;
			for( int col = 0; col < board_size; col++ )
				board[row][col] = line[col];
		}

		bool white_winning_path = false, black_winning_apath = false, white_one_step_away = false, black_one_step_away = false;

		for( int row = 0; row < board_size; row++ )
			if( board[row][0] == 'W' )
				check_for_winner( row, 0, board, white_winning_path, black_winning_apath, white_one_step_away, black_one_step_away );

		for( int col = 0; col < board_size; col++ )
			if( board[0][col] == 'B' )
				check_for_winner( 0, col, board, white_winning_path, black_winning_apath, white_one_step_away, black_one_step_away );

		if( white_winning_path ) cout << "White has a winning path." << endl;
		else if( black_winning_apath ) cout << "Black has a winning path." << endl;
		else if( white_one_step_away ) cout << "White can win in one move." << endl;
		else if( black_one_step_away ) cout << "Black can win in one move." << endl;
		else cout << "There is no winning path." << endl;
	}

	return 0;
}
