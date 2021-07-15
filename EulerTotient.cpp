#include<bits/stdc++.h>
using namespace std;
#define int long long int

int phi(int n) {    // sqrt complexity
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

vector<int> phi1ton(int n) {   //nloglogn complexity
	vector<int> phi(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}

	return phi;
}


int32_t main()
{


	cout << phi(9) << endl;


	vector<int>ans = phi1ton(9);
	for (auto it : ans)
		cout << it << " ";
}