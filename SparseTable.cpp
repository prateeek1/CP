// range query in logN
// for idempotent function in O(1) e.g min,max,gcd

// [i,2^j-1] [i+2^j,2^j-1]
#include<bits/stdc++.h>
using namespace std;


const int MAXN = 200005;
const int K = 20;
int st[MAXN][K + 1];

int p2[MAXN + 1];



void init()
{
	p2[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		p2[i] = p2[i / 2] + 1;
}


void build(vector<int>a)
{
	int N = a.size();
	for (int i = 0; i < N; i++)
		st[i][0] = a[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); //opeartion needed
}

int query(int L, int R)
{
	int j = p2[R - L + 1];
	int minimum = max(st[L][j], st[R - (1 << j) + 1][j]);  // opeartion needed


	return minimum;
}

int querysum(int L, int R)
{
	int  sum = 0;
	for (int j = K; j >= 0; j--) {
		if ((1 << j) <= R - L + 1) {
			sum += st[L][j];
			L += 1 << j;
		}
	}
}

int main()
{

	int n;
	cin >> n;

	vector<int>a;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	init();

	build(a);

	cout << query(0, 9) << endl;


	//cout << query(0, 1) << endl;

}