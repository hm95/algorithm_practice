#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void top_sort( string caller, map < string, vector <string> > phone_list, map <string, bool>& visited, vector <string>& sorted_list )
{
	visited[caller] = true;

	vector <string>::iterator it = phone_list[caller].begin();
	while( it != phone_list[caller].end() )
	{
		if( !visited[*it] )
			top_sort( *it, phone_list, visited, sorted_list );
		it++;
	}

	sorted_list.push_back( caller );
}

void find_calling_circles( string person, map < string, vector <string> > phone_list, map <string, bool>& visited, map < int, vector <string> >& circle_caller_list, int circle_number )
{
	visited[person] = false;

	vector <string>::iterator it = phone_list[person].begin();
	while( it != phone_list[person].end() )
	{
		if( visited[*it] )
			find_calling_circles( *it, phone_list, visited, circle_caller_list, circle_number );
		it++;
	}

	circle_caller_list[circle_number].push_back( person );
}

int main()
{
	int num_people, num_connections, case_number = 1;
	while( cin >> num_people >> num_connections && num_people != 0 && num_connections != 0 )
	{
		if( case_number != 1 ) cout << endl;

		vector <string> list_of_people, sorted_list;
		string person;

		map <string, bool> unique_person;
		map < string, vector <string> > phone_list, phone_list_T;
		string from, to;

		for( int connection_number = 0; connection_number < num_connections; connection_number++ )
		{
			cin >> from >> to;
			if( !unique_person[from] )
			{
				unique_person[from] = true;
				list_of_people.push_back( from );
			}
			if( !unique_person[to] )
			{
				unique_person[to] = true;
				list_of_people.push_back( to );
			}
			phone_list[from].push_back( to );
			phone_list_T[to].push_back( from );
		}

		map <string, bool> visited;
		for( int i = 0; i < list_of_people.size(); i++ )
			if( !visited[list_of_people[i]] )
				top_sort( list_of_people[i], phone_list, visited, sorted_list );

		map < int, vector <string> > circle_caller_list;
		int circle_number = 0;
		for( int i = sorted_list.size() - 1; i >= 0; i-- )
			if( visited[sorted_list[i]] )
			{
				find_calling_circles( sorted_list[i], phone_list_T, visited, circle_caller_list, circle_number );
				circle_number++;
			}

		cout << "Calling circles for data set " << case_number << ":" << endl;
		for( int i = 0; i < circle_caller_list.size(); i++ )
		{
			for( int j = 0; j < circle_caller_list[i].size(); j++ )
			{
				cout << circle_caller_list[i][j];
				if( j != circle_caller_list[i].size() - 1 ) cout << ", ";
			}
			cout << endl;
		}

		case_number++;
	}

	return 0;
}
