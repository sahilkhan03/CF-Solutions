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

const ll mod = 998244353;

struct cmp {
    bool operator()(const pl& a, const pl& b) const {
        return a.S < b.S;
    }
};

vl fact(3e5 + 5), inv(3e5 + 5);
ll modpow(ll n, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) (ans *= n) %= mod;
        (n *= n) %= mod, p /= 2;
    }
    return ans;
}

ll calc(ll n, ll r) {
    if (n < r) return 0;
    ll ans = (fact[n] * inv[r]) % mod;
    return (ans * inv[n - r]) % mod;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<pl> v(n); cin >> v;
    sort(all(v), [](pl a, pl b) -> bool{
        if (a.F == b.F) return a.S > b.S;
        return a.F < b.F;
    });
    fact[0] = inv[0] = 1;
    for (int i = 1; i < 3e5 + 5; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = modpow(fact[i], mod - 2);
    }
    multiset<pl, cmp> s;
    for (auto x : s) cout << x << endl;
    ll ans = 0;
    for (pl x : v) {
        while (!s.empty() and s.begin()->S < x.F) s.erase(s.begin());
        (ans += calc(s.size(), k - 1)) %= mod;
        s.insert(x);
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
