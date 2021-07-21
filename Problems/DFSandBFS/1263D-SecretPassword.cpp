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
#include<set>
#include<bits/stdc++.h>
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,n) for(int i=1;i<=n;i++)
using namespace std;
#define int long long int
#define mod 1000000007
long long inf = 100000000001;
#define all(v) (v).begin(),(v).end()
#define pb push_back
const int N = 200005;

const int MOD = 998244353;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
int  lcm(int  a, int  b) // Function to calculate Lcm
{
    return (a / __gcd(a, b)) * b;
}
int highestPowerof2(int n) // Highest pow of two
{
    int p = (int)log2(n);
    return (int)pow(2, p);
}

/*int power(int a, int n, int mod)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % mod;

        }
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}*/


/*int binom(int n, int r, int mod)
{
    int res = fact[n];

    res =  (res * power(fact[n - r], mod - 2, mod)) % mod;
    res = (res * power(fact[r], mod - 2, mod)) % mod;

    return res;
}*/


// int firstDigit(int n)
// {
//     // Find total number of digits - 1
//     int digits = (int)log10(n);

//     // Find first digit
//     n = (int)(n / pow(10, digits));

//     // Return first digit
//     return n;
// }


int fact[N];

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % mod;
        }
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}


int ncr(int n, int r)
{
    if (r > n)
        return 0;

    int res = fact[n];
    res = (res * power(fact[r], mod - 2)) % mod;
    res = (res * power(fact[n - r], mod - 2)) % mod;

    return res;
}




vector<int>gr[200005];
bool vis[200005];
void dfs(int node)
{
    vis[node] = 1;

    for (auto child : gr[node])
    {
        if (!vis[child])
            dfs(child);
    }
}


// const int N = 1e5;
// int a[N];
// int tree[4 * N + 1];
// void buildTree( int s, int e , int index)
// {
//     if (s == e)
//     {
//         tree[index] = a[s];
//         return;
//     }

//     int mid = (s + e) / 2;

//     buildTree( s, mid, 2 * index);
//     buildTree( mid + 1, e, 2 * index + 1);


//     tree[index] =   min(tree[2 * index], tree[2 * index + 1]);  //operation that is needed to be done
//     return;
// }

// int query( int s, int e, int qs, int qe, int index)
// {
//     if (s >= qs and e <= qe )
//         return tree[index];

//     if (qe<s or  qs>e)
//         return INT_MAX;  // operation needed

//     int mid = (s + e) / 2;

//     int left = query( s, mid, qs, qe, 2 * index);
//     int right = query( mid + 1, e, qs, qe, 2 * index + 1);

//     return min(left, right);  //operation that is needed
// }

// void update(int ss, int se, int i, int increment, int index)
// {
//     if (i > se or i < ss)
//         return ;
//     if (ss == se)
//     {
//         tree[index] += increment; //update needed
//         return;
//     }

//     int mid = (ss + se) / 2;

//     update(ss, mid, i, increment, 2 * index);
//     update(mid + 1, se, i, increment, 2 * index + 1)
//     tree[index] = min(tree[2 * index], tree[2 * index + 1]); //update needed

// }


// void updateRange(int ss,int se,int l,int r,int inc,int index)
// {
//      if(l>se or r<ss)
//         return;

//      if(ss==se)
//      {
//         tree[index]+=inc;
//         return;
//      }

//      int mid=(ss+se)/2;
//      updateRange(ss,mid,l,r,inc,2*index);
//      updateRange(mid+1,se,l,r,inc,2*index+1);

//      tree[index]=min(tree[2*index],tree[2*index+1]);


//      return;
// }

int32_t main() {



    int n;
    cin >> n;

    fo(i, n)
    {
        string s;
        cin >> s;
        for (auto it : s)
        {
            gr[i].pb(n + (it - 'a'));
            gr[(n + (it - 'a'))].pb(i);
        }



    }

    int ans = 0;
    for (int i = n; i < n + 26; i++)
    {
        if (!gr[i].empty() and !vis[i])
        {
            dfs(i);
            ans++;
        }
    }



    cout << ans << endl;
}




