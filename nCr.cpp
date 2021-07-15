#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define maxN 100001
const int mod = 1e9 + 7;
int fact[maxN];

int power(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2)
		{
			res = (res * a) % mod;
		}
		n /= 2;
		a = (a * a) % mod;
	}
	return res;
}


int ncr(int n, int r)
{
	if (r > n)
		return 0;

	int res = fact[n];
	res = (res * power(fact[r], mod - 2)) % mod;
	res = (res * power(fact[n - r], mod - 2)) % mod;

	return res;
}

int32_t main()
{
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= maxN; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}

	int n, r;
	cin >> n >> r;
	cout << fact[n] << endl;
	cout << ncr(n, r);
}