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

const int MX = 5005;
ll n;
ll dp[5005];
ll seg[5005][5005];
ll a[MX];
ll b[MX];
ll sum[MX];

ll reverseSeg(ll l, ll r)
{
    if (seg[l][r])
        return seg[l][r];
    if (l == r)
        return a[l] * b[r];
    if (l > r)
        return 0;

    return seg[l][r] = reverseSeg(l + 1, r - 1) + a[l] * b[r] + a[r] * b[l];
}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        cin >> b[i];

    for (ll i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i] * b[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], sum[j - 1] + reverseSeg(j, i));
        }
    }


    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i] + sum[n] - sum[i]);
    }

    cout << ans << endl;


}
