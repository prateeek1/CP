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
        int high;
        int low;
        high = low = m;
        bool flag = 1;
        int lst = 0;

        fo(i, n)
        {
            int t, l, h;
            cin >> t >> l >> h;

            high += t - lst;
            low -= t - lst;


            high = min(h, high);
            low = max(low, l);

            if (high < low)
                flag = 0;


            lst = t;



        }
        if (flag)
            cout << "YES" << endl;


        else cout << "NO" << endl;


    }

}











