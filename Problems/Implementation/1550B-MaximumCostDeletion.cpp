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
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
#define int long long int
#define mod 1000000007
long long inf = 100000000001;
#define pb push_back
const int N = 5e4 + 5;

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


void solve()
{

}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {

        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int ele1 = 0;
        int ele0 = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] != '1')
                ele1++;

            if (s[i] == '0' && s[i + 1] != '0')
                ele0++;

        }

        if (s[n - 1] == '1')
            ele1++;
        else
            ele0++;

        int ele = min(ele1, ele0);
        ele++;


        // cout << ele1 << " " << ele0 << endl;


        int ans = max(n * b, ele * b);


        cout << ans + n*a << endl;

    }
    return 0;
}


