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
int dp[1001][11][11];

int solve(vector<int>&v, int index, int diff, int prev, int n, vector<int>&ans)
{

    if (dp[index][diff][prev] != -1)
        return dp[index][diff][prev];


    if (index == n)
        return 1;


    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == prev)
            continue;

        if (v[i] <= diff)
            continue;

        int x = solve(v, index + 1, v[i] - diff, v[i], n, ans);

        if (x == 1)
        {
            ans.pb(v[i]);
            return 1;
        }

    }

    dp[index][diff][prev] = 0;
    return 0;

}
int32_t main()
{
    fast;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>zero;
        vector<int>one;
        int ans[n];
        for (int i = 0; i < n; i++)
        {
            int newpos = zero.size() + one.size();
            if (s[i] == '0')
            {
                if (one.empty())
                    zero.pb(newpos);

                else
                {
                    newpos = one.back();
                    one.pop_back();
                    zero.pb(newpos);
                }
            }
            else
            {
                if (zero.empty())
                    one.pb(newpos);

                else
                {
                    newpos = zero.back();
                    zero.pop_back();
                    one.pb(newpos);
                }
            }


            ans[i] = newpos;
        }

        cout << zero.size() + one.size() << endl;
        for (auto it : ans)
            cout << it + 1 << " ";

        cout << endl;


    }
}

