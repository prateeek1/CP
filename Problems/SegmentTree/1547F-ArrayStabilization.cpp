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
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
#define int long long int
#define mod 1000000007
//long long inf = 100000000001;
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

const int N = 1e5;
vector<int>a;
vector<int>tree;

void buildTree( int s, int e , int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }

    int mid = s + (e - s) / 2;

    buildTree( s, mid, 2 * index);
    buildTree( mid + 1, e, 2 * index + 1);


    tree[index] =   __gcd(tree[2 * index], tree[2 * index + 1]);
    return;
}

int query( int s, int e, int qs, int qe, int index)
{
    if (s >= qs and e <= qe )
        return tree[index];

    if (qe<s or  qs>e)
        return 0;

    int mid = s + (e - s) / 2;

    int left = query( s, mid, qs, qe, 2 * index);
    int right = query( mid + 1, e, qs, qe, 2 * index + 1);

    return __gcd(left, right);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        a.clear();
        tree.clear();
        //memset(a, 0, sizeof(a));
        //memset(tree, 0, sizeof(tree));
        fo(i, n)
        {
            int x;
            cin >> x;
            a.pb(x);
        }

        fo(i, n)
        {
            a.pb(a[i]);
        }

        int g = 0;
        fo(i, n)
        {
            g = __gcd(g, a[i]);

        }

        //  for (auto it : a)
        //    cout << it << " ";
        // cout << endl;
        a.pop_back();
        int m = n;
        n *= 2;
        n--;
        tree.resize(4 * n);

        buildTree(0, n - 1, 1);
        int x = INT_MAX;

        int low = 1;
        int high = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            bool f = true;

            fo(i, m)
            {
                int h = query(0, n - 1, i, i + mid - 1, 1);

                if (h != g)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                x = min(x, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }




        cout << x - 1 << endl;

    }



}