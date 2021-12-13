#include <bits/stdc++.h>
using namespace std;

class EdgeNode
{
	public:
		int node_index;
		int weight;
};

class ComparePriorityQueueElements
{
	public:
		bool operator() (const EdgeNode &edge_1, const EdgeNode &edge_2)
		{
			if(edge_1.weight > edge_2.weight)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class Vertex
{
	public:
		int children_count;
		int *children_index;
		int *children_weight;
};

int main()
{
	int num_nodes;
	cout << "Input number of nodes: " << "\n";
	cin >> num_nodes;
	int num_edges;
	cout << "Input number of edges: " << "\n";
	cin >> num_edges;
	Vertex *vertices = new Vertex[num_nodes];
	int shortest_distance[num_nodes + 1];
	int parents[num_nodes + 1];
	bool visited[num_nodes + 1];
	int visited_count = 0;
	for(int i = 0; i <= num_nodes; i++)
	{
		vertices[i].children_index = new int[num_nodes + 1];
		vertices[i].children_weight = new int[num_nodes + 1];
		vertices[i].children_count = 0;
		shortest_distance[i] = 10000000;
		visited[i] = false;
	}
	cout << "Input the edge pairs: " << "\n";
	for(int i = 0; i < num_edges; i++)
	{
		int source, destination, weight;
		cin >> source >> destination >> weight;
		int children_count = vertices[source].children_count;
		vertices[source].children_index[children_count] = destination;
		vertices[source].children_weight[children_count] = weight;
		vertices[source].children_count += 1;
	}
	
	cout << "==============================" << "\n";
	cout << "Original Graph Edge Pairs:" << "\n";
	for(int i = 1; i <= num_nodes; i++)
	{
		for(int j = 0; j < vertices[i].children_count; j++)
		{
			cout << "Source: " << i << " - Destination: " << vertices[i].children_index[j] << " - Weight: " << vertices[i].children_weight[j] << "\n";
		}
	}
	cout << "==============================" << "\n";
	
	int graph_source;
	cout << "Enter the graph source node:" << "\n";
	cin >> graph_source;
	priority_queue< EdgeNode, vector< EdgeNode >, ComparePriorityQueueElements > edges_pq;
	EdgeNode *source_node_cost = new EdgeNode;
	source_node_cost -> node_index = graph_source;
	source_node_cost -> weight = 0;
	edges_pq.push(*source_node_cost);
	int tree_node_1[num_nodes + 1];
	int tree_node_2[num_nodes + 1];
	int tree_edge_weight[num_nodes + 1];
	int tree_node_count = 0;
	
	while(!edges_pq.empty() and visited_count != num_nodes)
	{
		EdgeNode top_edge = edges_pq.top();
		if(!visited[top_edge.node_index])
		{
			int source = top_edge.node_index;
			visited[source] = true;
			visited_count += 1;
			shortest_distance[source] = top_edge.weight;
			if(source != graph_source)
			{
				tree_node_1[tree_node_count] = parents[source];
				tree_node_2[tree_node_count] = source;
				tree_edge_weight[tree_node_count] = shortest_distance[source];
				tree_node_count += 1;
			}
			for(int j = 0; j < vertices[source].children_count; j++)
			{
				int destination = vertices[source].children_index[j];
				int weight = vertices[source].children_weight[j];
				if(!visited[destination])
				{
					if(shortest_distance[source] + weight <= shortest_distance[destination])
					{
						shortest_distance[destination] = shortest_distance[source] + weight;
						EdgeNode *new_edge = new EdgeNode;
						new_edge -> node_index = destination;
						new_edge -> weight = shortest_distance[destination];
						edges_pq.push(*new_edge);
						parents[destination] = source;
					}
				}
			}
		}
		else
		{
			edges_pq.pop();
		}
	}
	cout << "------------------------------" << "\n";
	cout << "==============================" << "\n";
	cout << "Dijkstra Tree Edge Pairs:" << "\n";
	for(int i = 0; i < tree_node_count; i++)
	{
		cout << "Source: " << tree_node_1[i] << " - Destination: " << tree_node_2[i] << " - Weight: " << tree_edge_weight[i] << "\n";
	}
	cout << "==============================" << "\n";
	cout << "------------------------------" << "\n";
	cout << "==============================" << "\n";
	cout << "Vertices And Their Shortest Distances Cost:" << "\n";
	for(int i = 1; i <= num_nodes; i++)
	{
		cout << "Node: " << i << " - Shortest Distance Length: " << shortest_distance[i] << "\n";
	}
	cout << "==============================" << "\n";
	cout << "------------------------------" << "\n";
	return 0;
}