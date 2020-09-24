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


void solve() {
    ll n, m;
    cin >> n >> m;
    vl v(n); cin >> v;
    fenwick_tree<ll> fen(n + 2);
    map<ll, vl> ls;
    vector<vl> q(m, vl(3));
    for (int i = 0; i < m; i++) {
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }
    sort(all(q), [&](const vl & a, const vl & b)->bool{
        return a[1] < b[1];
    });
    vl ans(m);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        vl &cur = ls[v[i - 1]];
        ll e = v[i - 1];
        cur.pb(i);
        if (cur.size() >= e) {
            fen.add(cur[cur.size() - e], 1);
            if (cur.size() > e)
                fen.add(cur[cur.size() - e - 1], -2);
            if (cur.size() > e + 1)
                fen.add(cur[cur.size() - e - 2], 1);
        }
        while (j < m and q[j][1] <= i) {
            ans[q[j][2]] = fen.sum(q[j][0], q[j][1] + 1);
            j++;
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
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
