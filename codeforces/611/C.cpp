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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
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

const ll mod = 1e9 + 7;

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    cin >> s;
    vector<vl> pre(n + 1, vl(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j - 1];
            for (int k = 1; k <= i; k++) {
                if (j > 1 and s[k - 1][j - 1] == '.' and s[k - 1][j - 2] == '.') pre[i][j]++;
                if (k > 1 and s[k - 1][j - 1] == '.' and s[k - 2][j - 1] == '.') pre[i][j]++;
            }
            for (int k = 1; k < j; k++) {
                if (k > 1 and s[i - 1][k - 1] == '.' and s[i - 1][k - 2] == '.') pre[i][j]++;
                if (i > 1 and s[i - 1][k - 1] == '.' and  s[i - 2][k - 1] == '.') pre[i][j]++;
            }
        }
    }
    debug(pre);
    ll q;
    cin >> q;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = pre[c][d] - pre[a][d] - pre[c][b] + pre[a][b];
        for (int i = b + 1; i <= d; i++)
            if (s[a - 1][i - 1] == '.' and s[a - 1][i - 2] == '.') ans++;
        for (int i = a + 1; i <= c; i++)
            if (s[i - 1][b - 1] == '.' and s[i - 2][b - 1] == '.') ans++;
        cout << ans << endl;
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}