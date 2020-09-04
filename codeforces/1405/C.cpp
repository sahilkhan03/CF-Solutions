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
    string s; cin >> s;
    ll o = 0, z = 0, q = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '1') o++;
        else if (s[i] == '0') z++;
    }
    if (o > k / 2 or z > k / 2  or (k % 2 == 1)) {
        cout << "NO" << endl;
        return;
    }
    o = k / 2 - o, z = k / 2 - z;
    vl cnt = {z, o};
    for (int i = k; i < n; i++) {
        if (s[i] == '?') {
            if (s[i - k] != '?') s[i] = s[i - k];
            continue;
        }
        if (s[i - k] != '?' and s[i] != s[i - k]) {
            cout << "NO" << endl;
            return;
        }
        if (s[i - k] == '?') {
            if (!cnt[s[i] - '0']) {
                cout << "NO" << endl;
                return;
            }
            cnt[s[i] - '0']--;
        }
        debug(i, cnt);
    }
    cout << "YES" << endl;
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