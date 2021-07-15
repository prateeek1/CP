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

int a[N];
int n;
bool check(vector<int>v)
{

    int n = v.size();


    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((v[i] >= v[j] and v[j] >= v[k]) or (v[i] <= v[j] and v[j] <= v[k]) )
                    return true;
            }
        }
    }

    return false;
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        fo(i, n)
        cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int>v;
            for (int j = i; j < n; j++)
            {
                v.pb(a[j]);
                if (check(v))
                    break;

                ans++;
            }
        }

        cout << ans << endl;

    }

    return 0;
}


