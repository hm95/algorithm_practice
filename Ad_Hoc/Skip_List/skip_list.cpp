#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 4;

class SkipListNode
{
	public:
		// Pointer to array of SkipListNode pointers
		SkipListNode** next;

		// Data for each SkipListNode
		int key;
};

class SkipList
{
	public:
		// Initializes the skip list node pointers
		SkipList();

		// Sets the values in range_bounds; these are used to determine the size of nodes being inserted
		void choose_range_bounds();

		// Randomly picks a node size
		int choose_level();

		// Returns a boolean value indicating whether or not the skip list is empty
		bool is_empty();

		// Returns a boolean value indicating whether or not the skip list contains an element with key = value
		bool search( int value );

		// Inserts a new SkipListNode with key = new_key into the skip list
		void insert( int new_key );

	private:
		typedef SkipListNode* skip_list_node_ptr;

		// Holds skip list node pointers
		skip_list_node_ptr root[MAX_SIZE];

		// Holds values which are used to determine the size of nodes being inserted
		int range_bounds[MAX_SIZE];
};

SkipList::SkipList()
{
	for( int i = 0; i < MAX_SIZE; i++ )
		root[i] = NULL;
}

int SkipList::choose_level() 
{
	int r = ( rand() % range_bounds[ MAX_SIZE - 1 ] ) + 1;

	for( int i = 1; i < MAX_SIZE; i++ )
		if( r < range_bounds[i] )
			return i - 1;

	return MAX_SIZE - 1;
}

void SkipList::choose_range_bounds() 
{
	int i = MAX_SIZE - 2, j = 0;

	range_bounds[ MAX_SIZE - 1 ] = ( 2 << ( MAX_SIZE - 1 ) ) - 1;

	while( i >= 0 )
	{
		range_bounds[i] = range_bounds[ i + 1 ] - ( 2 << j );
		i--, j++;
	}
}

void SkipList::insert( int new_key )
{
	skip_list_node_ptr curr[MAX_SIZE], prev[MAX_SIZE], new_skip_list_node;
	curr[ MAX_SIZE - 1 ] = root[ MAX_SIZE - 1 ];
	prev[ MAX_SIZE - 1 ] = 0;
	
	int lvl = MAX_SIZE - 1;

	while( lvl >= 0 )
	{
		while( curr[lvl] && curr[lvl]->key < new_key )
		{
			prev[lvl] = curr[lvl];
			curr[lvl] = *( curr[lvl]->next + lvl );
		}

		if( curr[lvl] && curr[lvl]->key == new_key )
			return;

		if( lvl > 0 )
		{
			if( prev[lvl] == 0 )
			{
				curr[ lvl - 1 ] = root[ lvl - 1 ];
				prev[ lvl - 1 ] = 0;
			}
			else
			{
				curr[ lvl - 1 ] = *( prev[lvl]-> next + lvl - 1 );
				prev[ lvl - 1 ] = prev[lvl];
			}
		}

		lvl--;
	}

	lvl = choose_level();

	new_skip_list_node = new SkipListNode;
	new_skip_list_node->next = new skip_list_node_ptr[ sizeof( skip_list_node_ptr ) * ( lvl + 1 ) ];
	new_skip_list_node->key = new_key;

	for( int i = 0; i <= lvl; i++ )
	{
		if( prev[i] == 0 )
			root[i] = new_skip_list_node;

		else
			*( prev[i]->next + i ) = new_skip_list_node;
	}
}

bool SkipList::is_empty()
{
	return ( root[0] == 0 );
}

bool SkipList::search( int value )
{
	if ( is_empty() )
		return true;

	bool found = false;
	bool done = false;

	int lvl = MAX_SIZE - 1;
	while( lvl >= 0 && !root[lvl] )
		lvl--;

	skip_list_node_ptr prev, curr;
	prev = root[lvl];
	curr = root[lvl];

	while( !done )
	{
		if( value == curr->key )
		{
			found = true;
			done = true;
		}
		else if( value < curr->key )
		{
			if( lvl == 0 )
				done = true;
			else if( curr == root[lvl] )
			{
				lvl--;
				curr = root[lvl];
			}
			else
			{
				lvl--;
				curr = *( prev->next + lvl );
			}
		}
		else
		{
			prev = curr;

			if( *(curr->next + lvl ) != 0 )
				curr = *( prev->next + lvl );

			else
			{
				lvl--;
				while( lvl >= 0 && *( curr->next + lvl ) == 0 )
					lvl--;

				if( lvl >= 0 )
					curr = *( curr->next + lvl );

				else done = true;
			}
		}
	}

	return found;
}
