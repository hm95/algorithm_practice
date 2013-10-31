#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 45;
const int UNKNOWN = -1;

class data
{
	private:
		int fib[MAX_NUM_ELEMENTS + 1];
		
	public:
		data();
		int calc_fibonnaci_dp( int n );
		int calc_fibonnaci_memo( int n );
		void clear();
		void print_fibonnaci( int n );
};

data::data()
{
	fib[0] = 0;
	fib[1] = 1;

	clear();
}

int data::calc_fibonnaci_dp( int n )
{
	for( int i = 2; i <= n; i++ )
		fib[i] = fib[ i - 1 ] + fib[ i - 2 ];

	return fib[n];
}

int data::calc_fibonnaci_memo( int n )
{
	if( fib[n] == UNKNOWN )
		fib[n] = calc_fibonnaci_memo( n - 1 ) + calc_fibonnaci_memo( n - 2 );

	return fib[n];
}

void data::clear()
{
	for( int i = 2; i <= MAX_NUM_ELEMENTS; i++ )
		fib[i] = UNKNOWN;
}

void data::print_fibonnaci( int n )
{
	cout << "Fibonnaci number " << n << ", using Memoization, is " << calc_fibonnaci_memo( n ) << endl;
	clear();
	cout << "Fibonnaci number " << n << ", using Dynamic Programming, is " << calc_fibonnaci_dp( n ) << endl;
}

int main()
{
	data myData;
	myData.print_fibonnaci( 45 );
	
	return 0;
}
