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
#define foo(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long int
#define mod 1000000007
//long long inf = 100000000001;
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

const int inf = 2e9;
const int N = 2e5;
int fo[N];
int fe[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        foo(i, n)
        cin >> a[i];

        memset(fo, 0, sizeof(fo));
        memset(fe, 0, sizeof(fe));

        foo (i, n)
        {
            if (i % 2 == 0)
                fe[a[i]]++;
            else
                fo[a[i]]++;
        }

        sort(a, a + n);
        foo(i, n)
        {
            if (i % 2 == 0)
                fe[a[i]]--;
            else
                fo[a[i]]--;
        }

        bool f = true;
        foo(i, N)
        {
            if (fo[i] or fe[i])
            {
                f = false;
            }
        }

        if (f == true)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;


    }
}
