#include<bits/stdc++.h>
using namespace std;

int dp[3005][2], n, a[3005], b[3005], c[3005];

int solve(int pos, int state) {

	if (pos == n - 1) {
		if (state == 0)
			return a[pos];
		else return b[pos];
	}
	int &res = dp[pos][state];
	if (res != -1)
		return res;
	res = 0;

	if (state == 0) {
		res = max(solve(pos + 1, 1) + a[pos], solve(pos + 1, 0) + b[pos]);
	}
	else {
		res = max(solve(pos + 1, 1) + b[pos], solve(pos + 1, 0) + c[pos]);
	}
	return res;
}


int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	for (int i = 0; i < n; i++)cin >> c[i];


	cout << solve(0, 0) << endl;
}
