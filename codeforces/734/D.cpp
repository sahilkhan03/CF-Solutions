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
    ll n, x, y; cin >> n >> x >> y;
    vector<pl> v = {{ -mod, 0}, {mod, 0}, { -mod, 0}, {mod, 0}, { -mod, 0}, {mod, 0}, { -mod, 0}, {mod, 0}};
    while (n--) {
        char c; cin >> c;
        ll a, b; cin >> a >> b;
        if (c == 'R') {
            if (a == x) {
                if (b < y and v[6].F < b) v[6] = {b, 1};
                else if (b > y and v[7].F > b) v[7] = {b, 1};
            }
            if (b == y) {
                if (a < x and v[4].F < a) v[4] = {a, 1};
                else if (a > x and v[5].F > a) v[5] = {a, 1};
            }
            if (a + b == x + y) {
                if (a < x and v[2].F < a) v[2] = {a, 0};
                else if (a > x and v[3].F > a) v[3] = {a, 0};
            }
            if (a - b == x - y) {
                if (a < x and v[0].F < a) v[0] = {a, 0};
                else if (a > x  and v[1].F > a) v[1] = {a, 0};
            }
        }
        else if (c == 'B') {
            if (a + b == x + y) {
                if (a < x and v[2].F < a) v[2] = {a, 1};
                else if (a > x and v[3].F > a) v[3] = {a, 1};
            }
            if (a - b == x - y) {
                if (a < x and v[0].F < a) v[0] = {a, 1};
                else if (a > x  and v[1].F > a) v[1] = {a, 1};
            }
            if (a == x) {
                if (b < y and v[6].F < b) v[6] = {b, 0};
                else if (b > y and v[7].F > b) v[7] = {b, 0};
            }
            if (b == y) {
                if (a < x and v[4].F < a) v[4] = {a, 0};
                else if (a > x and v[5].F > a) v[5] = {a, 0};
            }
        }
        else {
            if (a + b == x + y) {
                if (a < x and v[2].F < a) v[2] = {a, 1};
                else if (a > x and v[3].F > a) v[3] = {a, 1};
            }
            if (a - b == x - y) {
                if (a < x and v[0].F < a) v[0] = {a, 1};
                else if (a > x  and v[1].F > a) v[1] = {a, 1};
            }
            if (a == x) {
                if (b < y and v[6].F < b) v[6] = {b, 1};
                else if (b > y and v[7].F > b) v[7] = {b, 1};
            }
            if (b == y) {
                if (a < x and v[4].F < a) v[4] = {a, 1};
                else if (a > x and v[5].F > a) v[5] = {a, 1};
            }
        }
    }
    for (auto p : v) {
        if (p.S) {
            cout << "YES" << endl;
            return;
        }
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
