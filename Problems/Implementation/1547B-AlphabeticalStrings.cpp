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
        string s;
        cin >> s;

        int n = s.length();



        int l = 0;
        int r = n - 1;


        while (n != 0)
        {


            if (s[l] - 96 == n)
            {
                l++;
                n--;
            }

            else if (s[r] - 96 == n)
            {
                r--;
                n--;
            }
            else
            {
                break;
            }
        }

        //cout << n << endl;






        if (n  == 0 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}



