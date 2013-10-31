#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
	map <string, string> dictionary;
	string line;

	while( getline( cin, line ) && line != "" )
	{
		istringstream iss( line );
		string from, to;
		while( iss >> to >> from )
			dictionary[from] = to;
	}

	while( getline( cin, line ) )
	{
		if( dictionary[line] == "" )
			cout << "eh" << endl;
		else cout << dictionary[line] << endl;
	}

	return 0;
}
