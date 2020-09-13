/*
    "Whether you think you can or you think you can't, you're right"
        - Henry Ford
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
#define endl '\n'

template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto i : t) os << i << " ";
    return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
    for (auto i : t) os << i << " ";
    return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
    for (auto i : t) os << i.first << " : " << i.second << endl;
    return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) is >> t;
    return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v) is >> t.first >> t.second;
    return is;
}

#ifdef LOCAL
#define debug(args...) (Debugger()), args
class Debugger {
public:
    bool first;
    string separator;
    Debugger(const string &_separator = ", ") : first(true), separator(_separator) {}
    template <typename ObjectType>
    Debugger &operator, (const ObjectType &v) {
        if (!first) cerr << separator;
        cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() { cerr << endl; }
};
#else
#define debug(args...)
#endif

const ll mod = 1e9 + 7;

ll n, idx = 0;
vector<vl> v, inv;
vector<bool> onstc;
stack<ll> s;
vl id, low, cost;
pl ans = {0, 1}; // {cost, ways}

void dfs(ll u) {
    id[u] = low[u] = idx++;
    onstc[u] = 1; s.push(u);
    for (auto x : v[u]) {
        if (id[x] == -1) dfs(x);
        if (onstc[x]) low[u] = min(low[u], low[x]);
    }
    if (id[u] == low[u]) {
        pl c = {1e18, 0}; // {cost, ways} for current SCC
        while (true) {
            ll w = s.top(); s.pop();
            if (cost[w] < c.F) c = {cost[w], 1};
            else if (cost[w] == c.F) c.S++;
            onstc[w] = 0;
            if (w == u) break;
        }
        ans.F += c.F;
        (ans.S *= c.S) %= mod;
    }
}

void solve() {
    cin >> n;
    cost.resize(n); cin >> cost;
    v.resize(n); id.resize(n, -1), low.resize(n, -1);
    ll m; cin >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        v[a - 1].pb(b - 1);
    }
    onstc = vector<bool>(n, 0);
    for (int i = 0; i < n; i++) {
        if (id[i] == -1) dfs(i);
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
