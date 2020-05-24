/*
    Author : DemonStar
*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define pi pair<int, int>
#define pl pair<long long, long long>
#define pld pair<long double, long double>
#define endl '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define rep(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define vi vector<int>
#define ml map<ll, ll>
#define vpl vector<pair<ll, ll>>
const ll mod = 1e9 + 7;

template <typename T, typename TT>
ostream &operator<<(ostream &os, const pair<T, TT> &t)
{
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t)
{
    for (auto &i : t)
        os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &t : v)
        is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v)
{
    for (pair<T1, T2> &t : v)
        is >> t.first >> t.second;
    return is;
}

ll modpow(ll n, ll p) {
    ll ans = 1;
    while(p) {
        if(p & 1) (ans *= n) %= mod;
        (n *= n) %= mod, p /= 2;
    }
    return ans;
}

ll dp[105][105][11][11];
// string cur = "";
int k11, k22;
ll  calc(int n1, int n2, int k1, int k2) {
    if(!n1 and !n2) {
        return 1;
    }
    ll &ans = dp[n1][n2][k1][k2];
    if(ans != -1) return ans;
    ans = 0;
    if(n1 and k1) {
        (ans += calc(n1 - 1, n2, k1 -1, k22)) %= 100000000;
    } 
    if(n2 and k2) {
        (ans += calc(n1,  n2 - 1, k11, k2 - 1)) %= 100000000;
    }
    return ans;
}

int main()
{
    fast;
    int n1, n2;
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k11 >> k22;
    cout << calc(n1, n2, k11, k22) << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}
