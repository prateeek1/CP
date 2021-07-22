#include<bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
const int N = 200005;
#define pb push_back
vector<int>gr[N];

void bfs(int src, int n, int &ans)
{
	vector<int>dis(n + 1, INT_MAX);
	queue<int>q;
	dis[src] = 0;
	q.push(src);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (auto child : gr[curr])
		{
			if (dis[child] == INT_MAX)
			{	// not visited
				dis[child] = dis[curr] + 1;
				q.push(child);
			}
			else if (dis[child] >= dis[curr]) // checks so we dont take parent
			{
				ans = min(ans, dis[child] + dis[curr] + 1);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	int ans = inf;
	for (int i = 1; i <= n; i++)
		bfs(i, n, ans);

	if (ans == inf)
		cout << "no cycle" << endl;
	else
		cout << ans << endl;
}