#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num_nodes;
	while( cin >> num_nodes )
	{
		if( num_nodes == 0 ) break;

		int node_val;
		vector <int> nodes;
		for( int i = 0; i < num_nodes; i++ )
		{
			cin >> node_val;
			nodes.push_back( node_val );
		}

		int count = 0;
		for( int i = 0; i < nodes.size(); i++ )
		{
			int val = nodes[i];
			for( int j = i + 1; j < nodes.size(); j++ )
				if( val > nodes[j] ) 
					count++;
		}

		cout << count << endl; 
	}
	
	return 0;
}
