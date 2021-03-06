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
vector<vl> v;
vl dist;
ll mx;
void dfs(ll u, ll dis, ll p) {
    dist[u] = dis;
    mx = max(mx, dis);
    for (auto x : v[u]) {
        if (x != p) dfs(x, dis + 1, u);
    }
}

void solve() {
    ll n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    v = vector<vl>(n);
    dist = vl(n);
    mx = 0;
    for (int i = 0; i < n - 1; i++) {
        ll p, q;
        cin >> p >> q;
        p--, q--;
        v[q].pb(p);
        v[p].pb(q);
    }
    dfs(a, 0, -1);
    if (dist[b] <= da) {
        cout << "Alice" << endl;
        return;
    }
    dfs(max_element(all(dist)) - dist.begin(), 0, -1);
    if (da >= (mx + 1) / 2) {
        cout << "Alice" << endl;
        return;
    }
    if (db > 2 * da) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
