#include<bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
const int N = 200005;
#define pb push_back
vector<int>gr[N];
vector<int>grr[N];
bool vis[N];
int comp[N];   // stores color of connected components
vector<int>order; // order of finishing
void dfs(int node)
{
	vis[node] = 1;
	for (auto child : gr[node])
	{
		if (!vis[child])
			dfs(child);
	}
	order.pb(node);
}

void dfs_reverse(int node, int col)
{
	comp[node] = col;
	vis[node] = 1;
	for (auto child : grr[node])
	{
		if (!vis[child])
			dfs_reverse(child, col);
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
		grr[y].pb(x);
	}


	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i);
	}


	memset(vis, 0, sizeof(vis));
	int col = 0;
	for (int i = n; i >= 1; i--)
	{
		if (!vis[order[i]])
		{
			dfs_reverse(order[i], col);
			col++;
		}
	}


	for (int i = 1; i <= n; i++)
		cout << i << " " << comp[i] << endl;


}