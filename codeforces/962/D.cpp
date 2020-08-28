/* “Whether you think you can or you think you can’t, you’re right” - Henry Ford */

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
ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto &i : t) os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v) is >> t.first >> t.second;
    return is;
}

const ll mod = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    vl v(n); cin >> v;
    map<ll, set<ll>> m;
    vl ans = v;
    set<ll> s;
    for(ll i = 0; i < n; i++)  {
        m[v[i]].insert(i);
        if(m[v[i]].size() > 1) s.insert(v[i]);
    }
    while(!s.empty()) {
        ll e = *s.begin();
        auto& cur = m[e];
        ll p1 = *cur.begin(), p2 = *next(cur.begin());
        ans[p1] = -1, ans[p2] = 2*e;
        m[2*e].insert(p2);
        if(m[2*e].size() > 1) s.insert(2*e);
        cur.erase(cur.find(p1));
        cur.erase(cur.find(p2));
        if(cur.size() < 2) s.erase(e);
    }
    vl res;
    for(ll i = 0; i < n; i++) {
        if(ans[i] != -1) res.pb(ans[i]);
    }
    cout << res.size() << endl;
    cout << res << endl;
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
