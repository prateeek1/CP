#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<map>
#include<cstring>
#include<math.h>
using namespace std;
#define ll long long int

int MOD = 1000000007;


long long int n;
ll dp[100005][2];
string s[100005], r[100005];
int main ()
{

    cin >> n;
    ll c[n];
    for (ll i = 0; i < n; i++)
        cin >> c[i];

    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = 1e15;
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (ll i = 0; i < n; i++)
    {
        if (s[i] >= s[i - 1])
            dp[i][0] = min(dp[i - 1][0], dp[i][0]);

        if (s[i] >= r[i - 1])
            dp[i][0] = min(dp[i - 1][1], dp[i][0]);

        if (r[i] >= s[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);

        if (r[i] >= r[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);

        if (dp[i][0] >= 1e15 && dp[i][1] >= 1e15)
        {
            cout << -1 << endl;
            return 0;
        }


    }


    cout << min(dp[n - 1][0], dp[n - 1][1]);









}