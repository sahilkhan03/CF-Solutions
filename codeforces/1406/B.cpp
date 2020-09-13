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
    vl pos, neg;
    ll z = 0;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (t > 0) pos.pb(t);
        else if (t < 0) neg.pb(t);
        else z++;
    }
    sort(all(pos), greater<ll>());
    sort(all(neg));
    ll ans = 1;
    if (z) ans = 0;
    else {
        ans = 1;
        ll i = pos.size() - 1, j = neg.size() - 1, c = 0;
        while (c < 5 and i >= 0 and j >= 0) {
            if (pos[i] > neg[j]) ans *= neg[j--];
            else ans *= pos[i--];
            c++;
        }
        while (c < 5 and i >= 0) c++, ans *= pos[i--];
        while (c < 5 and j >= 0) c++, ans *= neg[j--];
        if (c < 5) ans = 0;
    }
    if (pos.size() >= 1) {
        ll cur = pos[0];
        if (neg.size() >= 4) cur *= neg[0] * neg[1] * neg[2] * neg[3];
        else cur = -1e18;
        ans = max(ans, cur);
    }
    if (pos.size() >= 3) {
        ll cur = pos[1] * pos[0] * pos[2];
        if (neg.size() >= 2) cur *= neg[0] * neg[1];
        else cur = -1e18;
        ans = max(ans, cur);
    }
    if (pos.size() >= 5) {
        ll cur = pos[0] * pos[1] * pos[2] * pos[3] * pos[4];
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
