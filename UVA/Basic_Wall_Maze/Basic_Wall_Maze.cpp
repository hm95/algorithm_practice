#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map <int, string> mapping;

struct pos
{
    int row, col;
    string steps;
};

int row_dir[] = { 0, 0, 1, -1 };
int col_dir[] = { -1, 1, 0, 0 };

vector <bool> g_tmp_dir( 4, true );
vector < vector <bool> > g_tmp_col( 7, g_tmp_dir );
vector < vector < vector <bool> > > graph( 7, g_tmp_col );

vector <bool> v_tmp( 7, false );
vector < vector <bool> > visited( 7, v_tmp );

bool is_in_range( int row, int col )
{
    if( row >= 1 && col >= 1 && row <= 6 && col <= 6 ) return true;
    return false;
}

int main()
{
    mapping[0] = "N";
    mapping[1] = "S";
    mapping[2] = "E";
    mapping[3] = "W";

    int starting_row, starting_col, ending_row, ending_col;
    while( cin >> starting_row >> starting_col >> ending_row >> ending_col )
    {
         if( starting_row == 0 && starting_col == 0 ) break;

        for( int i = 0; i <= 6; i++ )
            for( int j = 0; j <= 6; j++ )
                for( int k = 0; k < 4; k++ )
                {
                    graph[i][j][k] = true;
                    visited[i][j] = false;
                }

        int x1, y1, x2, y2;
        for( int line_number = 0; line_number < 3; line_number++ )
        {
            cin >> x1 >> y1 >> x2 >> y2;

            if( x1 == x2 )
            {
                for( int col = y1 + 1; col <= y2; col++ )
                {
                    graph[x1][col][2] = false;
                    if( x1 + 1 <= 6 )
                        graph[x1 + 1][col][3] = false;
                }
            }
            else
            {
                for( int row = x1 + 1; row <= x2; row++ )
                {
                    graph[row][y1][1] = false;
                    if( y1 + 1 <= 6 )
                        graph[row][y1 + 1][0] = false;
                }
            }
        }

        pos root;
        root.row = starting_row, root.col = starting_col, root.steps = "";

        string optimal_path;
        visited[root.row][root.col] = true;

        queue <pos> q;
        q.push( root );

        while( !q.empty() )
        {
            pos cur = q.front();
            q.pop();

            if( cur.row == ending_row && cur.col == ending_col )
            {
                optimal_path = cur.steps;
                break;
            }

            for( int step_dir = 0; step_dir < 4; step_dir++ )
            {
                pos tmp;
                tmp.row = cur.row + row_dir[step_dir];
                tmp.col = cur.col + col_dir[step_dir];
                tmp.steps = cur.steps +  mapping[step_dir];

                if( is_in_range( tmp.row, tmp.col ) && !visited[tmp.row][tmp.col] && graph[cur.row][cur.col][step_dir] )
                {
                    visited[tmp.row][tmp.col] = true;
                    q.push( tmp );
                }
            }
        }

        cout << optimal_path << endl;
    }

    return 0;
}
