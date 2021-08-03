
#include<bits/stdc++.h>
using namespace std;

// O(N)
// the z-function is an array of length n where the i-th element is equal  to the greatest number of characters starting from rhe position i that coincides with the first characters of s
vector<int> z_algo(string s)
{
	int n = s.length();
	int l = 0;
	int r = 0;
	vector<int>z(n);

	for (int i = 1; i < n; i++)
	{
		if (i <= r)
		{
			z[i] = min(z[i - l], r - i + 1);
		}

		while (i + z[i] < n and s[z[i]] == s[i + z[i]])
			z[i]++;

		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}



int main()
{
	string str;
	cin >> str;

	vector<int>z = z_algo(str);

	for (auto it : z)
		cout << it << " ";
}