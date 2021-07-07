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
    ll k;
    cin >> k;
    string s = "codeforces";
    ll val[11];
    for (ll i = 0; i < 10; i++)
        val[i] = 1;

    ll prod = 1;
    while (prod < k)
    {
        for (ll i = 0; i < 10; i++)
        {
            val[i]++;
            prod = prod / (val[i] - 1);
            prod *= val[i];

            if (prod >= k)
                break;
        }
    }
    for (ll i = 0; i < 10; i++)
    {
        while (val[i] > 0)
        {
            cout << s[i];
            val[i]--;
        }

    }


}








































