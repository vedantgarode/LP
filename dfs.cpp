#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	void DFS(int v)
	{

		visited[v] = true;
		cout << v << " ";
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				DFS(*i);
	}
	
};
int main()
{

	Graph g;
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
	cout << "Following is Depth First Traversal"
			" starting from vertex "
		 << s << endl;
	g.DFS(s);

	return 0;
}
