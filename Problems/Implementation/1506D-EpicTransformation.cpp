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
int32_t main() {

    int t;
    cin >> t;

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    while (t--)
    {
        int n;

        cin >> n;
        int ans = 0;
        map<int, int>mp;
        fo(i, n)
        {
            int x;
            cin >> x;
            mp[x]++;
            ans = max(ans, mp[x]);
        }
        cout << max(n % 2, 2 * ans - n) << endl;
    }

}








