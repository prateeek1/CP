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
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
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


#define max 10000005
int mp[max];
int cnt[max];
bool vis[max];
int32_t main()
{
    fast;
    int n;
    cin >> n;
    fo(i, n)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (int i = 2; i < max; i++)
    {
        if (!vis[i])
        {
            for (int j = i; j < max; j += i)
            {
                vis[j] = 1;
                cnt[i] += mp[j];

            }
        }
    }


    for (int i = 2; i < max; i++)
    {
        cnt[i] += cnt[i - 1];
    }


    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (l >= max)
        {
            l = max - 1;
        }
        if (r >= max)
        {
            r = max - 1;
        }

        cout << cnt[r] - cnt[l - 1] << endl;
    }





}






