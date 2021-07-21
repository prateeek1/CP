#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<map>
#include<cstring>
#include<math.h>
#include<queue>
#include<set>
#include<bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,n) for(int i=1;i<=n;i++)
using namespace std;
#define int long long int
#define mod 1000000007
long long inf = 100000000001;
#define all(v) (v).begin(),(v).end()
#define pb push_back
const int N = 200005;

const int MOD = 998244353;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
int  lcm(int  a, int  b) // Function to calculate Lcm
{
    return (a / __gcd(a, b)) * b;
}
int highestPowerof2(int n) // Highest pow of two
{
    int p = (int)log2(n);
    return (int)pow(2, p);
}

/*int power(int a, int n, int mod)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % mod;

        }
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}*/


/*int binom(int n, int r, int mod)
{
    int res = fact[n];

    res =  (res * power(fact[n - r], mod - 2, mod)) % mod;
    res = (res * power(fact[r], mod - 2, mod)) % mod;

    return res;
}*/


// int firstDigit(int n)
// {
//     // Find total number of digits - 1
//     int digits = (int)log10(n);

//     // Find first digit
//     n = (int)(n / pow(10, digits));

//     // Return first digit
//     return n;
// }


int fact[N];

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


int ncr(int n, int r)
{
    if (r > n)
        return 0;

    int res = fact[n];
    res = (res * power(fact[r], mod - 2)) % mod;
    res = (res * power(fact[n - r], mod - 2)) % mod;

    return res;
}



const int maxx = 200005;
vector<int>gr[maxx];


long double dfs(int node, int par)
{
    long double sum = 0;
    for (auto child : gr[node])
    {
        if (child != par)
        {
            sum += dfs(child, node) + 1;
        }
    }

    if (sum == 0)
        return 0;
    else
        return (sum / (gr[node].size() - (par != -1)));
}


void solve(int n, int i)
{

}

int32_t main() {


    int n, l, r;
    cin >> n >> l >> r;
    int tot = r - l + 1;

    int x0 = tot / 3;
    int x1 = tot / 3;
    int x2 = tot / 3;
    while (tot % 3 != 0)
    {
        if (l % 3 == 1)
            x1++;

        if (l % 3 == 2)
            x2++;

        if (l % 3 == 0)
            x0++;

        l++;
        tot--;
    }




    int dp[n + 1][3];
    memset(dp, 0, sizeof(dp));

    dp[1][0] = x0;
    dp[1][1] = x1;
    dp[1][2] = x2;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = ((dp[i - 1][0] * x0) % mod + (dp[i - 1][1] * x2) % mod + (dp[i - 1][2] * x1) % mod) % mod;

        dp[i][1] = ((dp[i - 1][0] * x1) % mod + (dp[i - 1][1] * x0) % mod + (dp[i - 1][2] * x2) % mod) % mod;


        dp[i][2] = ((dp[i - 1][0] * x2) % mod + (dp[i - 1][1] * x1) % mod + (dp[i - 1][2] * x0) % mod) % mod;
    }




    cout << dp[n][0] << endl;

}

