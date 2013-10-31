#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_ELEMENTS = 100;

class data
{
	private:
		int values[MAX_NUM_ELEMENTS];
		
	public:
		data();
		void add_values();
		void binary_search( int V );
		int get_offset();
		void insertion_sort();
		void print_values();
};

data::data()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		values[i] = 0;
}

void data::add_values()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		values[i] = rand() % MAX_NUM_ELEMENTS;
}

void data::binary_search( int V )
{
	int low = 0, high = MAX_NUM_ELEMENTS - 1, offset = get_offset();

	if( values[low] <= V && values[offset] >= V )
		high = offset;
	else
		low = offset;

	while( low != high )
	{
		int mid = (low + high) / 2;
		if( values[mid] >= V ) high = mid;
		else low = mid + 1;
	}

	if( values[low] == V ) cout << "The item with value " << V << " was found at index " << low << endl;
	else cout << "The item with value " << V << " was not found." << endl;
}

int data::get_offset()
{
	int low = 0, high = MAX_NUM_ELEMENTS - 1;

	while( values[low] > values[high] )
	{
		int mid = (low + high) / 2;
		if( values[mid] > values[high] ) low = mid + 1;
		else high = mid;
	}

	return low;
}

void data::insertion_sort()
{
	int key, i, j;

	for( j = 2; j < MAX_NUM_ELEMENTS; j++ )
	{
		key = values[j];
		// Insert values[j] into the sorted sequence, values[1 to j - 1]
		i = j - 1;
		while( i >= 0 && values[i] > key )
		{
			values[i + 1] = values[i];
			i--;
		}
		values[i + 1] = key;
	}
}

void data::print_values()
{
	for( int i = 0; i < MAX_NUM_ELEMENTS; i++ )
		cout << values[i] << ' ';
	cout << endl;
}

int main()
{
	data myData;

	myData.add_values();
	myData.print_values();

	myData.insertion_sort();
	myData.print_values();
	myData.binary_search( 7 );
	
	return 0;
}
