/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
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

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n , x;
    cin >> n >> x;
    vl v(2 * n + 1), pre(2 * n + 1), cnt(2 * n + 1);
    v[0] = 0; pre[0] = 0; cnt[0] = 0;
    loop(i, n) {
        cin >> v[i + 1];
        v[i + 1 + n] = v[i + 1];
    }
    loop(i, 2 * n) {
        pre[i + 1] = pre[i] + v[i + 1];
        cnt[i + 1] = cnt[i] + v[i + 1] * (v[i + 1] + 1) * 1.0 / 2;
    }
    // cout << pre << endl << cnt << endl;
    ll ans = 0, cur = 0;
    for (int i = 2 * n; ~i and pre[i] >= x; i--) {
        auto it = lower_bound(all(pre), pre[i] - x);
        ll len = *it - pre[i] + x;
        cur = len * (2 * v[it - pre.begin()] + 1 - len) * 1.0 / 2;
        cur += cnt[i] - cnt[it - pre.begin()];
        // cout << "--- " << i << " " << cur << " " << it - pre.begin() << " " << len << endl;
        ans = max(ans, cur);
    }

    cout << ans << endl;




#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}
