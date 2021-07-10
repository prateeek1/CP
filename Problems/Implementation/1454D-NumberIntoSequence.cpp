#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll n1 = n;
		ll k = 1;
		ll p = 1;
		for (ll i = 2; i <= sqrt(n); i++)
		{
			ll p1 = 0;
			while (n % i == 0)
			{
				n /= i;
				p1++;
			}
			if (p1 > k)
			{
				k = p1;
				p = i;
			}
		}

		cout << k << "\n";
		for (ll i = 0; i < k - 1; i++)
		{
			cout << p << " ";
			n1 /= p;
		}
		cout << n1 << "\n";
	}
	return 0;

}