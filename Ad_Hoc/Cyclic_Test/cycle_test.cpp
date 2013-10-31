#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class data
{
	private:
		map <char, set <char> > ans;
		map <char, vector <char> > graph;

	public:
		data();
		void check_for_cycles();
		bool has_cycle();
		void print_graph();
};

data::data()
{
	// This graph does not have a cycle.
	graph['a'].push_back('b');
	graph['a'].push_back('d');
	graph['b'].push_back('c');
	graph['c'].push_back('d');
	graph['d'].push_back('e');
	check_for_cycles();

	graph.clear();
	ans.clear();

	// This graph does have a cycle.
	graph['a'].push_back('b');
	graph['a'].push_back('d');
	graph['a'].push_back('e');
	graph['b'].push_back('e');
	graph['c'].push_back('e');
	graph['d'].push_back('e');
	graph['e'].push_back('c');
	check_for_cycles();
}

bool data::has_cycle()
{
	map <char, vector <char> >::iterator it = graph.begin();
	vector <char>::iterator ct = graph[it->first].begin();

	stack <char> s;
	s.push( it->first );

	while( !s.empty() )
	{
		char tmp = s.top();
		s.pop();

		ct = graph[tmp].begin();
		while( ct != graph[tmp].end() )
		{
			if( ans[tmp].find(*ct) != ans[tmp].end() ) return true;
			else
			{
				s.push(*ct);
				ans[*ct] = ans[tmp];
				ans[*ct].insert(tmp);
			}
			ct++;
		}
	}

	return false;
}

void data::check_for_cycles()
{
	cout << "The graph, in adjacency-list form is: " << endl;
	print_graph();
	cout << "The graph does" << ( has_cycle() == true ? " " : " not " ) << "have a cycle." << endl << endl;
}

void data::print_graph()
{
	map <char, vector <char> >::iterator it = graph.begin();

	while( it != graph.end() )
	{
		vector <char>::iterator ct = graph[it->first].begin();
		cout << it->first << " is adjacent to:" << endl;
		while( ct != graph[it->first].end() )
		{
			cout << *ct << ' ';
			ct++;
		}
		cout << endl;
		it++;
	}
}

int main()
{
	data myData;

	return 0;
}
