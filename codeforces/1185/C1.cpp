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

template <class T> struct fenwick_tree {
public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += T(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};
fenwick_tree<ll> fen1(2e5 + 5), fen2(2e5 + 5);

ll calc(ll num) {
    ll ans = 0, lo = 1, hi = 2e5  + 3;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (fen1.sum(1, mid) <= num) ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vl v(n); cin >> v;
    vector<vl> idx;
    for (int i = 0; i < n; i++) idx.pb({v[i], i});
    sort(all(idx));
    map<pl, ll> inv;
    for (int i = 0; i < n; i++) inv[ {idx[i][0], idx[i][1]}] = i + 1;
    for (int i = 0; i < n; i++) {
        cout << i - fen2.sum(1, calc(m - v[i])) << " ";
        fen1.add(inv[ {v[i], i}], v[i]);
        fen2.add(inv[ {v[i], i}], 1);
    }
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
