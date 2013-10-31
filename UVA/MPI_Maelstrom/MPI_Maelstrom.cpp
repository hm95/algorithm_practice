#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int INFINITY = 9e8;

int main()
{
	int N;
	cin >> N; 

	vector <int> g_tmp( N, 0 );
	vector < vector <int> > graph( N, g_tmp );

	int row = 1, col = 0;
	string val;
	for( int row = 1; row < N; row++ )
		for( int col = 0; col < row; col++ )
		{
			int sval;
			cin >> val;
			istringstream iss( val );
			iss >> sval;

			if( val == "x" )
				graph[row][col] = graph[col][row] = INFINITY;
			else
				graph[row][col] = graph[col][row] = sval;
		}

	for( int k = 0; k < N; k++ )
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < N; j++ )
				graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );

	int starting_row = 0, communication_time = 0;;
	for( int col = 1; col < N; col++ )
		communication_time = max( graph[starting_row][col], communication_time );
	
	cout << communication_time << endl;

	return 0;
}
