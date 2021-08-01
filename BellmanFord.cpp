#include<bits/stdc++.h>
using namespace std;

//works in O(N^2)
// gives the shortest distance from source node
vector<int> bellman_ford(int n, int src, vector<vector<int>>edges)
{
	// min distance from src to i
	vector<int>dis(n + 1, INT_MAX);

	dis[src] = 0;
	//relax all the edges n-1 times
	for (int i = 0; i < n; i++)
	{
		for (auto it : edges)
		{
			int from = it[0], to = it[1], weight = it[2];
			if (dis[from] != INT_MAX and dis[to] > dis[from] + weight)
			{
				dis[to] = dis[from] + weight;
			}
		}
	}

	// check for negative weight cycle
	for (auto it : edges)
	{
		int from = it[0], to = it[1], weight = it[2];
		if (dis[from] != INT_MAX and dis[to] > dis[from] + weight)
		{
			// negative weight cycle
			cout << -1 << endl;
			exit(0);
		}
	}

	return dis;
}


int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>>edges;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({x, y, w});
	}

	vector<int>dis = bellman_ford(n, 1, edges);

	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";

}