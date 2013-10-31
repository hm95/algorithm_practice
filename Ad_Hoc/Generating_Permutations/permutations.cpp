#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void generate_all_permutations( vector <int> numbers )
{
	sort( numbers.begin(), numbers.end() );

	do {
		for( int i = 0; i < numbers.size(); i++ )
			cout << numbers[i] << " ";
		cout << endl;
	} while( next_permutation( numbers.begin(), numbers.end() ) );
}

int main()
{
	vector <int> numbers;

	int val;
	while( cin >> val )
		numbers.push_back( val );
	
	generate_all_permutations( numbers );

	return 0;
}
