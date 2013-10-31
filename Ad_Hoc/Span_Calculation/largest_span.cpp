#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 100;
const int MAX_VAL = 100;
const int NOT_KNOWN = -1;

class data
{
	private:
		int S[MAX_NUM_ELEMENTS];
		
	public:
		data();
		void calc_largest_span();
		int largest_span();
		void print_sequence();
};

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		S[i] = rand() % MAX_VAL;
}

void data::calc_largest_span()
{
	cout << "The original sequence, S, is " << endl;
	print_sequence();

	cout << "The length of the largest span, in S, is " << largest_span() << endl;
}

int data::largest_span()
{
	stack <int> stk;
	int spans[MAX_NUM_ELEMENTS];
	int maxv = -1, h;
	bool done;

	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
	{
		done = false;

		while( !stk.empty() && !done )
		{
			if( S[i] >= S[ stk.top() ] )
				stk.pop();
			else done = true;
		}

		if( stk.empty() ) h = -1;
		else h = stk.top();
		
		spans[i] = i - h;
		stk.push( i );
	}

	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		maxv = max( maxv, spans[i] );
	
	return maxv;
}

void data::print_sequence()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << S[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;
	myData.calc_largest_span();
	
	return 0;
}
