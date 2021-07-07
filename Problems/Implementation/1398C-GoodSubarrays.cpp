#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> cnt;
        cnt[0] = 1;

        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        long long ans = 0;
        for (char c : s) {
            int val = c - '0';
            sum += val - 1;
            ans += cnt[sum];
            cnt[sum]++;
        }
        cout << ans << '\n';
    }
    return 0;
}





























