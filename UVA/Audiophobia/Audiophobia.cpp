#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
    int case_num = 1, num_crossings, num_streets, num_queries;
    while( cin >> num_crossings >> num_streets >> num_queries )
    {
        if( num_crossings == 0 ) break;

        if( case_num != 1 ) cout << endl;

        vector <int> temp( num_crossings, INFINITY );
        vector < vector <int> > crossings_map( num_crossings, temp );

        for( int i = 0; i < num_streets; i++ )
        {
            int start, end, sound_level;
            cin >> start >> end >> sound_level;
            start--, end--;

            crossings_map[start][end] = sound_level;
            crossings_map[end][start] = sound_level;
        }

        for( int k = 0; k < num_crossings; k++ )
            for( int i = 0; i < num_crossings; i++ )
                for( int j = 0; j < num_crossings; j++ )
                    crossings_map[i][j] = min( crossings_map[i][j], max( crossings_map[i][k], crossings_map[k][j] ) );

        cout << "Case #" << case_num++ << endl;
        for( int i = 0; i < num_queries; i++ )
        {
            int start, end;
            cin >> start >> end;
            start--, end--;

            if( crossings_map[start][end] == INFINITY ) cout << "no path" << endl;
            else cout << crossings_map[start][end] << endl;
        }
    }

    return 0;
}
