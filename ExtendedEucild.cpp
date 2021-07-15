#include<bits/stdc++.h>
using namespace std;
#define int long long int

int gcdExtended(int a, int b, int &x, int &y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtended(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return gcd;
}

int32_t main()
{
	int x, y, a, b;

	cin >> a >> b;

	cout << gcdExtended(a, b, x, y) << endl;
	cout << x << " " << y << endl;
}