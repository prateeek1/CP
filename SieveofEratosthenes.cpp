// sieve of eratosthenes
#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>primes;

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

int32_t main()
{
	int n;
	sieve(100);
	for (auto it : primes)
		cout << it << " ";
}