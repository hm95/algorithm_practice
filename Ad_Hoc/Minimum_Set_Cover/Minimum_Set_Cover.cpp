#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool is_covered( vector <char>& cover_set, map <char, int>& freq )
{
    for( int i = 0; i < cover_set.size(); i++ )
        if( freq[cover_set[i]] == 0 )
            return false;

    return true;
}

int get_min_length( string& cover, vector <char>& cover_set )
{
    map <char, int> freq;
    int left_index = 0, right_index = 0, cur_dist = 0, min_dist = cover.size();
    freq[cover[0]]++;

    while( left_index <= cover.size() - cover_set.size() && right_index < cover.size() )
    {
        cur_dist = right_index - left_index + 1;

        if( is_covered( cover_set, freq ) )
        {
            min_dist = min( cur_dist, min_dist );
            freq[cover[left_index]]--;
            left_index++;
        }
        else
        {
            right_index++;
            freq[cover[right_index]]++;
        }
    }

    return min_dist;
}

int main()
{
    int num_values;
    cin >> num_values;

    vector <char> cover_set( num_values );
    for( int i = 0; i < num_values; i++ )
        cin >> cover_set[i];
    
    string cover;
    cin >> cover;

    cout << get_min_length( cover, cover_set ) << endl;

    return 0;
}
