#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ComparePQElements
{
	public:
		bool operator() (const pair< int, int > &pair_1, const pair< int, int > &pair_2)
		{
			if(pair_1.second > pair_2.second)
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
		vector< pair< int, int > > children;
};

int main()
{
	int num_nodes;
	cout << "Input number of nodes: " << "\n";
	cin >> num_nodes;
	int num_edges;
	cout << "Input number of edges: " << "\n";
	cin >> num_edges;
	vector< Vertex > vertices(num_nodes + 1);
	int shortest_distance[num_nodes + 1];
	int parents[num_nodes + 1];
	bool visited[num_nodes + 1];
	int visited_count = 0;
	for(int i = 0; i <= num_nodes; i++)
	{
		shortest_distance[i] = 10000000;
		visited[i] = false;
	}
	cout << "Input the edge pairs: " << "\n";
	for(int i = 0; i < num_edges; i++)
	{
		int source, destination, weight;
		cin >> source >> destination >> weight;
		vertices[source].children.push_back(make_pair(destination, weight));
		
	}
	
	cout << "==============================" << "\n";
	cout << "Original Graph Edge Pairs:" << "\n";
	for(int i = 1; i <= num_nodes; i++)
	{
		for(auto x_pair: vertices[i].children)
		{
			cout << "Source: " << i << " - Destination: " << x_pair.first << " - Weight: " << x_pair.second << "\n";
		}
	}
	cout << "==============================" << "\n";
	
	int graph_source;
	cout << "Enter the graph source node:" << "\n";
	cin >> graph_source;
	priority_queue< pair< int, int >, vector< pair< int, int > >, ComparePQElements > edges_pq;
	edges_pq.push(make_pair(graph_source, 0));
	vector< pair< pair< int, int >, int > > tree_edges;
	while(!edges_pq.empty() and visited_count != num_nodes)
	{
		pair< int, int > top_pair = edges_pq.top();
		if(!visited[top_pair.first])
		{
			int source = top_pair.first;
			visited[source] = true;
			visited_count += 1;
			shortest_distance[source] = top_pair.second;
			if(source != graph_source)
			{
				tree_edges.push_back(make_pair(make_pair(parents[source], source), shortest_distance[source]));
			}
			for(auto iter = vertices[source].children.begin(); iter != vertices[source].children.end(); iter++)
			{
				int destination = iter -> first;
				int weight = iter -> second;
				if(!visited[destination])
				{
					if(shortest_distance[source] + weight <= shortest_distance[destination])
					{
						shortest_distance[destination] = shortest_distance[source] + weight;
						edges_pq.push(make_pair(destination, shortest_distance[destination]));
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
	for(auto x: tree_edges)
	{
		cout << "Source: " << x.first.first << " - Destination: " << x.first.second << " - Weight: " << x.second << "\n";
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