#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_vertices;
	while( cin >> num_vertices )
	{
		if( num_vertices == 0 ) break;
		
		vector < vector <int> > adj;
		vector <int> tmp;

		for( int i = 0; i < num_vertices; i++ )
			tmp.push_back( 0 );

		for( int i = 0; i < num_vertices; i++ )
			adj.push_back( tmp );

		int start;
		while( cin >> start )
		{
			if( start == 0 ) break;
			
			int to;
			while( cin >> to )
			{
				if( to == 0 ) break;
				adj[start - 1][to - 1] = 1;
			}
		}

		for( int k = 0; k < num_vertices; k++ )
			for( int i = 0; i < num_vertices; i++ )
				for( int j = 0; j < num_vertices; j++ )
					if( adj[i][k] && adj[k][j] ) adj[i][j] = 1;

		int num_start;
		cin >> num_start;

		for( int i = 0; i < num_start; i++ )
		{
			int count = 0;
			int from;
			cin >> from;

			for( int j = 0; j < num_vertices; j++ )
				if( !adj[from - 1][j] ) count++;

			cout << count << " ";
			for( int j = 0; j < num_vertices; j++ )
				if( !adj[from - 1][j] ) cout << j + 1 << " ";
			cout << endl;
		}
		
		adj.clear();
	}

	return 0;
}
