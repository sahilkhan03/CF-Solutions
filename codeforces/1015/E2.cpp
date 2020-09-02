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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    cin >> s;
    vector<vl> ans;
    vector<set<ll>> dotr(n), dotc(m), star(n), stac(m);
    for (int i = 0; i < n; i++) {
        dotr[i].insert(m);
        dotr[i].insert(-1);
        star[i].insert(m);
        star[i].insert(-1);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') star[i].insert(j), stac[j].insert(i);
            else dotr[i].insert(j), dotc[j].insert(i);
        }
    }
    for (int j = 0; j < m; j++) {
        dotc[j].insert(-1); dotc[j].insert(n);
        stac[j].insert(-1); stac[j].insert(n);
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (s[i][j] == '*') {
                ll mn = 1e18;
                auto it = dotr[i].lower_bound(j);
                mn = min(*it - j - 1, j - *prev(it) - 1);
                it = dotc[j].lower_bound(i);
                mn = min({*it - i - 1, i - *prev(it) - 1, mn});
                if (mn) {
                    it = star[i].lower_bound(j);
                    while (*it - j <= mn) {
                        stac[*it].erase(stac[*it].find(i));
                        it = next(it);
                        star[i].erase(prev(it));
                    }
                    it = prev(star[i].lower_bound(j));
                    while (j - *it <= mn) {
                        stac[*it].erase(stac[*it].find(i));
                        it = prev(it);
                        star[i].erase(next(it));
                    }
                    it = stac[j].lower_bound(i);
                    while (*it - i <= mn) {
                        star[*it].erase(star[*it].find(j));
                        it = next(it);
                        stac[j].erase(prev(it));
                    }
                    it = prev(stac[j].lower_bound(i));
                    while (i - *it <= mn) {
                        star[*it].erase(star[*it].find(j));
                        it = prev(it);
                        stac[j].erase(next(it));
                    }
                    debug(i, j, mn, star[i], stac[j]);
                    ans.pb({i + 1, j + 1, mn});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (star[i].size() > 2) {
            debug(i);
            cout << -1 << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << endl;
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
