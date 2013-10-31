#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int find_set( int A, vector <int>& rank, vector <int>& parent )
{
	if( parent[A] != A )
		parent[A] = find_set( parent[A], rank, parent );

	return parent[A];
}

void union_sets( int A, int B, vector <int>& rank, vector <int>& parent )
{
	int A1 = find_set( A, rank, parent ), B1 = find_set( B, rank, parent );

	if( rank[A1] < rank[B1] )
		parent[A1] = B1;
	else
		parent[B1] = A1;

	if( rank[A1] == rank[B1] )
		rank[B1]++;
}

int main()
{
	string line;
	int num_test_cases;
	cin >> num_test_cases;
	getline( cin, line );

	for( int test_no = 0; test_no < num_test_cases; test_no++ )
	{
		int num_computers;
		cin >> num_computers;
		getline( cin, line );

		vector <int> rank;
		vector <int> parent;

		for( int comp_no = 0; comp_no <= num_computers; comp_no++ )
		{
			rank.push_back( 0 );
			parent.push_back( comp_no );
		}

		int num_wrong = 0, num_right = 0;
		while( getline( cin, line ) && line != "" )
		{
			char type;
			int comp1, comp2;

			istringstream iss( line );
			iss >> type >> comp1 >> comp2;

			if( type == 'c' ) union_sets( comp1, comp2, rank, parent );
			else
			{
				if( find_set( comp1, rank, parent ) == find_set( comp2, rank, parent ) ) num_right++;
				else num_wrong++;
			}
		}

		cout << num_right << "," << num_wrong << endl;
		if( test_no != num_test_cases - 1 ) cout << endl;
		rank.clear();
		parent.clear();
	}
	
	return 0;
}
