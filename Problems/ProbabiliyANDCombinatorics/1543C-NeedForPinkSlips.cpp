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

ld check(ld c, ld m, ld p, ld v, ld len)
{
    ld ans = (p / r) * len;
    if (c > 0)
    {
        if (c > v)
        {
            if (m > 0)
                ans += (c / r) * check(c - v, m + v / 2, p + v / 2, v, len + 1);

            else
                ans += (c / r) * check(c - v, 0, p + v, v, len + 1);

        }
        else
        {
            if (m > 0)
                ans += (c / r) * check(0, m + c / 2, p + c / 2, v, len + 1);
            else
                ans += (c / r) * check(0, 0, p + c, v, len + 1);
        }
    }


    if (m > 0)
    {
        if (m > v)
        {
            if (c > 0)
                ans += (m / r) * check(c + v / 2, m - v, p + v / 2, v, len + 1);

            else
                ans += (m / r) * check(0, m - v, p + v, v, len + 1);

        }
        else
        {
            if (c > 0)
                ans += (m / r) * check(c + m / 2, 0, p + m / 2, v, len + 1);
            else
                ans += (m / r) * check(0, 0, p + m, v, len + 1);
        }
    }

    return ans;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ld c, m, p, v;
        cin >> c >> m >> p >> v;
        c = c * r;
        m = m * r;
        p = p * r;
        v = v * r;
        ld ans = 0;
        ans = check(c, m, p, v, 1);
        cout << setprecision(12) << ans << endl;


    }

}











