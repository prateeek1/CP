
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
const int N = 5e4 + 5;
int dp[5001][5001];

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[m][1] = sum[m];

    int lim;

    for (int i = m + 1; i <= n; i++)
    {
        lim = i / m;
        for (int j = 1; j <= min(lim, k); j++)
        {


            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);

        }
    }


    cout << dp[n][k] << endl;



}

