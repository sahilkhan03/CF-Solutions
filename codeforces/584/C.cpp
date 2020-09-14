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

inline char good(char a, char b) {
    for (char c = 'a'; c <= 'z'; c++) {
        if (c != a and c != b) return c;
    }
    return 'z';
}

void solve() {
    ll n, t;
    cin >> n >> t;
    vl same, dif;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) same.pb(i);
        else dif.pb(i);
    }
    if (t >= dif.size()) {
        vector<char> ans(n, '.');
        for (auto i : dif) {
            ans[i] = good(a[i], b[i]);
        }
        t -= dif.size();
        while (t--) {
            ans[same.back()] = good(a[same.back()], b[same.back()]);
            same.pop_back();
        }
        while (!same.empty()) {
            ans[same.back()] = a[same.back()];
            same.pop_back();
        }
        for (auto x : ans) cout << x;
        return;
    }
    if (2 * t >= dif.size()) {
        vector<char> ans(n, '.');
        for (int i = 0; i < dif.size(); i++) {
            if (i & 1) ans[dif[i]] = a[dif[i]];
            else ans[dif[i]] = b[dif[i]];
        }
        ll cd = 2 * t - dif.size();
        while (cd--) {
            ans[dif.back()] = good(a[dif.back()], b[dif.back()]);
            dif.pop_back();
        }
        while (!same.empty()) {
            ans[same.back()] = a[same.back()];
            same.pop_back();
        }
        for (auto x : ans) cout << x;
        return;
    }
    cout << -1 << endl;
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
