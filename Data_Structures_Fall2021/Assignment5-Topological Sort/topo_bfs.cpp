#include <bits/stdc++.h>
using namespace std;

class Vertex
{
	public:
		int children_count;
		int *children_index;
};

class Node
{
	public:
		int index;
		Node* next;
};

Node *head = NULL;
Node *tail = NULL;

void bfs(int index, Vertex vertices[], int indegree[], int visited[], int solution[], int &visited_count, int ascii_val_starting_char)
{
	visited[index] = true;
	head = head -> next;
	if(head == NULL)
	{
		tail = NULL;
	}
	solution[visited_count] = index;
	visited_count++;
	for(int i = 0; i < vertices[index].children_count; i++)
	{
		int child_index = vertices[index].children_index[i];
		indegree[child_index]--;
		if(indegree[child_index] == 0)
		{
			Node *node = new Node();
			node -> index = child_index;
			node -> next = NULL;
			if(tail == NULL)
			{
				head = node;
				tail = node;
			}
			else
			{
				tail -> next = node;
				tail = node;
			}
		}
	}
}

int main()
{
	int num_nodes;
	cout << "Input number of nodes: " << "\n";
	cin >> num_nodes;
	int num_edges;
	cout << "Input number of edges: " << "\n";
	cin >> num_edges;

	cout << "Are inputs char values (Press 1 for Yes and 0 for No):" << "\n";
	int is_char_values_possible = 0;
	cin >> is_char_values_possible;
	char starting_char_val;
	int ascii_val_starting_char = -1;
	if(is_char_values_possible)
	{
		cout << "Enter starting char val:\n";
		cin >> starting_char_val;
		ascii_val_starting_char = (int)(starting_char_val);
	}

	Vertex *vertices = new Vertex[num_nodes + 1];
	int indegree[num_nodes + 1];
	int parents[num_nodes + 1];
	int visited[num_nodes + 1];
	int solution[num_nodes];
	int visited_count = 0;
	for(int i = 0; i <= num_nodes; i++)
	{
		vertices[i].children_index = new int[num_nodes + 1];
		vertices[i].children_count = 0;
		indegree[i] = 0;
		visited[i] = 0;
	}
	cout << "Input the edge pairs: " << "\n";
	for(int i = 0; i < num_edges; i++)
	{
		int source, destination;
		if(ascii_val_starting_char != -1)
		{
			char s_char, d_char;
			cin >> s_char >> d_char;
			source = (int)(s_char - starting_char_val) + 1;
			destination = (int)(d_char - starting_char_val) + 1;
		}
		else
		{
			cin >> source >> destination;
		}
		int children_count = vertices[source].children_count;
		vertices[source].children_index[children_count] = destination;
		vertices[source].children_count += 1;
		indegree[destination]++;
	}
	
	cout << "==============================" << "\n";
	cout << "Original Graph Edge Pairs:" << "\n";
	for(int i = 1; i <= num_nodes; i++)
	{
		for(int j = 0; j < vertices[i].children_count; j++)
		{
			cout << "Source: " << i << " - Destination: " << vertices[i].children_index[j] << "\n";
		}
	}
	cout << "==============================" << "\n";


	cout << "==============================" << "\n";

	for(int i = 1; i <= num_nodes; i++)
	{
		if(indegree[i] == 0)
		{
			Node *node = new Node();
			node -> index = i;
			node -> next = NULL;
			if(tail != NULL)
			{
				tail -> next = node;
				tail = node;
			}
			else
			{
				head = node;
				tail = node;
			}
		}
	}

	while(head != NULL)
	{
		int index = head -> index;
		bfs(index, vertices, indegree, visited, solution, visited_count, ascii_val_starting_char);
	}

	if(visited_count != num_nodes)
	{
		cout << "No topological sort is possible since there exists a cycle" << "\n";
	}
	else
	{
		cout << "Topological Ordering: " << "\n";
		for(int i = 0; i < visited_count; i++)
		{
			if(ascii_val_starting_char == -1)
			{
				cout << solution[i] << " ";
			}
			else
			{
				char sol_char = (char)(solution[i] + ascii_val_starting_char - 1);
				cout << sol_char << " ";
			}
		}
		cout << "\n";
	}
	cout << "==============================" << "\n";
	return 0;
}