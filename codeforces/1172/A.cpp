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
    ll n; cin >> n;
    vl a(n), b(n);
    cin >> a >> b;
    map<ll, ll> idx;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            idx[b[i]] = i + 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, idx[i] + n - i + 1);
    }
    if (idx[1]) {
        for (int i = idx[1], j = 1; i <= n; i++, j++) {
            if (b[i - 1] != j) {
                cout << ans << endl;
                return;
            }
        }
        ll pa = idx[1] - 1;
        for (int i = 0; i < idx[1] - 1; i++) {
            if (b[i]) {
                int cur = i + 1;
                int req = b[i] - b[n - 1];
                if (cur >= req) {
                    cout << ans << endl;
                    return;
                }
            }
        }
        cout << min(ans, pa) << endl;
        return;
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
