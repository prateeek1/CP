#include<bits/stdc++.h>
using namespace std;


vector<int>adj[100001];
bool vis[100001];


int maxDis, maxNode;

void dfs(int node, int d)
{
	vis[node] = 1;
	if (d > maxDis)
	{
		maxDis = d;
		maxNode = node;
	}


	for (int child : adj[node])
	{
		if (vis[child] == 0)
			dfs(child, d + 1);
	}
}

int main()
{

	int n, a, b;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	maxDis = -1;
	dfs(1, 0);

	memset(vis, 0, sizeof(vis));

	maxDis = -1;
	dfs(maxNode, 0);


	cout << maxDis << endl;




}