#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
const int N = 5e4 + 5;
int dp[5001][5001];
#define MOD 998244353
int  fact[300010];


int power(int a, int n, int mod)
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
}


int binom(int n, int r, int mod)
{
    int res = fact[n];

    res =  (res * power(fact[n - r], mod - 2, mod)) % mod;
    res = (res * power(fact[r], mod - 2, mod)) % mod;

    return res;
}



int32_t main()
{

    int t;
    cin >> t;
    fact[0] = 1;
    fact[1] = 1;


    for (int i = 2; i <= 300010; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int sum0 = 0;
        int sum1 = 0;
        int cnt = 0;





        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cnt++;

            }
            else
            {
                sum0++;
                sum1 += cnt / 2;
                cnt = 0;
            }
        }


        sum1 += cnt / 2;

        cout << binom(sum0 + sum1, sum1, MOD) << endl;
    }


}


