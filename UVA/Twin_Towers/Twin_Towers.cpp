#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	int len1, len2, test_no = 1;
	string s;
	while( cin >> len1 >> len2 && getline( cin, s ) )
	{
		if( len1 == 0 && len2 == 0 ) break;
		
		vector <int> tmp;
		for( int i = 0; i <= len2; i++ )
			tmp.push_back( 0 );

		vector < vector <int> > lengths;
		for( int i = 0; i <= len1; i++ )
			lengths.push_back( tmp );

		int val;
		getline( cin, s );
		istringstream iss( s );
		vector <int> s1;

		while( iss >> val )
			s1.push_back( val );

		getline( cin, s );
		istringstream bss( s );
		vector <int> s2;

		while( bss >> val )
			s2.push_back( val );
		
		for( int row = 1; row <= len1; row++ )
			for( int col = 1; col <= len2; col++ )
			{
				if( s1[row - 1] == s2[col - 1] ) lengths[row][col] = 1 + lengths[row - 1][col - 1];
				else lengths[row][col] = max( lengths[row - 1][col], lengths[row][col - 1] );
			}

		cout << "Twin Towers #" << test_no << endl;
		cout << "Number of Tiles : " << lengths[len1][len2] << endl << endl;
		test_no++;

		lengths.clear();
		tmp.clear();
		s1.clear();
		s2.clear();
	}

	return 0;
}
