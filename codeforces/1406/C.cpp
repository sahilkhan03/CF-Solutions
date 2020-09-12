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

vl cent;
vector<vl> v;
vl dp;
ll n;
void dfs(ll u, ll p) {
    bool f = 1;
    for (auto x : v[u]) {
        if (x != p) {
            dfs(x, u);
            dp[u] += dp[x];
            if (dp[x] > n / 2) f = 0;
        }
    }
    if (n - dp[u] > n / 2) f = 0;
    if (f) cent.pb(u);
}

void solve() {
    cin >> n;
    v = vector<vl>(n);
    cent.clear();
    dp = vl(n, 1);
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, -1);
    debug(cent);
    debug(dp);
    if (cent.size() == 1) {
        ll c = cent[0];
        ll nd = v[c][0];
        cout << c + 1 << " " << nd + 1 << endl;
        cout << c + 1 << " " << nd + 1 << endl;
        return;
    }
    ll c1 = cent[0], c2 = cent[1];
    ll nd = (v[c2][0] != c1 ? v[c2][0] : v[c2][1]);
    cout << c2 + 1 << " " << nd + 1 << endl;
    cout << c1 + 1 << " " << nd + 1 << endl;
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
