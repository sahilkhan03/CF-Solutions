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
    vl v(n); cin >> v;
    ll s = n, o = (n + 1) / 2, e = n / 2;
    for (auto x : v) {
        if (x) {
            if (x & 1) o--;
            else e--;
            s--;
        }
    }
    vector<vector<vl>> dp(2, vector<vl>(n + 1, vl(o + 1, 1e18)));
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int co = 0; co <= o; co++) {
            if (v[i - 1]) {
                if (v[i - 1] & 1)
                    dp[1][i][co] = min(dp[1][i - 1][co], dp[0][i - 1][co] + 1);
                else
                    dp[0][i][co] = min(dp[0][i - 1][co], dp[1][i - 1][co] + 1);
                continue;
            }
            if (s - co > 0)
                dp[0][i][co] = min(dp[0][i - 1][co], dp[1][i - 1][co] + 1);
            if (co > 0)
                dp[1][i][co] = min(dp[1][i - 1][co - 1], dp[0][i - 1][co - 1] + 1);
        }
    }
    cout << min(dp[0][n][o], dp[1][n][o]) << endl;
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
