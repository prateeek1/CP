#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)


const int N = 2e4 + 5;

int n, m;

int mp[N];

int bfs()
{

    queue<int>q;

    q.push(n);
    mp[n] = 1;
    int make = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();

        if (a == m)
        {


            return mp[a];

        }

        make = 2 * a;

        if (make < N)
        {
            if (!mp[make])
            {
                mp[make] = mp[a] + 1;
                q.push(make);
            }
            else
            {
                if (mp[a] + 1 < mp[make])
                {
                    mp[make] = mp[a] + 1;
                    q.push(make);
                }
            }
        }

        make = a - 1;

        if (make >= 0)
        {
            if (!mp[make])
            {
                mp[make] = mp[a] + 1;
                q.push(make);
            }
            else
            {
                if (mp[a] + 1 < mp[make])
                {
                    mp[make] = mp[a] + 1;
                    q.push(make);
                }
            }
        }

    }

    //return -1;
}
int main()
{

    cin >> n >> m;

    if (n == m)
    {
        cout << 0 << endl;

    }

    cout << bfs() - 1 << endl;







}