#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>PBDS;



// can store duplicates
typedef tree < pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>PBDSdup;


#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,n) for(int i=1;i<=n;i++)
#define mod 1000000007
const int MOD = 998244353;
long long inf = 100000000001;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define int long long int
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int32_t main()
{
    PBDS a;
    a.insert(1);
    a.insert(3);
    a.insert(4);
    a.insert(10);
    a.insert(13);

    // gives the value of the element in i'th position when sorted in ascending order
    cout << *a.find_by_order(0) << endl;


    for (int i = 0; i < a.size(); i++)
    {
        cout << i << " " << *a.find_by_order(i) << endl;
    }


    // finding lower bound in logN
    cout << a.order_of_key(5) << endl;


    PBDSdup b;
    b.insert({1, 1});
    b.insert({1, 2});
    b.insert({3, 4});
    b.insert({4, 5});
    b.insert({6, 6});

    for (int i = 0; i < b.size(); i++)
    {
        cout << i << " " << b.find_by_order(i)->first << endl;
    }

}