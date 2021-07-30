#include<bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,n) for(int i=1;i<=n;i++)
using namespace std;
#define mod 1000000007
long long inf = 100000000001;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define int long long int
const int MOD = 998244353;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
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


/*int firstDigit(int n)
{
    // Find total number of digits - 1
    int digits = (int)log10(n);

    // Find first digit
    n = (int)(n / pow(10, digits));

    // Return first digit
    return n;
}*/

/*int ncr(int n, int r)
{
    if (r > n)
        return 0;

    int res = fact[n];
    res = (res * power(fact[r], mod - 2)) % mod;
    res = (res * power(fact[n - r], mod - 2)) % mod;

    return res;
}*/


vector<int>primes;

int dp[1005][1005];

int solve(int i, int j, int n, int k, int a[])
{

    if (k == 0)
    {
        if (a[i] != a[j])
        {
            return  dp[i][k] = 0;

        }
    }

    if (i > (n - 1))
        return  0;

    if (dp[i][k] != -1)
        return dp[i][k];



    int cn = 0;
    if ( i > 0 and a[i] != a[j])
    {
        cn = 1;
    }


    return  dp[i][k] = max(solve(i + 1, i, n, k - cn, a) + 1, solve(i + 1, j, n, k, a) );

}


int32_t main() {

    fast;
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif


    int t;
    cin >> t;
    while (t--)
    {   int n;

        cin >> n;
        int a[n];

        int xorr = 0;
        fo(i, n)
        {
            cin >> a[i];
            xorr = xorr ^ a[i];

        }


        if (xorr == 0)
            cout << "Yes" << endl;
        else
        {
            int cnt = 0;
            int currxor = 0;

            for (int i = 0; i < n; i++)
            {
                currxor ^= a[i];


                if (currxor == xorr)
                {
                    currxor = 0;
                    cnt++;
                }
            }



            if (cnt > 2 and  currxor == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }




}










