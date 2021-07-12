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


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        int x, y;
        int n, m;
        cin >> a >> b;
        cin >> x >> y;
        cin >> n >> m;

        int ans = abs(a - x) + abs(b - y);

        if (a == x && a == n && m >= min(b, y) && m <= max(b, y) || b == y && b == m && n >= min(a, x) && n <= max(a, x))
            ans += 2;

        cout << ans << endl;
    }
}



