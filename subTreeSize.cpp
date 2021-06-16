
// SIZE OF SUBTREE in 0(N)

#include<bits/stdc++.h>
using namespace std;


vector<int>adj[100001];
bool vis[100001];
int subSize[100001];

int dfs(int node)
{
	vis[node] = 1;
	int curr = 1;
	for (int child : adj[node])
	{
		if (vis[child] == 0)
		{
			curr += dfs(child);
		}
	}
	subSize[node] = curr;
	return curr;
}


