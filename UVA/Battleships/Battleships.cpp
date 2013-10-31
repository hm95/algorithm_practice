#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int row_dir[] = { 1, -1, 0, 0 };
int col_dir[] = { 0, 0, 1, -1 };

bool is_in_range( int temp_row, int temp_col, const int& num_rows, const int& num_cols )
{
    if( temp_row >= 0 && temp_row < num_rows && temp_col >= 0 && temp_col < num_cols ) return true;
    return false;
}

void fill( vector < vector <char> >& graph, int row, int col, const int& num_rows, const int& num_cols )
{
    stack < pair <int, int> > stk;
    stk.push( make_pair( row, col ) );

    while( !stk.empty() )
    {
        int cur_row = stk.top().first;
        int cur_col = stk.top().second;
        stk.pop();

        for( int i = 0; i < 4; i++ )
        {
            int temp_row = cur_row + row_dir[i];
            int temp_col = cur_col + col_dir[i];

            if( is_in_range( temp_row, temp_col, num_rows, num_cols ) && ( graph[temp_row][temp_col] == '@' || graph[temp_row][temp_col] == 'x' ) )
            {
                graph[temp_row][temp_col] = '.';
                stk.push( make_pair( temp_row, temp_col ) );
            }
        }
    }
}

int main()
{
    int num_test_cases;
    cin >> num_test_cases;

    for( int test_case_no = 1; test_case_no <= num_test_cases; test_case_no++ )
    {
        int size;
        cin >> size;

        vector <char> g_tmp( size );
        vector < vector <char> > graph( size, g_tmp );

        string line;
        for( int row = 0; row < size; row++ )
        {
            cin >> line;
            for( int col = 0; col < size; col++ )
                graph[row][col] = line[col];
        }

        int num_living_ships = 0;
        for( int row = 0; row < size; row++ )
            for( int col = 0; col < size; col++ )
                if( graph[row][col] == 'x' )
                {
                    num_living_ships++;
                    fill( graph, row, col, size, size );
                }

        cout << "Case " << test_case_no << ": " << num_living_ships << endl;
    }

    return 0;
}
