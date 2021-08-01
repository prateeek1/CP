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

int32_t main()
{
	int n, q;
	cin >> n >> q;
	int l[q], r[q], c[q];

	for (int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i] >> c[i];
	}

	dsu G;
	G.init(n + 2);

	int res[n + 2] = {};
	for (int i = q - 1; i >= 0; i--)
	{
		int index = G.get(l[i]);

		while (index <= r[i])
		{
			res[index] = c[i];
			G.unite(index, index + 1);
			index = G.get(index);
		}

	}


	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
}