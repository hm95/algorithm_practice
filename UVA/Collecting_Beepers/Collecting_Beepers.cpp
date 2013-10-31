#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 9e8;

struct pos
{
	int x_coord, y_coord;
};

int find_cost( int n1, int n2, map <int, pos>& world )
{
	return abs( world[n1].x_coord - world[n2].x_coord ) + abs( world[n1].y_coord - world[n2].y_coord );
}

int cost( string str, map <int, pos>& world )
{
	int total_cost = 0;
	for( int i = 0; i < str.size() - 1; i++ )
		total_cost += find_cost( str[i] - '0', str[i + 1] - '0', world );

	return total_cost;
}

int main()
{
	int num_graphs;
	cin >> num_graphs;

	for( int graph_no = 0; graph_no < num_graphs; graph_no++ )
	{
		int x_val, y_val;
		cin >> x_val >> y_val;

		vector < vector <int> > graph;
		vector <int> tmp;

		for( int i = 0; i < y_val; i++ )
			tmp.push_back( 1 );

		for( int i = 0; i < x_val; i++ )
			graph.push_back( tmp );

		int start_x, start_y;
		cin >> start_x >> start_y;

		pos start;
		start.x_coord = start_x;
		start.y_coord = start_y;

		map <int, pos> world;

		world[0] = start;
		int node_num = 1;

		int num_beepers;
		cin >> num_beepers;

		for( int i = 0; i < num_beepers; i++ )
		{
			int x_val, y_val;
			cin >> x_val >> y_val;

			pos tmp;
			tmp.x_coord = x_val;
			tmp.y_coord = y_val;

			world[node_num] = tmp;
			node_num++;
		}

		string path;
		for( int i = 0; i < num_beepers; i++ )
			path += i + '0' + 1;

		int min_cost = INF;
		if( path == "1" ) min_cost = 0;

		while( next_permutation( path.begin(), path.end() ) )
		{
			string tmp = "0";
			for( int i = 0; i < num_beepers; i++ )
				tmp += path[i];
			tmp += "0";

			min_cost = min( min_cost, cost( tmp, world ) );
		}

		cout << "The shortest path has length " << min_cost << endl;

		world.clear();
		tmp.clear();
	}

	return 0;
}
