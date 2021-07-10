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
        int k, n, m;
        cin >> k >> n >> m;

        vector<int>a(n);
        vector<int>b(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];


        bool f = true;
        vector<int>ans;
        int i = 0;
        int j = 0;

        while (1)
        {
            if (i < n && a[i] <= k)
            {
                if (a[i] == 0)
                    k++;
                ans.pb(a[i]);
                i++;
            }

            else if (j < m && b[j] <= k)
            {
                if (b[j] == 0)
                    k++;
                ans.pb(b[j]);
                j++;
            }
            else
                break;

        }


        if (i < n || j < m)
            cout << -1 << endl;

        else
        {
            for (auto it : ans)
                cout << it << " ";

            cout << endl;
        }
    }
}


