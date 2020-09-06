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
    for (auto &i : t) os << i << " ";
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
ll n;
map<vl, set<ll>> m;
vector<pl> v;

bool calc(ll u) {
    m.clear();
    pl a = v[u];
    for (int i = 0; i < n; i++) {
        if (i == u) continue;
        vl cur = {0, 1, 0, 1};
        pl b = v[i];
        ll nm = a.S - b.S, dm = a.F - b.F, g = __gcd(nm, dm);
        if (!dm) {
            cur = {1, 0, -a.F, 1};
            m[cur].insert(i);
            continue;
        }
        nm /= g, dm /= g;
        cur[0] = nm, cur[1] = dm;
        ll nc = a.S * dm - a.F * nm;
        g = __gcd(nc, dm);
        cur[2] = nc / g, cur[3] = dm / g;
        m[cur].insert(i);
    }
    vector<set<ll>> s;
    for (auto x : m) s.pb(x.S);
    sort(all(s), [](const set<ll> &p, const set<ll> &q) -> bool {
        return p.size() > q.size();
    });
    debug(s);
    m.clear();
    ll j = 0;
    while (j < n and (s[0].find(j) != s[0].end() or j == u)) j++;
    if (j == n) return 1;
    a = v[j];
    for (int i = 0; i < n; i++) {
        if (i == j or i == u or (s[0].find(i) != s[0].end())) continue;
        vl cur = {0, 1, 0, 1};
        pl b = v[i];
        ll nm = a.S - b.S, dm = a.F - b.F, g = __gcd(nm, dm);
        if (!dm) {
            cur = {1, 0, -a.F, 1};
            m[cur].insert(i);
            continue;
        }
        nm /= g, dm /= g;
        cur[0] = nm, cur[1] = dm;
        ll nc = a.S * dm - a.F * nm;
        g = __gcd(nc, dm);
        cur[2] = nc / g, cur[3] = dm / g;
        m[cur].insert(i);
    }
    return (m.size() < 2);
}

void solve() {
    cin >> n;
    v.resize(n); cin >> v;
    if (n < 3) {
        cout << "YES" << endl;
        return;
    }
    if (calc(0) or calc(1) or calc(2)) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
