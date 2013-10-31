#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int num_candidates;
	while( cin >> num_candidates )
	{
		if( num_candidates == 0 ) break;
		
		map < pair <int, int>, int > sets;

		for( int cand_num = 0; cand_num < num_candidates; cand_num++ )
		{
			int from, to;
			cin >> from >> to;
			if( from > to )
			{
				int tmp = from;
				from = to;
				to = tmp;
			}

			if( sets[ make_pair( from, to ) ] == 0 ) sets[ make_pair( from, to ) ]++;
			else sets[ make_pair( from, to ) ]--;
		}
	
		bool is_valid = true;
		
		map < pair <int, int>, int >::iterator ht = sets.begin();
		while( ht != sets.end() )
		{
			if( ht->second != 0 )
			{
				is_valid = false;
				break;
			}
			ht++;
		}
		
		if( is_valid ) cout << "YES" << endl;
		else cout << "NO" << endl;

		sets.clear();
	}

	return 0;
}
