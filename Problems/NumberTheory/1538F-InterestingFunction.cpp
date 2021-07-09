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
#define ld long double
const ld r = 1e+9;
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


ll solve(ll l, ll r)
{
    ll ans = 0;
    while (l || r)
    {
        ans += (r - l);
        r /= 10;
        l /= 10;
    }
    return ans;
}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        ll l, r;
        cin >> l >> r;
        ll ans = solve(l, r);
        cout << ans << endl;
    }
}




















