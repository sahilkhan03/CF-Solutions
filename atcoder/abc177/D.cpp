/* “Whether you think you can or you think you can’t, you’re right” - Henry Ford */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
#define endl '\n'

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

const ll mod = 1e9 + 7;

ll dfs(vector<vl> &v, vector<bool> &vis, ll u)
{
    if (vis[u])
        return 0;
    vis[u] = 1;
    ll c = 1;
    for (auto x : v[u])
    {
        c += dfs(v, vis, x);
    }
    return c;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vl> v(n);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll ans = 0;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ll c = dfs(v, vis, i);
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
