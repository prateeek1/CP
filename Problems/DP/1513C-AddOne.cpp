#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<map>
#include<cstring>
#include<math.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main()
{

    ios_base::sync_with_stdio(0);
    ll l, r;
    cin >> l >> r;
    ll a = log(r);

    a = a ^ (a - 1);
    cout << a << endl;

}
