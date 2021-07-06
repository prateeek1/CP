#include<bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1|1
#define lson ls,l,m
#define rson rs,m+1,r
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int dp[N], a[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, last = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for (int i = 2; i <= n; ++i) {
			if (a[i] < a[i - 1]) last++;
			dp[i] = dp[last] + 1;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}