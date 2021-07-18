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

        vector<int>a;
        vector<int>b;
        int sum1 = 0;
        int sum2 = 0;
        fo(i, n)
        {
            int x;
            cin >> x;
            a.pb(x);
        }

        fo(i, n)
        {
            int x;
            cin >> x;
            b.pb(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int cnt = a.size() / 4;
        for (int i = 0; i < a.size() - cnt; i++)
        {

            sum2 += b[i];
        }

        for (int i = cnt; i < a.size(); i++)
            sum1 += a[i];


        if (sum1 >= sum2)
        {
            cout << 0 << endl;
            continue;
        }


        int l[n];
        int r[n];
        l[0] = a[0];
        r[0] = b[0];

        for (int i = 1; i < n; i++)
        {
            l[i] = l[i - 1] + a[i];
            r[i] = r[i - 1] + b[i];

        }

        int pb1 = 0;
        int as = a.size();
        int bs = b.size();

        while (sum1 < sum2)
        {
            as++;
            bs++;
            pb1 += 1;

            int cnt = as / 4;

            if (cnt != 0)
            {
                sum1 = l[n - 1] - l[cnt - 1];
                sum1 += pb1 * 100;

                int j = min(bs - cnt, n);
                sum2 = r[j - 1];

            }

            if (cnt == 0)
            {
                sum1 += 100;
                sum2 = r[n - 1];
            }

            //cout << sum1 << " " << sum2 << endl;


        }

        cout << as - n << endl;

    }




}







