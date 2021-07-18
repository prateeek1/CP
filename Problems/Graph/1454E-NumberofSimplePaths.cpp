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

#define MOD 998244353
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


int32_t main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<set<int>>gr(n);

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            gr[x].insert(y);
            gr[y].insert(x);
        }

        vector<int>val(n, 1);
        queue<int>q;

        for (int i = 0; i < n; i++)
        {
            if (gr[i].size() == 1)
                q.push(i);
        }


        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            int to = *gr[v].begin();
            val[to] += val[v];
            val[v] = 0;
            gr[v].clear();
            gr[to].erase(v);
            if (gr[to].size() == 1) {
                q.push(to);


            }
        }


        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += val[i] * 1ll * (val[i] - 1) / 2;
            ans += (val[i] * 1ll * (n - val[i]));

        }


        cout << ans << endl;
    }

}












