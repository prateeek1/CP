#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define mod 1000000007



int main()
{

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= sum)
		{
			ans++;
			sum += a[i];
		}
	}

	cout << ans << endl;
}






