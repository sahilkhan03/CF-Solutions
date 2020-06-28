/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pl, null_type, less<pl>, rb_tree_tag, tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
#define pl pair<ll, ll>
#define vl vector<ll>
#define endl '\n'
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


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

const ll mod = 998244353;

ll modpow(ll n, ll p) {
    ll ans = 1;
    while (p) {
        if (p  & 1) (ans *= n) %= mod;
        (n *= n) %= mod, p /= 2;
    }
    return ans;
}

void add(vl &fen, ll i, ll num) {
    while (i < fen.size()) {
        fen[i] += num;
        i += i & (-i);
    }
}

ll sum(vl &fen, ll i) {
    ll a = 0;
    while (i) {
        a += fen[i];
        i -= i & (-i);
    }
    return a;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n;
    cin >> n;
    vl pos(n), sp(n), fen1(n + 1), fen2(n + 1);
    cin >> pos >> sp;
    ordered_set s;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        s.insert({sp[i], pos[i]});
        mp[pos[i]] = sp[i];
    }
    for (int i = 0; i < n; i++) {
        auto it = *s.find_by_order(i);
        add(fen1, i + 1, it.second);
        // debug(sum(fen1, i + 1));
    }
    sort(all(pos));
    vl pre(n);
    pre[n - 1] = pos[n - 1];
    for (int i = n - 2; ~i; i--) pre[i] = pre[i + 1] + pos[i];
    ll ans = 0;
    // debug(pre);
    for (int i = 0; i < n - 1; i++) {
        auto len = s.order_of_key({mp[pos[i]], pos[i]});
        ll cnt = sum(fen2, len);
        ll s1 = sum(fen1, len);
        ans += pre[i + 1] - s1 - pos[i] * (n - i - 1 - len + cnt);
        debug(i, len, cnt, s1 , ans);
        add(fen2, len + 1, 1);
        add(fen1, len + 1, -pos[i]);
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}