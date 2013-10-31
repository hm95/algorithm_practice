#include <iostream>
using namespace std;

int get_nth_fibonacci( const int N )
{
    if( N == 1 || N == 0 )
        return N;

    int two_behind = 0, one_behind = 1;

    int tmp;
    for( int i = 2; i < N; i++ )
    {
        int tmp = two_behind + one_behind;
        two_behind = one_behind;
        one_behind = tmp;
    }

    return one_behind + two_behind;
}

int main()
{
    int N;
    cin >> N;
    cout << "Fibonacci number " << N << " is " << get_nth_fibonacci( N ) << endl;

    return 0;
}
