#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 100;

class data
{
	private:
		int a[MAX_NUM_ELEMENTS];
		int b[MAX_NUM_ELEMENTS];
		int c[MAX_NUM_ELEMENTS + 1];
		
	public:
		data();
		void add_values();
		void n_bit_addition();
		void print_values();
};

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	c[MAX_NUM_ELEMENTS] = 0;
}

void data::add_values()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
	{
		a[i] = rand() % 2;
		b[i] = rand() % 2;
	}
}

void data::n_bit_addition()
{
	int carry = 0, sum = 0;

	for( int i = 0; i < MAX_NUM_ELEMENTS + 1; i++ )
	{
		sum = carry + a[i] + b[i];
		if( sum == 3 )
		{
			carry = 1;
			c[i] = 1;
		}
		else if( sum == 2 )
		{
			carry = 1;
			c[i] = 0;
		}
		else
		{
			carry = 0;
			c[i] = 1;
		}
	}
}

void data::print_values()
{
	cout << "Number a: " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << a[i] << ' ';
	cout << endl;

	cout << "Number b: " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << b[i] << ' ';
	cout << endl;

	cout << "Number c: " << endl;
	for( int i = 0; i < MAX_NUM_ELEMENTS + 1; i++ )
		cout << c[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;

	myData.add_values();
	myData.print_values();
	myData.n_bit_addition();
	myData.print_values();
	
	return 0;
}
