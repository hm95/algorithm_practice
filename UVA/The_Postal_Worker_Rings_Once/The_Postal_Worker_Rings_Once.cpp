#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

void walk( int pos, int& sum, vector < vector <int> >& graph  )
{
	for( int i = 0; i < 26; i++ )
		if( graph[pos][i] )
		{
			sum += graph[pos][i];
			graph[pos][i] = graph[i][pos] = false;
			walk( i, sum, graph );
		}
}

int bfs( int start, int ending, vector < vector <int> > graph )
{
	queue < pair <int, int> > q;
	q.push( make_pair( start, 0 ) );

	while( !q.empty() )
	{
		pair <int, int> cur = q.front();
		q.pop();

		if( cur.first == ending ) return cur.second;

		for( int i = 0; i < 26; i++ )
		{
			if( graph[cur.first][i] && i != cur.first )
			{
				q.push( make_pair( i, graph[cur.first][i] ) );
				graph[cur.first][i] = 0;
			}
		}
	}
}

int main()
{
	string line;
	while( getline( cin, line ) )
	{
		vector <int> tmp( 26, 0 );
		vector < vector <int> > graph( 26, tmp );
		vector < vector <int> > costt = graph;

		int end, sum = 0;
		string first = line;

		int starting = line[0] - 'a', ending = line[line.size() - 1] - 'a';
		int cost = line.size();
		costt[starting][ending] = costt[ending][starting] = cost;
		graph[starting][ending]++;
		graph[ending][starting]++;

		int avertex;
		while( getline( cin, line ) && line != "deadend" )
		{
			starting = line[0] - 'a', ending = line[line.size() - 1] - 'a';
			cost = line.size();
			costt[starting][ending] = costt[ending][starting] = cost;
			graph[starting][ending]++;
			graph[ending][starting]++;
			avertex = starting;
		}

		int count = 0;
		for( int i = 0; i < 26; i++ )
			for( int j = 0; j < 26; j++ )
				if( graph[i][j] % 2 )
					count++;

		cout << count << endl;


		int starting_vertex = -1, ending_vertex = -1;
		for( int i = 0; i < 26; i++ )
		{
			for( int j = 0; j < 26; j++ )
				if( graph[i][j] % 2 )
					starting_vertex = i;
		}

		for( int i = 0; i < 26; i++ )
		{
			for( int j = 0; j < 26; j++ )
				if( graph[i][j] % 2 && i != starting_vertex )
					ending_vertex = i;
		}

		/*char s = starting_vertex + 'a', e = ending_vertex + 'a';
		cout << s << ' ' << e << endl << endl;


		int dend = bfs( starting_vertex, ending_vertex, costt );
		walk( starting_vertex, sum, graph );
		cout << sum << endl;
		cout << dend << endl;*/

		/*if( starting_vertex == -1 )
		{
			starting_vertex = avertex;
			walk( starting_vertex, sum, graph );
			cout << sum << endl;
		}
		else
		{
			walk( starting_vertex, sum, graph );
			int dend = bfs( starting_vertex, ending_vertex, graph );
			cout << sum + dend << endl;
		}*/
	}

	return 0;
}
