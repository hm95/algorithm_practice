#include <iostream>
using namespace std;

// An 8 x 8 chessboard
const int BOARD_SIZE = 8;

class ChessBoard
{
	public:
		ChessBoard();
		void find_all_solutions();
		void initialize_board();
		void print_solution();
		void put_queen_in_row( int row );

	private:
		bool available;
		typedef bool* bool_ptr;
		bool_ptr column, left_diag, right_diag;
		int* queen_row_values, offset, num_solutions;
};

ChessBoard::ChessBoard()
{
	available = true;
	offset = BOARD_SIZE - 1;

	initialize_board();
}

void ChessBoard::find_all_solutions()
{
	put_queen_in_row(0);

	cout << num_solutions << " solutions were found." << endl;
}

void ChessBoard::initialize_board()
{
	num_solutions = 0;

	column = new bool[BOARD_SIZE];
	left_diag = new bool[ 2 * BOARD_SIZE - 1 ];
	right_diag = new bool[ 2 * BOARD_SIZE - 1 ];
	queen_row_values = new int[BOARD_SIZE];

	for( int i = 0; i < BOARD_SIZE; i++ )
	{
		queen_row_values[i] = -1;
		column[i] = true;
	}

	for( int i = 0; i < 2 * BOARD_SIZE - 1; i++ )
		left_diag[i] = right_diag[i] = true;
}

void ChessBoard::print_solution()
{
	num_solutions++;

	cout << "Solution " << num_solutions << endl;
	for( int col = 0; col < BOARD_SIZE; col++ )
	{
		for( int row = 0; row < BOARD_SIZE; row++ )
		{
			if( queen_row_values[col] == row ) cout << "Q";
			else cout << "[]";
		}
		cout << endl;
	}
	cout << endl;

}

void ChessBoard::put_queen_in_row( int row )
{
	for( int col = 0; col < BOARD_SIZE; col++ )
	{
		if( column[col] == available && left_diag[ row + col ] == available && right_diag[ row - col + offset ] == available )
		{
			queen_row_values[row] = col;
			column[col] = !available;
			left_diag[ row + col ] = !available;
			right_diag[ row - col + offset ] = !available;

			if( row < BOARD_SIZE - 1 ) put_queen_in_row( row + 1 );
			else print_solution();

			column[col] = available;
			left_diag[ row + col ] = available;
			right_diag[ row - col + offset ] = available;
		}
	}
}

int main()
{
	ChessBoard cb;
	cb.find_all_solutions();

	return 0;
}
