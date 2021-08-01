#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

vector<pair<int, int>>gr[100005];
int vis[100005] = {};

int prim()
{
	priority_queue < pair < int, int> , vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({0, 1});
	int mst = 0;

	while (!pq.empty())
	{
		pair<int, int>best = pq.top();
		pq.pop();

		int weight = best.first;
		int to = best.second;

		if (vis[to]) // not an active edge
			continue;

		mst += weight;
		vis[to] = 1;

		for (auto x : gr[to])
		{
			if (vis[x.first] == 0)
				pq.push({x.second, x.first});
		}
	}

	return mst;
}


int32_t main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].pb({y, w});
		gr[y].pb({x, w});
	}

	cout << prim() << endl;

}