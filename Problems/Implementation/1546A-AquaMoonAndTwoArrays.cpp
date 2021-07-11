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
        int n;
        cin >> n;
        int a[n];
        int b[n];

        vector<int>pos;
        vector<int>neg;

        fo(i, n)
        cin >> a[i];

        fo(i, n)
        cin >> b[i];

        // fo(i, n)
        //cout << a[i] - b[i] << " ";

        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] > 0)
            {
                int m = abs(a[i] - b[i]);
                for (int j = 0; j < m; j++)
                {
                    neg.push_back(i + 1);
                }
            }

            if ((a[i] - b[i]) < 0)
            {
                int m = abs(a[i] - b[i]);
                fo(j, m)
                {
                    pos.push_back(i + 1);
                }
            }
        }

        //cout << neg.size() << pos.size() << endl;
        if (neg.size() == pos.size())
        {
            cout << neg.size() << endl;
            for (int i = 0; i < neg.size(); i++)
                cout << neg[i] << " " << pos[i] << endl;

            //cout << endl;

        }

        else
            cout << -1 << endl;




    }
}
