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

vector<vl> lst;
ll n, m;
vl cost;

bool check(ll mid) {
    vector<pl> cur;
    for (int i = 0; i < m; i++) {
        if (lst[i].empty()) return 0;
        auto it = upper_bound(all(lst[i]), mid);
        if (it == lst[i].begin()) return 0;
        cur.pb({*prev(it), i});
    }
    sort(all(cur));
    ll rem = 0, last = 0;
    for (auto x : cur) {
        rem += x.F - last - 1;
        if (cost[x.S] > rem) return 0;
        rem -= cost[x.S];
        last = x.F;
    }
    return 1;
}

void solve() {
    cin >> n >> m;
    vl v(n); cin >> v;
    lst.resize(m); cost.resize(m);
    cin >> cost;
    for (int i = 0; i < n; i++) {
        if (v[i]) lst[v[i] - 1].pb(i + 1);
    }
    ll ans = -1, lo = 1, hi = n, mid = n;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (check(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
