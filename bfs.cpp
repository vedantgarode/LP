#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;

	list<int> *adj;

public:
	Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void BFS(int s)
{

	bool visited[V] = {false};
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{

		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
};

int main()
{

	int n;
	cout << "Enter no of nodes :";
	cin >> n;
	Graph g(n);
	cout << "Enter Node connections :" << endl;
	while (true)
	{
		int x, y;
		cin >> x >> y;
		if (x == 0 & y == 0)
		{
			break;
		}
		g.addEdge(x, y);
	}

	int s;
	cout << "Enter start point :" << endl;
	cin >> s;
	cout << "Following is Breadth First Traversal \nstarting from " << s << endl;

	g.BFS(s);
	
	return 0;
}
