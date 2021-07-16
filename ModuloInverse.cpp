#include<bits/stdc++.h>
using namespace std;
#define int long long int

// finding a number such that when multiplied by a and modulo under m gives 1

int power(int a, int n, int mod)
{
	int res = 1;
	while (n)
	{
		if (n % 2)
			res = (res * a) % mod;

		n /= 2;
		a = (a * a) % mod;
	}

	return res;
}

int modinverse(int a, int m) // gcd of a and m should be 1
{
	return power(a, m - 2, m);
}

int32_t main()
{
	int a, m;
	cin >> a >> m;
	cout << modinverse(a, m);    // (a*a^-1)%m=1
}