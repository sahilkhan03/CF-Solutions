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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    cin >> v;
    vector<vi> dp(n + 1, vi(k + 1, mod)), cost(n + 1, vi(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        vi tmp;
        for (int j = 0; j < m; j++) if (v[i - 1][j] == '1') tmp.pb(j);
        for (int x = 0; x < min(k + 1, (int)tmp.size()); x++) {
            int rem = tmp.size() - x;
            cost[i][x] = mod;
            for (int l = 0; l + rem - 1 < tmp.size(); l++)
                cost[i][x] = min(cost[i][x], tmp[l + rem - 1] - tmp[l] + 1);
        }
    }
    debug(cost);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int tot = 0; tot <= k; tot++) {
            for (int x = 0; x <= tot; x++) {
                dp[i][tot] = min(dp[i][tot], dp[i - 1][tot - x] + cost[i][x]);
            }
        }
    }
    cout << dp[n][k] << endl;
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
