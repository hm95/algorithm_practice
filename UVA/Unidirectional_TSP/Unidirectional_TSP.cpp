#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
    int num_rows, num_cols;
    while( cin >> num_rows >> num_cols )
    {
        map < pair<int, int>, vector <int> > path;
        vector <int> row_tmp( num_cols, 0 );
        vector < vector <int> > matrix( num_rows, row_tmp ), min_weights = matrix;

        for( int i = 0; i < num_rows; i++ )
            for( int j = 0; j < num_cols; j++ )
                cin >> matrix[i][j];

        for( int row = 0; row < num_rows; row++ )
        {
            min_weights[row][0] = matrix[row][0];
            path[ make_pair( row, 0 ) ].push_back( row );
        }

        for( int j = 1; j < num_cols; j++ )
        {
            for( int i = 0; i < num_rows; i++ )
            {
                if( i == 0 ) min_weights[i][j] = matrix[i][j] + min( min_weights[i][j - 1] , min( min_weights[num_rows - 1][j - 1], min_weights[i + 1][j - 1] ) );
                else if( i == num_rows - 1 ) min_weights[i][j] = matrix[i][j] + min( min_weights[i][j - 1] , min( min_weights[i - 1][j - 1], min_weights[0][j - 1] ) );
                else min_weights[i][j] = matrix[i][j] + min( min_weights[i][j - 1] , min( min_weights[i - 1][j - 1], min_weights[i + 1][j - 1] ) );
            }
        }

        int min_weight = INFINITY;
        for( int row = 0; row < num_rows; row++ )
            min_weight = min( min_weight, min_weights[row][num_cols - 1] );

        cout << "The path of minimum weight has a value of " << min_weight << endl;
    }

    return 0;
}
