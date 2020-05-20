/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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
    string a, b;
    cin >> a >> b;
    vector<vector<vi>> dp(a.size() + 1, vector<vi>(b.size() + 1, vi(3)));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (!i and !j)
            {
                dp[i][j] = {(a[i] == b[j]), -1, -1};
            }
            else if (!i)
            {
                if (a[i] == b[j])
                    dp[i][j] = {1, -1, -1};
                else
                    dp[i][j] = {dp[i][j - 1][0], i, j - 1};
            }
            else if (!j)
            {
                if (a[i] == b[j])
                    dp[i][j] = {1, -1, -1};
                else
                    dp[i][j] = {dp[i - 1][j][0], i - 1, j};
            }
            else
            {
                if (a[i] == b[j])
                {
                    dp[i][j] = {dp[i - 1][j - 1][0] + 1, i - 1, j - 1};
                }
                else if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = {dp[i - 1][j][0], i - 1, j};
                }
                else
                    dp[i][j] = {dp[i][j - 1][0], i, j - 1};
            }
        }
    }
    string ans = "";
    auto cur = dp[a.size() - 1][b.size() - 1];
    int i = a.size() - 1, j = b.size() - 1;
    while (true)
    {
        // cout << cur << endl;
        if (a[i] == b[j])
            ans = a[i] + ans;
        if (cur[1] == -1 or cur[2] == -1)
            break;
        i = cur[1], j = cur[2];
        cur = dp[i][j];
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr
        << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}