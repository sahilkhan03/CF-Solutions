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
const ll N = 1e6 + 5;
bitset<N> vis;

void solve() {
    ll n; cin >> n;
    vl v(n); cin >> v;
    multiset<ll> s(all(v));
    ll g = v[0];
    for(int i = 1; i < n; i++) g = __gcd(g, v[i]);
    bool f = 0;
    for(int i = 2; i < N; i++) {
        if(!vis[i]) {
            ll c = 0;
            for(int j = i; j < N; j += i) {
                vis[j] = 1;
                c += s.count(j);
            }
            if(c > 1) {
                f = 1;
                break;
            }
        }
    }
    if(!f) {
        cout << "pairwise coprime" << endl;
        return;
    }
    if(g == 1) {
        cout << "setwise coprime" << endl;
        return;
    }
    cout << "not coprime" << endl;
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
