#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back


const int N = 5e4 + 5;

int n, m;

vector<int>gr[N];
bool vis[N];


void dfs(int node)
{

    vis[node] = 1;

    for (auto child : gr[node])
    {
        if (!vis[child])
            dfs(child);
    }
}
int main()
{

    cin >> n >> m;
    int cnt = 0;
    int ans = 0;

    fo(i, n)
    {
        int k;
        cin >> k;
        if (k == 0)cnt++;

        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x *= 500;
            gr[x].pb(i + 1);
            gr[i + 1].pb(x);
        }
    }



    for (int i = 0; i < n; i++)
    {
        if (!vis[i + 1])
        {
            dfs(i + 1);
            ans++;
        }
    }


    if (cnt == n)
        cout << n << endl;
    else
        cout << ans - 1 << endl;









}