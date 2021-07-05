#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<map>
#include<cstring>
#include<math.h>
using namespace std;

int MOD = 1000000007;


bool dp[200001];
int main ()
{

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = a[i];
        for (int j = 200000; j >= 0; j--)if (dp[j])dp[u + j] = true;

    }
    if (!dp[sum / 2])
    {
        cout << 0 << endl;
        return 0;
    }
    //for (int i = 0; i <= 15; i++)
    //  cout << dp[i] << " ";
    int mx = 1000, ans;
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        while ((a[i] % 2) == 0) {
            d++;
            a[i] /= 2;
        }
        if (d < mx) {
            mx = d;
            ans = i + 1;
        }
    }
    cout << 1 << endl << ans;



}