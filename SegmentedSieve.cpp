// segmented sieve
#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>primes;
vector<int>segprimes;
void sieve(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primes.push_back(p);
}

void segsieve(int l, int r)
{
	if (l == 1)
		l++;
	int maxN = r - l + 1;
	bool prime[maxN + 1];
	memset(prime, 0, sizeof(prime));
	for (int  it : primes)
	{
		if (it * it <= r)
		{
			int i = (l / it) * it;
			if (i < l)
				i += it;

			for (; i <= r; i += it)
			{
				if (i != it)
					prime[i - l] = 1;
			}
		}
	}
	for (int i = 0; i < maxN; i++)
	{
		if (prime[i] == 0)
			segprimes.push_back(i + l);
	}
}

int32_t main()
{

	sieve(100);
	segsieve(10, 20);
	for (auto it : segprimes)
		cout << it << " ";

}