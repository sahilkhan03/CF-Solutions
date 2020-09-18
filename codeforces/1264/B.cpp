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

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a and !b ) {
        if (abs(d - c) > 1) {
            cout << "NO" << endl;
            return;
        }
        vl ans;
        while (d and  c) {
            ans.pb(2);
            ans.pb(3);
            c-- , d--;
        }
        if (c) ans.pb(2);
        cout << "YES" << endl;
        if (d) cout << 3 << " ";
        cout << ans << endl;
        return;
    }
    if (!c and !d) {
        if (abs(a - b) > 1) {
            cout << "NO" << endl;
            return;
        }
        vl ans;
        while (b and a) {
            ans.pb(0);
            ans.pb(1);
            b-- , a--;
        }
        if (a) ans.pb(0);
        cout << "YES" << endl;
        if (b) cout << 1 << " ";
        cout << ans << endl;
        return;
    }
    if (a > b or d > c) {
        cout << "NO" << endl;
        return;
    }
    ll c1 = b - a, c2 = c - d;
    if (abs(c1 - c2) > 1) {
        cout << "NO" << endl;
        return;
    }
    vl ans;
    for (int i = 0; i < a; i++) {
        ans.pb(0);
        ans.pb(1);
    }
    while (c1 and c2) {
        c1--, c2--;
        ans.pb(2);
        ans.pb(1);
    }
    for (int i = 0; i < d; i++) ans.pb(2), ans.pb(3);
    if (c2) ans.pb(2);
    cout << "YES" << endl;
    if (c1) cout << 1 << " ";
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