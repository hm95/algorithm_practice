#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct pos
{
    string state, path;
    int cost;
};

string get_formatted_string( string original_string )
{
    string new_string = "";

    for( int i = 1; i < original_string.length(); i += 2 )
    {
        new_string += original_string[i];
        new_string += original_string[i - 1];
    }

    return new_string;
}

string get_next_valid_state( string original_string, int i )
{
    string new_string = original_string;

    if( i == 0 )
    {
        new_string[3] = original_string[0];
        new_string[6] = original_string[3];
        new_string[0] = original_string[6];
    }
    if( i == 1 )
    {
        new_string[4] = original_string[1];
        new_string[7] = original_string[4];
        new_string[1] = original_string[7];
    }
    if( i == 2 )
    {
        new_string[5] = original_string[2];
        new_string[8] = original_string[5];
        new_string[2] = original_string[8];
    }
    if( i == 3 )
    {
        new_string[0] = original_string[1];
        new_string[1] = original_string[2];
        new_string[2] = original_string[0];
    }
    if( i == 4 )
    {
        new_string[3] = original_string[4];
        new_string[4] = original_string[5];
        new_string[5] = original_string[3];
    }
    if( i == 5 )
    {
        new_string[6] = original_string[7];
        new_string[7] = original_string[8];
        new_string[8] = original_string[6];
    }

    return new_string;
}

int main()
{
    map <int, string> move_map;
    move_map[0] = "V1";
    move_map[1] = "V2";
    move_map[2] = "V3";
    move_map[3] = "H1";
    move_map[4] = "H2";
    move_map[5] = "H3";

    string ending_state = "123456789";
    map <string, bool> can_reach;
    map <string, int> distance;
    map <string, string> state_path;

    can_reach[ending_state] = true;
    distance[ending_state] = 0;
    state_path[ending_state] = "";

    pos root;
    root.state = ending_state, root.cost = 0, root.path = "";

    queue <pos> q;
    q.push( root );

    while( !q.empty() )
    {
        pos cur = q.front();
        q.pop();

        for( int i = 0; i < 6; i++ )
        {
            pos tmp;
            tmp.state = get_next_valid_state( cur.state, i );
            tmp.cost = cur.cost + 1;
            tmp.path = cur.path + move_map[i];

            if( !can_reach[tmp.state] )
            {
                can_reach[tmp.state] = true;
                state_path[tmp.state] = tmp.path;
                distance[tmp.state] = tmp.cost;
                q.push( tmp );
            }
        }
    }

    bool done = false;
    while( !done )
    {
        string starting_state = "";
        string s;
        for( int i = 0; i < 9; i++ )
        {
            cin >> s;
            if( s == "0" )
            {
                done = true;
                return 0;
            }
            starting_state += s;
        }

        if( can_reach[starting_state] )
        {
            string optimal_path = state_path[starting_state];
            reverse( optimal_path.begin(), optimal_path.end() );
            optimal_path = get_formatted_string( optimal_path );
            cout << distance[starting_state] << " " << optimal_path << endl;
        }
        else cout << "Not solvable" << endl;
    }

    return 0;
}
