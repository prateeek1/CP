#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int t, n, m;
string g[105];
int main()
{
	cin >> n;
	long long ans = 1, p = 1;
	for (int i = 2; i <= n; i++) ans = (ans * i) % MOD, p = (p << 1) % MOD;
	cout << (ans - p + MOD) % MOD;
	return 0;
}