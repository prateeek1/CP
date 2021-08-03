#include<bits/stdc++.h>
using namespace std;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while (idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while (idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}


	void updateMax(int idx, int val)
	{
		while (idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while (idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}


};

int main()
{
	int n;
	cin >> n;

	int a[n];
	BIT b;
	b.init(n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		b.update(i, x);
	}


	// int q;
	// cin >> q;

	// while (q--)
	// {
	// 	int l, r;
	// 	cin >> l >> r;
	// 	cout << b.rsum(l, r) << endl;
	// }


	cout << b.prefMax(9) << endl;
}