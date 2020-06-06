/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
#define mset(v, a) memset(v, a, sizeof v);
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

const ll mod = 1e9 + 7;

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    vl n(3);
    cin >> n;
    vl p(3);
    cin >> p;
    ll r; cin >> r;
    ll cb = 0 , cs = 0, cc = 0;
    loop(i, (ll)s.size()) {
        if (s[i] == 'B') cb++;
        else if (s[i] == 'S') cs++;
        else cc++;
    }
    vl c = {cb , cs , cc};
    ll ans = 0;
    vector<pl> v(3);
    vl rem(3);
    if (c[0]) v[0] = {n[0] / c[0], 0}, rem[0] = n[0] % c[0];
    else v[0] = {1e18, 0}, rem[0] = 0;
    if (c[1]) v[1] = {n[1] / c[1], 1}, rem[1] = n[1] % c[1];
    else v[1] = {1e18, 1}, rem[1] = 0;
    if (c[2]) v[2] = {n[2] / c[2], 2}, rem[2] = n[2] % c[2];
    else v[2] = {1e18, 2}, rem[2] = 0;
    sort(all(v));
    v[1].first -= v[0].first, v[2].first -= v[0].first;
    ans += v[0].first;
    v[0].first = 0;
    if (v[0].first < v[1].first) {
        ll d = v[1].first - v[0].first;
        r -= (c[v[0].second] - rem[v[0].second]) * p[v[0].second];
        if (r < 0) goto skip;
        ans++, d--, v[1].first--, v[2].first--, rem[v[0].second] = 0;
        ll mx = (r / p[v[0].second]) / c[v[0].second];
        r -= min(d, mx) * (p[v[0].second] * c[v[0].second]);
        ans += min(d, mx);
        v[1].first -= min(d, mx);
        v[2].first -= min(d, mx);
        if (v[0].first < v[1].first)
            goto skip;
    }
    if (v[1].first < v[2].first) {
        ll d = v[2].first - v[1].first;
        r -= (c[v[0].second] - rem[v[0].second]) * p[v[0].second] + (c[v[1].second] - rem[v[1].second]) * p[v[1].second];
        if (r < 0) goto skip;
        ans++, d--, v[2].first--, rem[v[1].second] = 0, rem[v[0].second] = 0;
        ll mx = r / (p[v[0].second] * c[v[0].second] + p[v[1].second] * c[v[1].second]);
        r -= min(d, mx) * (p[v[0].second] * c[v[0].second] + p[v[1].second] * c[v[1].second]);
        ans += min(d, mx);
        v[2].first -= min(d, mx);
        if (v[1].first < v[2].first)
            goto skip;
    }
    r -= (c[v[0].second] - rem[v[0].second]) * p[v[0].second] + (c[v[1].second] - rem[v[1].second]) * p[v[1].second] + (c[v[2].second] - rem[v[2].second]) * p[v[2].second];
    if (r < 0) goto skip;
    ans++;
    ans += r / (p[0] * c[0] + p[1] * c[1] + p[2] * c[2]);
skip:;
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
