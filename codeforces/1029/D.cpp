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

ll modpow(ll n, ll p, ll k) {
    ll ans = 1;
    while(p) {
        if(p & 1) (ans *= n) %= k;
        (n *= n) %= k, p /= 2;
    }
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vl v(n); cin >> v;
    ll ans = 0;
    vector<map<ll, ll>> m(11);
    for(int i = 0; i < n; i++) {
        ll len = log10(v[i]) + 1;
        m[len][v[i]%k]++;
    }
    vl mdpw(12);
    for(int i = 0; i < 12; i++) mdpw[i] = modpow(10, i, k);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < 11; j++) {
            ll x = v[i]%k;
            (x *= mdpw[j]) %= k;
            ll y = (k - x) % k;
            ans += m[j][y] - ((j == (ll)log10(v[i]) + 1) and (y == v[i]%k));
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
