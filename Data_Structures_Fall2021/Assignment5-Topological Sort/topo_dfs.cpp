#include <bits/stdc++.h>
using namespace std;

class Vertex
{
	public:
		char child_value;
		int children_count;
		int *children_index;
};

bool dfs(int index, Vertex vertices[], int outdegree[], int visited[], int done[], int solution[], int &n, int ascii_val_starting_char)
{
	if(visited[index] == 1 && done[index] == 0)
	{
		if(ascii_val_starting_char == -1)
		{
			cout << "There exists a cycle involving node: " << index << "\n";
		}
		else
		{
			char char_cyc = (char)(index + ascii_val_starting_char - 1);
			cout << "There exists a cycle involving node: " << char_cyc << "\n";
		}
		return true;
	}
	if(done[index] == 1)
	{
		return false;
	}
	visited[index] = 1;
	if(outdegree[index] == 0)
	{
		solution[n] = index;
		n = n - 1;
		done[index] = 1;
		return false;
	}
	for(int i = 0; i < vertices[index].children_count; i++)
	{
		int children_index = vertices[index].children_index[i];
		bool is_cycle = dfs(children_index, vertices, outdegree, visited, done, solution, n, ascii_val_starting_char);
		if(is_cycle)
		{
			return true;
		}
	}
	solution[n] = index;
	n = n - 1;
	done[index] = 1;

	return false;
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
	int outdegree[num_nodes + 1];
	int parents[num_nodes + 1];
	int visited[num_nodes + 1];
	int done[num_nodes + 1];
	int solution[num_nodes + 1];

	for(int i = 0; i <= num_nodes; i++)
	{
		vertices[i].children_index = new int[num_nodes + 1];
		vertices[i].children_count = 0;
		indegree[i] = 0;
		visited[i] = 0;
		done[i] = 0;
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
		outdegree[source]++;
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
	bool is_cycle = false;
	int n = num_nodes;
	for(int i = 1; i <= num_nodes; i++)
	{
		if(indegree[i] == 0)
		{
			is_cycle = dfs(i, vertices, outdegree, visited, done, solution, n, ascii_val_starting_char);
			if(is_cycle)
			{
				break;
			}
		}
	}

	if(is_cycle)
	{
		cout << "No topological sort is possible since there exists a cycle" << "\n";
	}
	else
	{
		cout << "Topological Ordering: " << "\n";
		for(int i = 1; i <= num_nodes; i++)
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