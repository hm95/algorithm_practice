#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector < vector <char> > graph, graph_transpose;
vector <bool> visited;
map <char, bool> mmap;
vector <int> Topologically_Sorted_List;
vector < vector <int> > connected_component_list;

void topological_sort( int starting_vertex )
{
	visited[starting_vertex] = true;

	vector <char>::iterator it = graph[starting_vertex].begin();
	while( it != graph[starting_vertex].end() )
	{
		if( !visited[*it - 'A'] )
			topological_sort( *it - 'A' );
		it++;
	}

	Topologically_Sorted_List.push_back( starting_vertex );
}

void find_connected_components( int starting_vertex, int connected_component_number )
{
	visited[starting_vertex] = false;

	vector <char>::iterator it = graph_transpose[starting_vertex].begin();
	while( it != graph_transpose[starting_vertex].end() )
	{
		if( visited[*it - 'A'] )
			find_connected_components( *it - 'A', connected_component_number );
		it++;
	}

	connected_component_list[connected_component_number].push_back( starting_vertex );
}

int main()
{
	bool first = true;
	int num_lines;
	while( cin >> num_lines )
	{
		if( num_lines == 0 ) break;
		if( !first ) cout << endl;

		graph.resize( 26 ), graph_transpose.resize( 26 );
		visited.resize( 26 ), connected_component_list.resize( 26 );

		char a, b, c, d, e, ans;
		for( int line_num = 0; line_num < num_lines; line_num++ )
		{
			cin >> a >> b >> c >> d >> e >> ans;

			mmap[a] = true;
			mmap[b] = true;
			mmap[c] = true;
			mmap[d] = true;
			mmap[e] = true;
			
			graph[ans - 'A'].push_back( a );
			graph[ans - 'A'].push_back( b );
			graph[ans - 'A'].push_back( c );
			graph[ans - 'A'].push_back( d );
			graph[ans - 'A'].push_back( e );

			graph_transpose[a - 'A'].push_back( ans );
			graph_transpose[b - 'A'].push_back( ans );
			graph_transpose[c - 'A'].push_back( ans );
			graph_transpose[d - 'A'].push_back( ans );
			graph_transpose[e - 'A'].push_back( ans );
		}

		map <char, bool>::iterator it = mmap.begin();
		while( it != mmap.end() )
		{
			if( !visited[it->first - 'A'] )
				topological_sort( it->first - 'A' );
			it++;
		}

		int connected_component_number = 0;
		for( int i = Topologically_Sorted_List.size() - 1; i >= 0; i-- )
			if( visited[Topologically_Sorted_List[i]] )
			{
				find_connected_components( Topologically_Sorted_List[i], connected_component_number );
				connected_component_number++;
			}

		for( int i = 0; i < connected_component_list.size(); i++ )
			if( connected_component_list[i].size() != 0 )
				sort( connected_component_list[i].begin(), connected_component_list[i].end() );

		sort( connected_component_list.begin(), connected_component_list.end() );

		for( int i = 0; i < connected_component_list.size(); i++ )
		{
			if( connected_component_list[i].size() == 0 ) continue;
			for( int j = 0; j < connected_component_list[i].size(); j++ )
			{
				cout << char( connected_component_list[i][j] + 'A' );
				if( j != connected_component_list[i].size() - 1 )
					cout << ' ';
			}
			cout << endl;
		}

		first = false;
		graph.clear();
		graph_transpose.clear();
		connected_component_list.clear();
		visited.clear();
		mmap.clear();
		Topologically_Sorted_List.clear();
	}

	return 0;
}
