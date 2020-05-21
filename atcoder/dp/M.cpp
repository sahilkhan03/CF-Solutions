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

int main()
{
    ll n, k;
    cin >> n >> k;
    vl v(n);
    cin >> v;
    vector<vl> dp(n + 1, vl(k + 1, 0));
    loop(i, k + 1) dp[0][i] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int l = max(0LL, j - v[i - 1]), r = j;
            dp[i][j] = (mod + dp[i - 1][r] - (l ? dp[i - 1][l - 1] : 0)) % mod;
            if (j)
                (dp[i][j] += dp[i][j - 1]) %= mod;
        }
    }
    cout << (mod + dp[n][k] - (k ? dp[n][k - 1] : 0)) % mod << endl;

#ifdef LOCAL
    cerr
        << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}