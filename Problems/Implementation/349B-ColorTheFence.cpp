#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
const int N = 5e4 + 5;

int32_t main()
{
    int sum;
    cin >> sum;
    vector<int>v;
    fo(i, 9)
    {
        int x;
        cin >> x;
        v.pb(x);
    }

    int mi;
    mi = *min_element(v.begin(), v.end());
    int ans = sum / mi;
    int pos;


    if (ans == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    //cout << "a";
    char a;

    for (int i = 0; i < 9; i++)
    {
        if (v[i] == mi)
            a = '0' + (i + 1);
    }


    string s(ans, a);


    int rem = sum % mi;

    int j = 0;
    for (int i = 8; i >= a - '0'; i-- )
    {
        while (rem + mi >= v[i])
        {
            s[j] = '0' + i + 1;
            j++;
            rem -= (v[i] - mi);
            rem = max(rem, 0ll);
        }
    }

    cout << s << endl;




}


