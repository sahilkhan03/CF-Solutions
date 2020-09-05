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
    for (T i : t) os << i << " ";
    return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
    for (T &i : t) os << i << " ";
    return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
    for (auto &i : t) os << i.first << " : " << i.second << endl;
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
    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    if (t[0] == t[1]) {
        ll c = 0;
        for (auto x : s) c += (x == t[0]);
        c += min(k, n - c);
        cout << c * (c - 1) / 2 << endl;
        return;
    }
    vector<vector<vl>> dp(n + 1, vector<vl>(n + 1, vl(k + 1, -1e18)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int a = 0; a <= i; a++) {
            for (int use = 0; use <= min(i * 1ll, k); use++) {
                dp[i][a][use] = dp[i - 1][a][use];
                if (use > 0) {
                    dp[i][a][use] = max(dp[i][a][use], dp[i - 1][a][use - 1] + a);
                    if (a > 0)
                        dp[i][a][use] = max(dp[i][a][use], dp[i - 1][a - 1][use - 1]);
                }
                if (s[i - 1] == t[0] and a > 0)
                    dp[i][a][use] = max(dp[i][a][use], dp[i - 1][a - 1][use]);
                if (s[i - 1] == t[1])
                    dp[i][a][use] = max(dp[i][a][use], dp[i - 1][a][use] + a);
                // debug(i, a, use, dp[i][a][use]);
                ans = max(ans, dp[i][a][use]);
            }
        }
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
