#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

class Node
{
	public:
		Node *next;
		int val;
		Node(int x): val(x), next(NULL) {}
};

void traverse_and_print(Node* temp)
{
	if(temp != NULL)
	{
		cout << temp -> val << "\n";
		traverse_and_print(temp -> next);
	}
	return;
}

Node* create_ascending_test_set(int cur_index, int min_val)
{	
	if(cur_index >= min_val)
	{
		Node* new_node = new Node(cur_index);
		new_node -> next = create_ascending_test_set(cur_index - 1, min_val);
		return new_node;
	}
	return NULL;
}

Node* create_descending_test_set(int cur_index, int max_val)
{
	if(cur_index <= max_val)
	{
		Node* new_node = new Node(cur_index);
		new_node -> next = create_descending_test_set(cur_index + 1, max_val);
		return new_node;
	}
	return NULL;
}

Node* selection_sort_recursive_ascending(Node* temp)
{
	Node* head = temp;
	if(not head)
	{
		return temp;
	}
	Node* temp_node = temp;
	while(head != NULL and temp_node != NULL and temp_node -> next != NULL)
	{
		if(head -> val > temp_node -> next -> val)
		{
			Node* tempo = temp_node -> next;
			Node* next_ptr = NULL;
			Node* head_next = head -> next;
			if(temp_node -> next -> next)
			{
				next_ptr = temp_node -> next -> next;
			}
			temp_node -> next = head;
			temp_node -> next -> next = next_ptr;
			if(tempo == head_next)
			{
				tempo -> next = temp_node;
			}
			else
			{
				tempo -> next = head_next;
			}
			head = tempo;
		}
		else
		{
			temp_node = temp_node -> next;
		}
	}
	if(head -> next != NULL)
	{
		head -> next = selection_sort_recursive_ascending(head -> next);
	}
	return head;
}

Node* selection_sort_recursive_descending(Node* temp)
{
	Node* head = temp;
	if(not head)
	{
		return head;
	}
	Node* temp_node = temp;
	while(head != NULL and temp_node != NULL and temp_node -> next != NULL)
	{
		if(head -> val < temp_node -> next -> val)
		{
			Node* tempo = temp_node -> next;
			Node* next_ptr = NULL;
			Node* head_next = head -> next;
			if(temp_node -> next -> next)
			{
				next_ptr = temp_node -> next -> next;
			}
			temp_node -> next = head;
			temp_node -> next -> next = next_ptr;
			if(tempo == head_next)
			{
				tempo -> next = temp_node;
			}
			else
			{
				tempo -> next = head_next;
			}
			head = tempo;
		}
		else
		{
			temp_node = temp_node -> next;
		}
	}
	if(head -> next != NULL)
	{
		head -> next = selection_sort_recursive_descending(head -> next);
	}
	return head;
}

void traverse_and_print_linked_list_format(Node* temp)
{
	while(temp -> next != NULL)
	{
		cout << temp -> val << " -> ";
		temp = temp -> next;
	}
	cout << temp -> val << "\n";
}

void test_cases_descending(int test_index, int lower_index, int max_index)
{
	cout << "-------------------------------\n";
	cout << "Test " << test_index << "\n";
	cout << "-------------------------------\n";
	Node* new_node_desc_test = create_descending_test_set(lower_index, max_index);

	cout << "Before Sorting in Descending Order:\n";
	traverse_and_print_linked_list_format(new_node_desc_test);

	Node* ret_node_desc_test = selection_sort_recursive_descending(new_node_desc_test);

	cout << "-------------------------------\n";
	cout << "After Sorting in Descending Order:\n";
	if(ret_node_desc_test != NULL)
	{
		traverse_and_print_linked_list_format(ret_node_desc_test);
	}
	else
	{
		cout << "head is NULL" << "\n";
	}
	cout << "====================================\n";
}

void test_cases_ascending(int test_index, int max_index, int lower_index)
{
	cout << "-------------------------------\n";
	cout << "Test " << test_index << "\n";
	cout << "-------------------------------\n";
	Node* new_node_asc_test = create_ascending_test_set(max_index, lower_index);

	cout << "Before Sorting in Ascending Order:\n";
	traverse_and_print_linked_list_format(new_node_asc_test);

	Node* ret_node_asc_test = selection_sort_recursive_ascending(new_node_asc_test);

	cout << "-------------------------------\n";
	cout << "After Sorting in Ascending Order:\n";
	if(ret_node_asc_test != NULL)
	{
		traverse_and_print_linked_list_format(ret_node_asc_test);
	}
	else
	{
		cout << "head is NULL" << "\n";
	}
	cout << "====================================\n";
}

void sample_test_cases_mode()
{
	test_cases_descending(1, 0, 15);
	test_cases_ascending(2, 15, 0);
	test_cases_descending(3, 10, 10);
	test_cases_ascending(4, 0, 0);
	cout << "------------------------------\n";
	cout << "Test 5 (NULL Test)\n";
	cout << "------------------------------\n";
	Node* new_node_null_test = NULL;
	Node* ret_node_desc_null_test = selection_sort_recursive_descending(new_node_null_test);
	if(ret_node_desc_null_test != NULL)
	{
		traverse_and_print_linked_list_format(ret_node_desc_null_test);
	}
	else
	{
		cout << "head is NULL" << "\n";
	}
	cout << "====================================\n";
	// your code goes here
}

Node* create_linkedlist(vector< int > &linkedlist_elements, int index)
{
	if(index < linkedlist_elements.size())
	{
		Node* new_node = new Node(linkedlist_elements[index]);
		new_node -> next = create_linkedlist(linkedlist_elements, index + 1);
		return new_node;
	}
	return NULL;
}

int main() 
{

	int working_mode;
	cout << "Type 0 for sample test cases and 1 for testing in interactive mode:\n";
	cin >> working_mode;

	if(working_mode == 1)
	{
		int array_size;
		cout << "Input the size of the linked list: \n";
		cin >> array_size;

		cout << "Enter linkedlist elements:\n";
		vector< int > linkedlist_elements;
		for(int i = 0; i < array_size; i++)
		{
			int input_val;
			cin >> input_val;
			linkedlist_elements.push_back(input_val);
		}
		Node* head = create_linkedlist(linkedlist_elements, 0);

		int sort_type;
		cout << "Ascending or Descending Ordering: Type 1 for Ascending and 0 for Descending\n";
		cin >> sort_type;

		if(sort_type == 1)
		{
			cout << "Before Sorting in Ascending Order:\n";
			traverse_and_print_linked_list_format(head);

			Node* ret_node_asc_test = selection_sort_recursive_ascending(head);

			cout << "-------------------------------\n";
			cout << "After Sorting in Ascending Order:\n";
			if(ret_node_asc_test != NULL)
			{
				traverse_and_print_linked_list_format(ret_node_asc_test);
			}
			else
			{
				cout << "head is NULL" << "\n";
			}
			cout << "====================================\n";
		}
		else
		{
			cout << "Before Sorting in Descending Order:\n";
			traverse_and_print_linked_list_format(head);

			Node* ret_node_desc_test = selection_sort_recursive_descending(head);

			cout << "-------------------------------\n";
			cout << "After Sorting in Descending Order:\n";
			if(ret_node_desc_test != NULL)
			{
				traverse_and_print_linked_list_format(ret_node_desc_test);
			}
			else
			{
				cout << "head is NULL" << "\n";
			}
			cout << "====================================\n";
		}
	}
	else
	{
		sample_test_cases_mode();
	}

	return 0;
}