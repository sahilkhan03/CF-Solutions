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
vl v;

bool check(ll mid, ll k, ll r) {
    vl pre = v;
    ll ls = 0, n = v.size() - 1;
    for (int i = 0; i < n; i++) {
        ls += pre[i];
        ll dif = max(0ll, mid - ls);
        if (k < dif) return 0;
        k -= dif;
        pre[i] += dif;
        ls += dif;
        pre[min(n, i + 2 * r + 1)] -= dif;
    }
    return 1;
}

void solve() {
    ll n, r, k;
    cin >> n >> r >> k;
    v = vl(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[max(0ll, i - r)] += x;
        v[min(n, i + r + 1)] -= x;
    }
    ll lo = 0, hi = 2e18, mid, ans = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (check(mid, k, r)) ans = mid, lo = mid + 1;
        else hi = mid - 1;
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
