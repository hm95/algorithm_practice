#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int rowdir[] = { 1, -1, 0, 0 };
int coldir[] = { 0, 0, 1, -1 };

struct city
{
	char name;
	int count;
};

struct pos
{
	char colour;
	int row, col;
};

bool cmp( const city& c1, const city& c2 )
{
	if( c1.count == c2.count ) return c1.name < c2.name;
	return c1.count > c2.count;
}

bool ok( int row, int col, const vector < vector <char> >& con )
{
	if( row >= 0 && row < con.size() && col >= 0 && col < con[0].size() ) return true;
	return false;
}

void flood_fill( int row, int col, char cell, vector < vector <char> >& con, map <char, int>& world, vector < vector <bool> >& visited )
{
	world[cell]++;

	pos root;
	root.row = row;
	root.col = col;
	root.colour = cell;

	queue <pos> q;
	q.push( root );
	visited[root.row][root.col] = true;

	while( !q.empty() )
	{
		pos tmp = q.front();
		q.pop();

		for( int i = 0; i < 4; i++ )
		{
			pos curr;
			curr.row = tmp.row + rowdir[i];
			curr.col = tmp.col + coldir[i];

			if( ok( curr.row, curr.col, con ) && con[curr.row][curr.col] == tmp.colour && !visited[curr.row][curr.col] )
			{
				visited[curr.row][curr.col] = true;
				curr.colour = tmp.colour;
				q.push( curr );
			}
		}
	}
}

int main()
{
	int num_graphs;
	cin >> num_graphs;

	for( int graph_no = 0; graph_no < num_graphs; graph_no++ )
	{
		int rows, cols;
		cin >> rows >> cols;

		vector < vector <char> > con;
		vector <char> tmp;

		vector < vector <bool> > vis;
		vector <bool> vtmp;

		for( int i = 0; i < rows; i++ )
		{
			for( int j = 0; j < cols; j++ )
			{
				char cell;
				cin >> cell;
				tmp.push_back( cell );
				vtmp.push_back( 0 );
			}
			con.push_back( tmp );
			vis.push_back( vtmp );
			tmp.clear();
			vtmp.clear();
		}

		map <char, int> world;
		for( int i = 0; i < rows; i++ )
			for( int j = 0; j < cols; j++ )
				if( !vis[i][j] ) flood_fill( i, j, con[i][j], con, world, vis );
			
		vector <city> cities;
		map <char, int>::iterator it = world.begin();

		while( it != world.end() )
		{
			city tmp;
			tmp.name = it->first;
			tmp.count = it->second;
			cities.push_back( tmp );
			it++;
		}

		sort( cities.begin(), cities.end(), cmp );

		cout << "World #" << graph_no + 1 << endl;
		vector <city>::iterator vt = cities.begin();
		while( vt != cities.end() )
		{
			cout << vt->name << ": " << vt->count << endl;
			vt++;
		}
	
		con.clear();
		world.clear();
		cities.clear();
	}

	return 0;
}
