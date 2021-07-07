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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll x = abs(a - b);

        if (x == 0)
        {
            cout << 0 << " " << 0 << endl;
            continue;
        }

        if (__gcd(a, b) == x)
        {
            cout << x << " " << 0 << endl;
            continue;
        }

        ll y = min(a, b);
        y = y % x;
        ll z = min(y, x - y);
        cout << x << " " << z << endl;


    }

}





























