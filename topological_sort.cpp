//Kahn's Algorithm
// Choose the node which has indegree 0 or dependencies are traversed
// Graph doesn't contain cycles

#include<bits/stdc++.h>
using namespace std;

vector<int>ar[100];
int in[100];
vector<int>ans;

void kahn(int n)
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0) // if indegree is 0 push in queue
			q.push(i);
	}
	while (!q.empty())
	{
		int curr = q.front();
		ans.push_back(curr);
		q.pop();
		for (int node : ar[curr])
		{
			in[node]--;
			if (in[node] == 0)
				q.push(node);
		}

	}

	for (auto it : ans)
		cout << it << " ";


}


int main()
{
	int n, m, x, y;
	cin >> n >> m; //vertices and edges
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		ar[x].push_back(y);  //directed graph
		in[y]++;
	}
	kahn(n);
}
