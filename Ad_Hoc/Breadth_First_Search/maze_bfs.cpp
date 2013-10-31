#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int UNKNOWN = -1;

struct position
{
	int row, col, num_steps;
};

class data
{
	private:
		int s_row, s_col, e_row, e_col;
		vector <int> coldir;
		vector <string> maze;
		vector <int> rowdir;
		vector < vector <int> > steps;
		map < pair<int, int>, string > path_map;

	public:
		data();
		void calc_minimum_steps();
		int find_minimum_steps();
		bool is_reachable( int row, int col );
		void print_new();
		void print_original();
		void print_path();
};

data::data()
{
	maze.push_back( "S..X....." );
	maze.push_back( ".......X." );
	maze.push_back( "..X....X." );
	maze.push_back( "....X..X." );
	maze.push_back( "....E..X." );

	rowdir.push_back(1);
	rowdir.push_back(-1);
	rowdir.push_back(0);
	rowdir.push_back(0);

	coldir.push_back(0);
	coldir.push_back(0);
	coldir.push_back(1);
	coldir.push_back(-1);

	vector <int> tmp;
	for( int i = 0; i < maze.size(); i++ )
	{
		for( int j = 0; j < maze[0].size(); j++ )
			tmp.push_back( UNKNOWN );
		steps.push_back( tmp );
		tmp.clear();
	}
}

void data::calc_minimum_steps()
{
	print_original();

	cout << "The starting point has coordinates (" << s_row << "," << s_col << ")." << endl;
	cout << "The ending point has coordinates (" << e_row << "," << e_col << ")." << endl;
	cout << "The shortest path from (" << s_row << "," << s_col << ") to (" << e_row << "," << e_col << ") takes " << find_minimum_steps() << " steps." << endl << endl;

	print_path();
	print_new();
}

int data::find_minimum_steps()
{
	position pos;
	pos.row = s_row, pos.col = s_col, pos.num_steps = 0;
	
	queue <position> q;	
	q.push( pos );

	path_map[ make_pair( 0,0 ) ] = "NULL";

	while( !q.empty() )
	{
		position tmp = q.front();
		q.pop();
		maze[tmp.row][tmp.col] = 'X';
		steps[tmp.row][tmp.col] = tmp.num_steps;

		if( tmp.row == e_row && tmp.col == e_col )
			return tmp.num_steps;

		for( int i = 0; i < 4; i++ )
		{
			position curr;
			curr.row = tmp.row + rowdir[i];
			curr.col = tmp.col + coldir[i];
			curr.num_steps = tmp.num_steps + 1;

			if( is_reachable( curr.row, curr.col ) )
			{
				stringstream ss;
				ss << tmp.row << "," << tmp.col;
				path_map[ make_pair( curr.row, curr.col ) ] = ss.str();
				q.push(curr);
				ss.str("");
			}
		}
	}
}

bool data::is_reachable( int row, int col )
{
	if( row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() && maze[row][col] != 'X' ) return true;
	return false;
}

void data::print_new()
{
	cout << "A shortest path from (" << s_row << "," << s_col << ") to (" << e_row << "," << e_col << ")." << endl;

	for( int i = 0; i < maze.size(); i++ )
	{
		for( int j = 0; j < maze[0].size(); j++ )
		{
			if( i == s_row && j == s_col ) cout << "S ";
			else if( i == e_row && j == e_col ) cout << "E ";
			else if( maze[i][j] == 'P' ) cout << "+ ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

void data::print_original()
{
	cout << "Original maze - 'S' depicts the starting point, 'E' depicts the ending point, 'X' depicts a point which cannot be visited:" << endl;

	for( int i = 0; i < maze.size(); i++ )
	{
		for( int j = 0; j < maze[0].size(); j++ )
		{
			if( maze[i][j] == 'E' ) e_row = i, e_col = j;
			if( maze[i][j] == 'S' ) s_row = i, s_col = j;
			cout << maze[i][j] << ' ';
			steps[i][j] = UNKNOWN;
		}
		cout << endl;
	}
	cout << endl;
}

void data::print_path()
{
	vector <string> path;
	cout << "One shortest path is " << endl;

	map < pair<int, int>, string >::iterator it = path_map.find( make_pair( e_row, e_col ) );
	while( it->second != "NULL" )
	{
		stringstream ss;
		ss << "(" << it->first.first << "," << it->first.second << ")";
		path.push_back( ss.str() );
		it = path_map.find( make_pair( it->second[0] - '0', it->second[2] - '0' ) );
		ss.str("");

		maze[ it->first.first ][ it->first.second ] = 'P';
	}
	stringstream ss;
	ss << "(" << s_row << "," << s_col << ")";
	path.push_back( ss.str() );

	reverse( path.begin(), path.end() );
	for( int i = 0; i < path.size(); i++ )
	{
		if( i == path.size() - 1 ) cout << path[i] << endl;
		else cout << path[i] << " -> ";
	}
	cout << endl;
}

int main()
{
	data myData;
	myData.calc_minimum_steps();

	return 0;
}
