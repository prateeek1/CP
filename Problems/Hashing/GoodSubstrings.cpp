#include <bits/stdc++.h>
using namespace std;
set<long long> s;
int main() {
	string S, H; cin >> S >> H; int l = S.length();
	long long k; cin >> k;
	for (int i = 0; i < l; i++)
	{
		long long ct = 0, HASH = 0;
		for (int j = i; j < l; j++)
		{
			if (H[S[j] - 'a'] == '0') ct++;
			if (ct > k) break;
			HASH *= 101LL, HASH += S[j];
			s.insert(HASH);
		}
	}
	cout << s.size();
	return 0;
}