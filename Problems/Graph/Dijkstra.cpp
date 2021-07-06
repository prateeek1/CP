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
using namespace std;
#define ll long long int
#define mod 1000000007
long long inf = 100000000001;
int n, m;
vector<pair<int, int>>ar[100005];
priority_queue<long long>q;
int x[100005];
long long  dis[100005];
void trace(int n)
{
    if (n != 1)
    {
        trace(x[n]);
    }
    cout << n << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ar[x].pb({y, w});
        ar[y].pb({x, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        x[i] = i;
    }
    dis[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int a = q.top();
        q.pop();
        for (int i = 0; i < ar[a].size(); i++)
        {
            int b = ar[a][i].first;
            int w = ar[a][i].second;
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
                q.push(b);
                x[b] = a;
            }
        }
    }

    if (dis[n] == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        trace(n);
        cout << " ";
    }
}




















