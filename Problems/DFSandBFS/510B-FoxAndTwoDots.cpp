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

const int MOD = 998244353;
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



const int maxx = 200005;
vector<int>gr[maxx];


long double dfs(int node, int par)
{
    long double sum = 0;
    for (auto child : gr[node])
    {
        if (child != par)
        {
            sum += dfs(child, node) + 1;
        }
    }

    if (sum == 0)
        return 0;
    else
        return (sum / (gr[node].size() - (par != -1)));
}


int n, m;
bool vis[55][55];


char a[55][55];

void dfs(int i, int j, int x, int y)
{
    if (a[i][j] != a[x][y])
        return;

    if (vis[i][j])
    {
        cout << "Yes" << endl;
        exit(0);
    }

    vis[i][j] = true;
    if (i - 1 >= 0 and i - 1 != x)dfs(i - 1, j, i, j);
    if (j - 1 >= 0 and j - 1 != y)dfs(i, j - 1, i, j);

    if (i + 1 < n and i + 1 != x) dfs(i + 1, j, i, j);
    if (j + 1 < m and j + 1 != y) dfs(i, j + 1, i, j);
}




int32_t main() {

    cin >> n >> m;
    fo(i, n)
    {
        fo(j, m)
        cin >> a[i][j];
    }


    fo(i, n)
    {
        fo(j, m)
        {
            memset(vis, 0, sizeof(vis));

            dfs(i, j, i, j);
        }
    }



    cout << "No" << endl;



}







