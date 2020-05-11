/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pl, null_type, less<pl>, rb_tree_tag, tree_order_statistics_node_update>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define pi pair<int, int>
#define pl pair<long long, long long>
#define pld pair<long double, long double>
#define endl '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define rep(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod ((ll)(1e9 + 7))
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define ml map<ll, ll>
#define vpl vector<pair<ll, ll>>

template <typename T, typename TT>
ostream &operator<<(ostream &os, const pair<T, TT> &t) {
    return os << t.first << " " << t.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &t) {
    for (auto &i : t)
        os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v)
        is >> t;
    return is;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
    for (pair<T1, T2> &t : v)
        is >> t.first >> t.second;
    return is;
}

const ll md = 998244353;
ll inv[int(2e5+5)];
ll fact[int(2e5 + 5)];

ll modpow(ll n, ll p)
{
    ll ans = 1;
    while(p) {
        if(p&1)
            (ans *= n) %= md;
        (n *= n) %= md, p /= 2;
    }
    return ans;
}

ll ncr(ll n, ll k) {
    if(!k)
        return 1;
    ll res = (fact[n] * inv[k]) % md;
    return (res * inv[n - k]) % md;
}

int main() {
    fast;
    fact[0] = 1, inv[0] = 1;
    rep(i, 1, 2e5 + 5)
    {
        fact[i] = (fact[i - 1] * i)%md;
        inv[i] = modpow(fact[i], md - 2);
    }
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    loop(i, k + 1) {
        (ans += ncr(n-1,i) *  modpow(m - 1, n - i - 1)) %= md;
    }
    cout << (ans*m)%md << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}