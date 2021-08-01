// If we remove an vertex from graph and number of connected components increases then that vertex is articulation point

// If we remove an edge from graph and number of connected components increases then that edge is bridge


#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 100005;
vector<int>gr[N];
int disc[N];
int low[N];
int tme;
set<int>art;
vector<pair<int, int>>bridges;
void dfs(int cur, int par)
{
	disc[cur] = low[cur] = tme++;
	int no_child = 0;

	for (auto child : gr[cur])
	{
		if (disc[child] == 0)
		{
			dfs(child, cur);
			no_child++;
			low[cur] = min(low[cur], low[child]);

			if (par != 0 and low[child] >= disc[cur])
			{
				art.insert(cur);
			}

			if (low[child] > disc[cur])
			{
				bridges.pb({cur, child});
			}

		}
		else if (child != par)
		{
			//backedge
			low[cur] = min(low[cur], disc[child]);

		}
	}

	if (par == 0 and no_child >= 2)
	{
		art.insert(cur);
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

	tme = 1;
	dfs(1, 0);

	for (auto it : art)
		cout << it << " ";
}



