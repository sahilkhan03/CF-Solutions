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

multiset<char> s;
string ans = "";

void solve() {
    string a, b;
    cin >> a >> b;
    if (b.size() > a.size()) {
        sort(all(a), greater<char>());
        cout << a << endl;
        return;
    }
    for (auto x : a) s.insert(x);
    for (int i = 0; i < b.size() and !s.empty(); i++) {
        auto it = s.upper_bound(b[i]);
        if (it != s.begin()) {
            char c = *prev(it);
            ans += c;
            s.erase(s.find(c));
            if (c == b[i]) continue;
            while (!s.empty()) {
                ans += *prev(s.end());
                s.erase(prev(s.end()));
            }
            break;
        }
        ll j = i - 1;
        while (j >= 0) {
            s.insert(ans.back());
            ans.pop_back();
            it = s.upper_bound(b[j]);
            if (*prev(it) != b[j]) {
                j--;
                continue;
            }
            it = s.lower_bound(b[j]);
            if (it == s.begin()) {
                j--;
                continue;
            }
            it = prev(it);
            ans += *it;
            s.erase(it);
            break;
        }
        while (!s.empty()) {
            ans += *prev(s.end());
            s.erase(prev(s.end()));
        }
        break;
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
