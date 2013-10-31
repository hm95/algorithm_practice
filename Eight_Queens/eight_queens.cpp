#include <iostream>
#include <vector>
using namespace std;

vector <bool> cols( 8, true );
vector <bool> left_diag( 15, true ); 
vector <bool> right_diag( 15, true );

const int OFFSET = 7;

void put_queen_in_row( const int& row )
{
    for( int col = 0; col < 8; col++ )
        if( cols[col] && left_diag[row + col] && right_diag[row - col + OFFSET] )
        {
            cols[row] = false;
            left_diag[row + col] = false;
            right_diag[row - col + OFFSET] = false;

            if( col == 7 ) cout << "Solution!" << endl;
            else put_queen_in_row( row + 1 );

            cols[row] = true;
            left_diag[row + col] = true;
            right_diag[row - col + OFFSET] = true;
        }
}

int main()
{
    put_queen_in_row( 0 );

    return 0; 
}
