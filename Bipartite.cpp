#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
#define pb push_back
vector<int>gr[N];
int vis[N];   // 0 not visited 1 color-1 2 color-2

bool bipartite = 0;  // if 1 then not bipartite
void dfs(int node, int par, int col)
{
	vis[node] = col;
	for (auto child : gr[node])
	{
		if (vis[child] == 0)
		{
			dfs(child, node, 3 - col);
		}
		else if (child != par  and col == vis[child])
		{
			// backedge
			bipartite = 1;
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


	dfs(1, 0, 1);

	if (bipartite)
		cout << " Not biparite";
	else
		cout << " bipartite";
}