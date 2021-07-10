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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int sum;
        int mp[n + 1] = {0};
        int cnt = 0;
        fo(i, n)
        {

            cin >> a[i];

            mp[a[i]]++;

        }

        for (int i = 0; i < n - 1; i++)
        {
            sum = a[i];
            for (int j = i + 1; j < n; j++)
            {
                sum += a[j];
                if (sum <= n)
                {



                    cnt += mp[sum];

                    mp[sum] = 0;
                }
            }
        }

        cout << cnt << endl;



    }
}





