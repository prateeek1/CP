
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<functional>

using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    string s1, s2, ans;
    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0);
    cin >> s1;
    for (int j = 0; j < (n - 1); j++)
    {
        cin >> s2;
        i = 0;
        while (i < s1.size() && i < s2.size())
        {
            if (s1[i] != s2[i])
            {
                graph[s1[i] - 97].push_back(s2[i] - 97);
                indegree[s2[i] - 97]++;
                break;
            }
            i++;
        }
        if (i >= s2.size() && i < s1.size())
        {
            cout << "Impossible";
            return 0;
        }
        s1 = s2;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (i = 0; i < 26; i++)
        if (indegree[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        i = pq.top();
        pq.pop();
        ans.push_back((char)(i + 97));
        for (auto v : graph[i])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                pq.push(v);
        }
    }
    if (ans.size() < 26)
        cout << "Impossible\n";
    else
        cout << ans;

    return 0;
}











