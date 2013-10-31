#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int rank[50001], parent[50001];

int find_set( int A )
{
	if( A != parent[A] )
		parent[A] = find_set( parent[A] );
		
	return parent[A];
}

void union_set( int A, int B )
{
	int A1 = find_set( A ), B1 = find_set( B );

	if( rank[A1] < rank[B1] )
		parent[A1] = B1;
	else
		parent[B1] = A1;

	if( rank[A1] == rank[B1] )
		rank[B1] += 1;
}

void make_set( int A )
{
	parent[A] = A;
	rank[A] = 0;
}

int main()
{
	int num_students, num_pairs;
	while( cin >> num_students >> num_pairs )
	{
		if( num_students == 0 && num_pairs == 0 ) break;

		for( int i = 1; i <= num_students; i++ )
			make_set(i);

		for( int i = 0; i < num_pairs; i++ )
		{
			int s1, s2;
			cin >> s1 >> s2;

			union_set( s1, s2 );
		}

		vector <int> religions;
		vector <int>::iterator result;

		for( int i = 1; i <= num_students; i++ )
		{
			result = find( religions.begin(), religions.end(), find_set(i) );

			if( result == religions.end() )
				religions.push_back( parent[i] );
		}

		cout << religions.size() << endl;
	}
	
	return 0;
}
