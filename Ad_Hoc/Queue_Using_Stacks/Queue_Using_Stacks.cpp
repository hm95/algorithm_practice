void enqueue( const int& value )
{
	stk1.push( value );
}

void dequeue()
{
	if( !stk2.empty() )
		stk2.pop();
	else
	{
		while( !stk1.empty() )
		{
			int tmp = stk1.top();
			stk2.push( tmp );
			stk1.pop();
		}
		stk2.pop();
	}
}
