#include <iostream>
#include <vector>
using namespace std;

void generate_all_subsets( int index, vector <int> str, vector <int> orig )
{
	if( str.size() != 0 )
	{
		for( int i = 0; i < str.size(); i++ )
			cout << str[i] << " ";
		cout << endl;
	}

	while( index < orig.size() )
	{
		vector <int> tmp = str;
		tmp.push_back( orig[index] );
		generate_all_subsets( index + 1, tmp, orig );
		index++;
	}
}

int main()
{
	vector <int> numbers, str;

	int val;
	while( cin >> val )
		numbers.push_back( val );
	
	generate_all_subsets( 0, str, numbers );

	return 0;
}
