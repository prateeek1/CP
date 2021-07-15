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




bool vis[501][501];
int n, m, k;
char a[501][501];


void dfs(int x, int y)
{
    if (x<0 or y<0 or x>n or y>m or vis[x][y] or !k or a[x][y] != '.')
        return;

    vis[x][y] = 1;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);

    if (k)
    {
        a[x][y] = 'X';
        k--;
    }
}






int32_t main()
{

    cin >> n >> m >> k;
    fo(i, n)
    {
        fo(j, m)
        {
            cin >> a[i][j];
        }
    }

    fo (i, n)
    {
        fo (j, m)
        {
            if (!vis[i][j] and k)
                dfs(i, j);
        }
    }


    fo(i, n)
    {
        fo(j, m)
        {
            cout << a[i][j];

        }
        cout << endl;
    }

}