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
ll n;
ll calc(string &s) {
    vl cnt(52, 0);
    for (auto x : s) {
        if (x >= 'a' and x <= 'z') cnt[x - 'a']++;
        else cnt[26 + x - 'A']++;
    }
    ll mx = *max_element(all(cnt));
    if (mx == s.size()) return s.size() - (n == 1);
    return min(ll(s.size()), mx + n);
}

void solve() {
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    vector<string> idx = {"Kuro", "Shiro", "Katie"};
    vector<pl> v = {{calc(a), 0}, {calc(b), 1}, {calc(c), 2}};
    sort(all(v), greater<pl>());
    debug(v);
    if (v[0].F == v[1].F) cout << "Draw" << endl;
    else cout << idx[v[0].S] << endl;
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
