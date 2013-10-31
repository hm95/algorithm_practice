#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	int n, m;
	int field_num = 1;

	while( cin >> n >> m && n != 0 && m != 0 )
	{
		if( field_num != 1 ) cout << endl;
		char orig_field[n][m], final_field[n][m];

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin >> orig_field[i][j];

		bool is_mine[n + 2][m + 2];
		for( int i = 0; i < n + 2; i++ )
		{
			is_mine[i][0] = false;
			is_mine[i][m + 1] = false;
		}

		for( int j = 0; j < m + 2; j++ )
		{
			is_mine[0][j] = false;
			is_mine[n + 1][j] = false;
		}

		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= m; j++ )
			{
				if( orig_field[i - 1][j - 1] == '*' ) is_mine[i][j] = true;
				else is_mine[i][j] = false;
			}
		}
	
		int mine_count;
		cout << "Field #" << field_num << ":" << endl;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				if( orig_field[i][j] == '*' ) cout << '*';
				else
				{
					mine_count = 0;
					if( is_mine[i][j] ) mine_count++;
					if( is_mine[i+1][j] ) mine_count++;
					if( is_mine[i][j+1] ) mine_count++;
					if( is_mine[i+2][j+2] ) mine_count++;
					if( is_mine[i+1][j+2] ) mine_count++;
					if( is_mine[i+2][j+1] ) mine_count++;
					if( is_mine[i][j+2] ) mine_count++;
					if( is_mine[i+2][j] ) mine_count++;
					cout << mine_count;
				}
			}
			cout << endl;
		}
		field_num++;
	}

	return 0;
}
