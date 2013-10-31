#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void top_sort( string drink, map < string, vector <string> > adj_list, map <string, bool>& visited, vector <string>& sorted_list )
{
	visited[drink] = true;

	vector <string>::iterator it = adj_list[drink].begin();
	while( it != adj_list[drink].end() )
	{
		if( !visited[*it] )
			top_sort( *it, adj_list, visited, sorted_list );
		it++;
	}

	sorted_list.push_back( drink );
}

int main()
{
	int num_drinks;
	while( cin >> num_drinks )
	{
		string drink;
		vector <string> list_drinks;
		for( int drink_number = 0; drink_number < num_drinks; drink_number++ )
		{
			cin >> drink;
			list_drinks.push_back( drink );
		}

		int num_pairs;
		cin >> num_pairs;
		string first, second;

		map < string, vector <string> > adj_list;
		for( int pair_number = 0; pair_number < num_pairs; pair_number++ )
		{
			cin >> first >> second; 
			adj_list[first].push_back( second );
		}

		map <string, bool> visited;
		vector <string> sorted_list;
		for( int i = 0; i < list_drinks.size(); i++ )
			if( !visited[list_drinks[i]] )
				top_sort( list_drinks[i], adj_list, visited, sorted_list );

		cout << "Case #" << case_number << ": " << "Dilbert should drink beverages in this order:";
		for( int i = sorted_list.size() - 1; i >= 0; i-- )
			cout << " " << sorted_list[i];
		cout << "." << endl;
	}

	return 0;
}
