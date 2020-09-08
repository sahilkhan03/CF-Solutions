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
    for (T i : t) os << i << " ";
    return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
    for (T &i : t) os << i << " ";
    return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
    for (auto &i : t) os << i.first << " : " << i.second << endl;
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
vector<map<ll, ll>> v;
vector<bool> vis;

void bfs(vl &dist, ll u) {
    queue<pl> q;
    q.push({u, 0});
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        if (vis[tp.F]) continue;
        vis[tp.F] = 1;
        dist[tp.F] = tp.S;
        for (auto x : v[tp.F]) {
            q.push({x.F, tp.S + 1});
        }
    }
}

void solve() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    v.resize(n);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    vis = vector<bool>(n);
    vl dis1(n), dis2(n);
    bfs(dis1, s - 1);
    vis = vector<bool>(n);
    bfs(dis2, t - 1);
    debug(dis1, dis2);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!v[i][j]) {
                if (min(dis1[i] + dis2[j], dis1[j] + dis2[i]) + 1 >= dis1[t - 1]) ans++;
            }
        }
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
