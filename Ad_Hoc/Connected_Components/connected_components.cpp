#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class data
{
	private:
		map <int, vector <char> > list;
		map <char, vector <char> > graph;
		set <char> visited;

	public:
		data();
		void connected_components();
		void label_component( char vertex, int component );
		void print_connected_components();
};

data::data()
{
	graph['a'].push_back('b');
	graph['a'].push_back('d');
	graph['a'].push_back('e');
	graph['b'].push_back('e');
	graph['c'].push_back('e');
	graph['d'].push_back('e');
	graph['e'].push_back('c');
	graph['g'].push_back('a');
	graph['f'].push_back('z');

	map <char, vector <char> >::iterator it = graph.begin();
	while( it != graph.end() )
	{
		vector <char>::iterator ct = graph[it->first].begin();
		while( ct != graph[it->first].end() )
		{
			graph[*ct].push_back( it->first );
			ct++;
		}
		it++;
	}
}

void data::connected_components()
{
	int component_number = 0;
	map <char, vector <char> >::iterator it = graph.begin();
	vector <char>::iterator ct = graph[it->first].begin();

	while( it != graph.end() )
	{
		if( visited.find( it->first ) == visited.end() )
		{
			label_component( it->first, component_number );
			component_number++;
		}
		it++;
	}

	map < int, vector <char> >::iterator lt = list.begin();
	while( lt != list.end() )
	{
		vector <char>::iterator c = list[lt->first].begin();
		cout << "Component: " << lt->first << endl;
		while( c != list[lt->first].end() )
		{
			cout << *c << ' ';
			c++;
		}
		cout << endl;
		lt++;
	}
}

void data::label_component( char vertex, int component )
{
	queue <char> q;
	q.push( vertex );
	
	while( !q.empty() )
	{
		char tmp = q.front();
		q.pop();
		
		visited.insert( tmp );
		list[component].push_back( tmp );

		vector <char>::iterator it = graph[tmp].begin();
		while( it != graph[tmp].end() )
		{
			if( visited.find( *it ) == visited.end() )
			{
				visited.insert( *it );
 				q.push( *it );
			}
			it++;
		}
	}
}

void data::print_connected_components()
{
	cout << "The connected components are: " << endl;
	connected_components();
}

int main()
{
	data myData;
	myData.print_connected_components();

	return 0;
}
