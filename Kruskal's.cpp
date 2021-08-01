#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct dsu
{
	vector<int> par;
	void init(int n)
	{
		par = vector<int> (n + 1, 0);
		for (int i = 1; i <= n; i++)
			par[i] = i;

	}
	int get(int x)
	{
		if (x == par[x])
			return x;

		return par[x] = get(par[x]);
	}

	int unite(int x, int y)
	{
		x = get(x);
		y = get(y);
		if (x != y)
		{
			par[x] = max(par[x], par[y]);
			par[y] = max(par[x], par[y]);
		}
	}
};


// get the minimum spannning tree
int kruskal(vector<vector<int>>edges, int n)
{
	sort(edges.begin(), edges.end());
	dsu G;
	G.init(n);
	int ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int x = edges[i][1];
		int y = edges[i][2];
		int w = edges[i][0];

		if (G.get(x) != G.get(y))
		{

			// can take this edge
			G.unite(x, y);
			// include all edges which doesnt result in a cycle
			ans += w;
		}
	}

	return ans;
}


int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>>edges(m);
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edges[i] = {w, x, y};

	}

	cout << kruskal(edges, n) << endl;
}