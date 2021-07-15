#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define maxN 100001
int spf[maxN];
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < maxN; i++)
		spf[i] = i;


	for (int i = 4; i < maxN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < maxN; i++)
	{

		if (spf[i] == i)
		{
			for (int j = i * i; j < maxN; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

vector<int> primefactor(int x)
{
	vector<int> res;
	while (x != 1)
	{
		res.push_back(spf[x]);
		x = x / spf[x];
	}
	return res;
}


int32_t main()
{
	sieve();
	vector<int>ans = primefactor(10);
	for (auto it : ans)
		cout << it << " ";
}