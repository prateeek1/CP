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
#define ff first
#define ss second
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


const int N = 200005;
vector<int>gr[N];
int vis[N];   // 0 not visited 1 color-1 2 color-2

bool bipartite = 0;  // if 1 then not bipartite
vector<int>v[2];
bool dfs(int node, int par, int col)
{
    vis[node] = col;
    v[col].pb(node);
    for (auto child : gr[node])
    {
        if (vis[child] == 0 and dfs(child, node, 3 - col))
        {
            return 1;
        }
        if (vis[child] != 3 - col)
            return 1;
    }
    return 0;
}

int32_t main() {

    fast;
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif



    string s;
    cin >> s;

    int n = s.length();
    int ans = 0;
    int b = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            b++;
        }

        if (s[i] == 'a')
        {
            ans = (ans + b) % mod;
            b = (b * 2) % mod;
        }
    }


    cout << ans << endl;
}










 