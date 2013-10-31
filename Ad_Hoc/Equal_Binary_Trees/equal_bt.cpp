#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* left, *right;
};

bool are_equal( Node* node1, Node* node2 )
{
	if( node1 == NULL && node2 == NULL ) return true;
	if( node1 != NULL && node2 != NULL && node1->value == node2->value )
		return are_equal( node1->left, node2->left ) && are_equal( node1->right, node2->right );
	return false;
}

int main()
{
	Node* root1 = new Node, *node2 = new Node;
	root1->value = 0;
	root1->left = NULL, root1->right = node2;
	node2->value = 1, node2->left = node2->right = NULL;

	Node* root2 = new Node;
	root2->value = 0;
	root2->left = root2->right = NULL;

	cout << "The two trees are " << ( are_equal( root1, root2 ) == 0 ? "not " : "" ) << "equal."<< endl;

	return 0;
}
