#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int del = 0, a = 0, b = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        s[i] == 'a' ? a++ : b++;
        if (min(a, b) <= k)
            ans = max(ans, a + b);
        else s[del++] == 'a' ? a-- : b--;
    }
    cout << ans;
}








