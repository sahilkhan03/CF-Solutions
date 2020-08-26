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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vi v(n);
    cin >> v;
    vector<short> cnt(3001, 0), nc(3001, 0);
    vector<vi> pr(3001, vi(3001, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < 3001; j++)
            pr[v[i]][j] += cnt[j];
        cnt[v[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[v[i]]--;
        for (int j = 1; j < 3001; j++)
        {
            pr[v[i]][j] -= cnt[j];
            ans += nc[j] * pr[j][v[i]];
        }
        nc[v[i]]++;
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
