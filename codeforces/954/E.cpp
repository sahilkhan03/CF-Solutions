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
#define pl pair<long double, long double>
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

void solve() {
    long double n, T;
    cin >> n >> T;
    vector<pl> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].S;
    for (int i = 0; i < n; i++) cin >> v[i].F;
    long double  t = 0, den = 0;
    for (auto x : v) t += x.F * x.S, den += x.S;
    long double c = t / den;
    if (c < T) {
        for (auto& x : v) x.F = -x.F;
        c = -c, t = -t, T = -T;
    }
    sort(all(v), greater<pl>());
    ll i = 0;
    while (i < n - 1) {
        if ((t - v[i].F * v[i].S) / (den - v[i].S) > T) {
            t -= v[i].F * v[i].S;
            den -= v[i].S;
            i++;
        }
        else break;
    }
    t -= v[i].F * v[i].S, den -= v[i].S;
    long double lo = 0, hi = v[i].S, ans = 0, mid;
    while (hi - lo > 1e-10) {
        mid = lo + (hi - lo) / 2;
        c = (t + v[i].F * mid) / (den + mid);
        debug(mid, c, abs(T - c));
        if (abs(T - c) < 1e-7) {
            ans = max(ans, den + mid);
        }
        if (c > T) hi = mid;
        else lo = mid;
    }
    printf("%.10Lf\n", ans);
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
