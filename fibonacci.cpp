#include <iostream>
#include <vector>
using namespace std;

vector <int> get_first_n_fibs( const int& N )
{
    vector <int> list_fibs;
    list_fibs.push_back( 1 );
    list_fibs.push_back( 1 );
    
    int two_behind = 1, one_behind = 1;

    for( int i = 2; i < N; i++ )
    {
        int tmp = one_behind;
        one_behind += two_behind;
        two_behind = tmp;

        list_fibs.push_back( one_behind );
    }

    return list_fibs;
}

int main()
{
    const int N = 12;

    vector <int> fibs = get_first_n_fibs( N );

    for( int i = 0; i < fibs.size(); i++ )
        cout << "Fib(" << i + 1 << ") is " << fibs[i] << endl;

    return 0;
}
