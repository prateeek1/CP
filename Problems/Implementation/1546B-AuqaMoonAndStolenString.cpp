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
        int n, m;
        cin >> n >> m;
        int dp[m];
        memset(dp, 0, sizeof(dp));


        fo (i, n)
        {

            fo(j, m)
            {
                char a;
                cin >> a;
                //cout << a;
                dp[j] += int(a);
            }
        }

        fo (i, n - 1)
        {

            fo(j, m)
            {
                char a;
                cin >> a;
                dp[j] -= int(a);
            }
        }

        for (int i = 0; i < m; i++)
        {
            cout << char(dp[i]);
        }

        cout << endl;











    }
}
