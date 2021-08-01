#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 100005;
vector<pair<int, int>>gr[N];
vector<int>dis(N + 1, 1e9);
vector<int>parent(N + 1, 1e9);

void dijsktra(int s, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});

	dis[s] = 0;
	while (!pq.empty())
	{
		pair<int, int>here = pq.top();
		pq.pop();

		int v = here.second;
		int dv = here.first;

		for (auto edge : gr[v])
		{
			if (dv + edge.second < dis[edge.first])
			{
				dis[edge.first] = dv + edge.second;
				pq.push({dis[edge.first], edge.first});
				parent[edge.first] = v;
			}
		}

	}



}
int32_t main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}


	dijsktra(1, n);

	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";


}