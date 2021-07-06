#include<bits/stdc++.h>
#define ll long long
using namespace std;
int v[101][101], b[101][101], n, m, t1, flag;
char a[101][101];
void dfs(int x, int y) {
    if (b[x][y] || v[x][y])return;
    v[x][y] = 1;
    if (x > 1)dfs(x - 1, y);
    if (x < n)dfs(x + 1, y);
    if (y > 1)dfs(x, y - 1);
    if (y < m)dfs(x, y + 1);
}
int main() {
    for (cin >> t1; t1--;) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)scanf("%s", a[i] + 1);
        for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) b[i][j] = v[i][j] = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
                if (a[i][j] == '#') b[i][j] = 1;
                if (a[i][j] == 'B') b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] = b[i][j + 1] = 1;
            }
        flag = 0;
        dfs(n, m);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == 'G' && !v[i][j])flag = 1;
        cout << (!flag ? "Yes\n" : "No\n");
    }
}









