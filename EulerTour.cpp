#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 100005;
vector<int>gr[N];
int timer;

vector<int>tour;
int tin[N];
int tout[N];

void euler_tour(int cur, int par)
{
	tour.pb(cur);
	tin[cur] = ++timer;
	for (auto x : gr[cur])
	{
		if (x != par)
		{
			euler_tour(x, cur);
		}
	}

	tout[cur] = timer;
	return;
}

// whether x is ancestor
bool is_ancestor(int x, int y)
{

	return tin[x] <= tin[y] and tout[x] >= tout[y];
}


int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	timer = 0;
	euler_tour(1, 0);
	// // for (auto it : tour)
	// // 	cout << it << " ";

	// for (int i = 1; i <= n; i++)
	// 	cout << i << " " << tin[i] << " " << tout[i] << endl;

	if (is_ancestor(1, 7))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}