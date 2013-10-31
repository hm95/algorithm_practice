#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map < pair <int, int>, int > memo;
vector < vector <int> > list_of_prime_factors( 1000 );
map <int, bool> visited;
vector <bool> primes( 1001, true );

void generate_all_prime_factorizations()
{
	for( int i = 2; i < sqrt( 1001 ); i++ )
	{
		if( !primes[i] ) continue;
		for( int j = i * i; j < 1001; j += i )
			primes[j] = false;
	}

	for( int number = 1; number <= 999; number++ )
		for( int i = 2; i < number; i++ )
			if( primes[i] && number % i == 0 )
				list_of_prime_factors[number].push_back( i );
}

int find_optimal_number_transformation( int A, int B )
{
	if( memo[ make_pair( A, B ) ] )
		return memo[ make_pair( A, B ) ];

	queue < pair <int, int> > q;
	q.push( make_pair( A, 0 ) );

	int min_dist = -1;
	visited[A] = true;

	while( !q.empty() )
	{
		pair <int, int> cur = q.front();
		q.pop();

		if( cur.first == B )
		{
			min_dist = cur.second;
			break;
		}

		for( int i = 0; i < list_of_prime_factors[cur.first].size(); i++ )
			if( cur.first + list_of_prime_factors[cur.first][i] <= B && !visited[cur.first + list_of_prime_factors[cur.first][i]] )
			{
				visited[cur.first + list_of_prime_factors[cur.first][i]] = true;
				q.push( make_pair( cur.first + list_of_prime_factors[cur.first][i], 1 + cur.second ) );
			}
	}

	memo[ make_pair( A, B ) ] = min_dist;
	return min_dist;
}

int main()
{
	generate_all_prime_factorizations();

	int A, B, case_number = 1;
	while( cin >> A >> B && A != 0 && B != 0 )
	{
		cout << "Case " << case_number << ": " << find_optimal_number_transformation( A, B ) << endl;

		case_number++;
		visited.clear();
	}

	return 0;
}
