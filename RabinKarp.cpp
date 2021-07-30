#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;


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

int polyHash(string s)
{
	int p = 31;
	int p_powr = 1;
	int hash = 0;

	for (int i = 0; i < s.size(); i++)
	{
		hash += p_powr * (s[i] - 'a' + 1);
		p_powr *= p;
		p_powr %= mod;
		hash %= mod;
	}
	return hash;
}

vector<int> rabinkarp(string a, string b)
{
	int n = a.length();
	int m = b.length();
	int pref[n];
	vector<int>occurences;

	int pat_hash = polyHash(b);

	for (int i = 0; i < n; i++)
	{
		pref[i] = (a[i] - 'a' + 1) * power(31, i);
		pref[i] %= mod;
	}

	for (int i = 1; i < n; i++)
	{
		pref[i] += pref[i - 1];
		pref[i] %= mod;
	}


	for (int i = 0; i + m <= n; i++)
	{
		int new_hash = pref[i + m - 1];

		if (i - 1 >= 0)
			new_hash -= pref[i - 1];

		new_hash += mod;
		new_hash %= mod;

		if (new_hash == pat_hash * power(31, i) % mod)
		{
			occurences.push_back(i);
		}

	}

	return occurences;
}




int32_t main()
{
	string a = "abababbabab";
	string b = "aba";


	vector<int>ans = rabinkarp(a, b);

	for (auto it : ans)
		cout << it << " " << endl;



}
