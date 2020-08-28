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
    vector<string> sq;
    for(ll i = 1; i * i < 2e9 + 4; i++) {
        ll num = i * i;
        string cur = "";
        while(num) {
            int rem = num % 10;
            cur += char('0' + rem);
            num /= 10;
        }
        reverse(all(cur));
        sq.pb(cur);
    }
    string s; cin >> s;
    ll ans = 1e18;
    for(auto& x: sq) {
        if(x.size() > s.size()) break;
        ll i = 0, j = 0;
        while(i < s.size() and j < x.size()) {
            if(s[i] == x[j]) j++;
            i++;
        }
        if(j == x.size()) ans = min(ans, (ll)(s.size() - x.size()));
    }
    if(ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
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
