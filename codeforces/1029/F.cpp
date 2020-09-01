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
    ll a, b;
    cin >> a >> b;
    ll n = a + b, ans = 2*(n + 1);
    vl f1, f2; 
    for(ll i = 1; i * i <= a; i++) {
        if(a % i == 0) f1.pb(i), f1.pb(a/i);
    }
    for(ll i = 1; i * i <= b; i++) {
        if(b % i == 0) f2.pb(i), f2.pb(b/i);
    }
    sort(all(f1)), sort(all(f2));
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ll l1 = *prev(upper_bound(all(f1), i)),
               l2 = *prev(upper_bound(all(f2), i)); 
            if(a/l1 <= n/i or b/l2 <= n/i) ans = min(ans, 2*(i + n/i));
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
