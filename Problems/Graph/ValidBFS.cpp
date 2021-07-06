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
#define ll long long int
#define mod 1000000007
long long inf = 100000000001;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
ll lcm(ll a, ll b) // Function to calculate Lcm
{
    return (a / __gcd(a, b)) * b;
}
int highestPowerof2(int n) // Highest pow of two
{
    int p = (int)log2(n);
    return (int)pow(2, p);
}
void solve()
{

}
map<ll, ll>mp[200005];
ll a[200005];
int main()
{
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        mp[x][y] = 1;
        mp[y][x] = 1;
    }

    fo(i, n)
    {
        cin >> a[i];
    }
    int i, j;

    for ( i = 0,  j = 1; i < n; i++) {
        while (mp[a[i]][a[j]])
            j++;
    }
    if (j == n && a[0] == 1)
        cout << "Yes";
    else
        cout << "No";
}











