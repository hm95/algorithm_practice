/*	@JUDGE_ID:	syder	439	C++	Breadth First Search */
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct path
{
	char row, col;
	int num_steps;
};

bool is_in_range( char row, char col )
{
	if( row >= 'a' && row <= 'h' && col >= '1' && col <= '8' ) return true;
	return false;
}

int rowd[8] = { -2, -2, 2, 2, 1, 1, -1, -1 };
int cold[8] = { -1, 1, -1, 1, 2, -2, 2, -2 };

int main()
{
	string start_pos, end_pos;

	while( cin >> start_pos >> end_pos )
	{
		int ns = 0;
		path cur_pos;
		cur_pos.num_steps = 0;
		cur_pos.row = start_pos[0];
		cur_pos.col = start_pos[1];

		queue <path> q;
		q.push( cur_pos );

		while( !q.empty() )
		{
			path tmp = q.front();
			q.pop();

			if( tmp.row == end_pos[0] && tmp.col == end_pos[1] )
			{
				ns = tmp.num_steps;
				break;
			}

			for( int i = 0; i < 8; i++ )
			{
				path cp;
				cp.row = tmp.row + rowd[i];
				cp.col = tmp.col + cold[i];
				cp.num_steps = tmp.num_steps + 1;

				if( is_in_range( cp.row, cp.col ) ) q.push( cp );
			}
		}

		cout << "To get from " << start_pos << " to " << end_pos << " takes " << ns << " knight moves." << endl;
	}

	return 0;
}
