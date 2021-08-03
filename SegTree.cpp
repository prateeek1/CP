#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct seg
{
	int N;
	vector<int>tree;
	vector<int>lazy;
	vector<int>a;
	void init(vector<int>s)
	{
		N = s.size();
		a.resize(N);

		for (int i = 0; i < N; i++)
		{
			a[i] = s[i];
		}
		tree.resize(4 * N + 5);
		lazy.assign(4 * N + 5, 0);

		buildTree(0, N - 1, 1);

	}

	void buildTree( int s, int e , int index)
	{
		if (s == e)
		{
			tree[index] = a[s];
			return;
		}

		int mid = (s + e) / 2;

		buildTree( s, mid, 2 * index);
		buildTree( mid + 1, e, 2 * index + 1);


		tree[index] =	min(tree[2 * index], tree[2 * index + 1]);  //operation that is needed to be done
		return;
	}

	int queryTree(int s, int e, int qs, int qe, int index)
	{
		if (s >= qs and e <= qe )
			return tree[index];

		if (qe<s or  qs>e)
			return INT_MAX;

		int mid = (s + e) / 2;

		int left = queryTree( s, mid, qs, qe, 2 * index);
		int right = queryTree( mid + 1, e, qs, qe, 2 * index + 1);

		return min(left, right);  //operation that is needed
	}

	void updateTree(int ss, int se, int i, int increment, int index)
	{
		if (i > se or i < ss)
			return ;
		if (ss == se)
		{
			tree[index] += increment; //update needed
			return;
		}

		int mid = (ss + se) / 2;

		updateTree(ss, mid, i, increment, 2 * index);
		updateTree(mid + 1, se, i, increment, 2 * index + 1);
		tree[index] = min(tree[2 * index], tree[2 * index + 1]); //update needed

	}


	void updateLazy(int ss, int se, int l, int r, int inc, int index)
	{
		if (lazy[index] != 0)
		{
			tree[index] += lazy[index];

			if (ss != se)
			{
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}

		if (ss > r or l > se)
		{
			return;
		}

		if (ss >= l and se <= r)
		{
			tree[index] += inc;
			if (ss != se)
			{
				lazy[2 * index] += inc;
				lazy[2 * index + 1] += inc;
			}
			return;
		}

		int mid = (ss + se) / 2;
		updateLazy(ss, mid, l, r, inc, 2 * index);
		updateLazy(mid + 1, se, l, r, inc, 2 * index + 1);
		tree[index] = min(tree[2 * index], tree[2 * index + 1]); // update needed
		return;
	}


	int queryLazy(int ss, int se, int qs, int qe, int index)
	{
		if (lazy[index] != 0)
		{
			tree[index] += lazy[index];

			if (ss != se)
			{
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}

		if (ss > qe or se < qs )
			return INT_MAX;


		if (ss >= qs and se <= qe)
		{
			return tree[index];
		}

		int mid = (ss + se) / 2;
		int left = queryLazy(ss, mid, qs, qe, 2 * index);
		int right = queryLazy(mid + 1, se, qs, qe, 2 * index + 1);

		return min(left, right);  // operation needed
	}


	void build()
	{
		buildTree(0, N - 1, 1);
	}

	void update(int i, int upd)
	{
		updateTree(0, N - 1, i, upd, 1);
	}

	int query(int l, int r)
	{
		queryTree(0, N - 1, l, r, 1);
	}

	void rangeUpdate(int l, int r, int upd)
	{
		updateLazy(0, N - 1, l, r, upd, 1);
	}

	int rangeQuery(int l, int r)
	{
		queryLazy(0, N - 1, l, r, 1);
	}

};







int main()
{


	int n;
	cin >> n;
	vector<int>a;


	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		a.pb(x);
	}

	seg tree;

	tree.init(a);

	tree.rangeUpdate(1, 4, 10);

	cout << tree.rangeQuery(1, 4) << endl;


}