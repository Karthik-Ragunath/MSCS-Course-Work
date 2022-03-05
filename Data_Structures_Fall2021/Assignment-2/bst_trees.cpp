#include<iostream>
using namespace std;

class Node
{
	public:
		int val;
		Node *left;
		Node *right;
		Node(int x): val(x), left(NULL), right(NULL) {}
};


Node* insert_into_bst(Node* root, int node_val)
{
	if(root == NULL)
	{
		Node* new_node = new Node(node_val);
		return new_node;
	}
	if(node_val <= root -> val)
	{
		root -> left = insert_into_bst(root -> left, node_val);
	}
	if(node_val > root -> val)
	{
		root-> right = insert_into_bst(root -> right, node_val);
	}
	return root;
}

void inorder_traversal(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	inorder_traversal(root -> left);
	cout << root -> val << "   ";
	inorder_traversal(root -> right);
}

Node* get_successor(Node* root)
{
	if(root == NULL)
	{
		return root;
	}
	while(root -> left != NULL)
	{
		return get_successor(root -> left);
	}
	return root;
}

Node* delete_node(Node* root, int del_val)
{
	if(root == NULL)
	{
		return root;
	}
	if(root -> val > del_val)
	{
		root -> left = delete_node(root -> left, del_val);
		return root;
	}
	if(root -> val < del_val)
	{
		root -> right = delete_node(root -> right, del_val);
		return root;
	}
	if(root -> left == NULL && root -> right == NULL)
	{
		root = NULL;
		return root;
	}
	if(root -> left == NULL)
	{
		root = root -> right;
		return root; 
	}
	if(root -> right == NULL)
	{
		root = root -> left;
		return root;
	}
	Node* temp = get_successor(root -> right);
	root -> val = temp -> val;
	root -> right = delete_node(root -> right, temp -> val);
	return root;

}

int main()
{
	int working_mode;
	cout << "Enter 1 to insert nodes to BST, 0 to delete nodes from BST and any other to exit from program" << "\n";
	cin >> working_mode;
	Node* root = NULL;
	while(working_mode == 1 || working_mode == 0)
	{
		if(working_mode == 1)
		{
			int num_nodes;
			cout << "Enter the number of nodes to insert:\n";
			cin >> num_nodes;
			cout << "Enter the node values:\n";
			for(int i = 0; i < num_nodes; i++)
			{
				int temp;
				cin >> temp;
				root = insert_into_bst(root, temp);
			}
		}
		else
		{
			int val_to_delete;
			cout << "Enter the node value to delete:\n";
			cin >> val_to_delete;
			root = delete_node(root, val_to_delete);
		}
		cout << "--------------- Printing Inorder Traversal -------------------\n";
		inorder_traversal(root);
		cout << "\n--------------------------------------------------------------\n";
		cout << "Enter 1 to input nodes to BST, 0 to delete nodes from BST and any other number/ character to exit from program" << "\n";
		cin >> working_mode;
	}
	return 0;
}