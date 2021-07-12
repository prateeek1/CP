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


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n];
        fo(i, n)
        {
            a[i] = inf;
        }


        int b[m];
        fo(i, m)
        {
            cin >> b[i];
        }

        fo(i, m)
        {
            int x;
            cin >> x;
            a[b[i] - 1] = x;

        }
        // fo(i, n)
        //cout << a[i] << " ";
        // cout << endl;

        int l[n];
        int r[n];

        l[0] = a[0];
        r[n - 1] = a[n - 1];
        vector<int>ans(n);

        for (int i = 1; i < n; i++)
        {
            l[i] = min(a[i], l[i - 1] + 1);
        }

        for (int i = n - 2; i >= 0; i--)
            r[i] = min(a[i], r[i + 1] + 1);


        fo(i, n)
        {
            ans[i] = min(l[i], r[i]);
        }


        for (auto it : ans)
            cout << it << " ";

        cout << endl;






    }
}
