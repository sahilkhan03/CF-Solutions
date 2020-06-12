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

bitset<100005> vis;
vl inv(1e5 + 5);
int dfs(vector<map<int, int>> &v, int u, int j) {
    if (vis[u]) return 0;
    int ans = (inv[u + 1] == j + 1);
    vis[u] = 1;
    debug(u + 1);
    for (auto x : v[u]) {
        if (!x.second)
            ans += dfs(v, x.first, j);
    }
    if (inv[u + 1] != j + 1) vis[u] = 0;
    debug(u + 1, ans);
    return ans;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    ll n, m, k;
    cin >> n >> m >> k;
    vl types(k);;
    cin >> types;
    int c = 1;
    loop(i, k) {
        loop(l, types[i])
        inv[c++] = i + 1;
    }
    vector<map<int, int>> v(n);
    vector<vector<int>> adj(k, vector<int>(k, mod));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (v[a - 1].count(b - 1))
            c = min(c, v[a - 1][b - 1]);
        v[a - 1][b - 1] = c;
        v[b - 1][a - 1] = c;
        if (inv[a] != inv[b]) {
            adj[inv[a] - 1][inv[b] - 1] = min(adj[inv[a] - 1][inv[b] - 1], c);
            adj[inv[b] - 1][inv[a] - 1] = min(adj[inv[b] - 1][inv[a] - 1], c);
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cnt = dfs(v, i, j);
            debug(i , j, types[j], cnt);
            if (j >= k or types[j] != cnt) {
                cout << "No" << endl;
                goto skip;
            }
            j++;
        }
    }
    cout << "Yes" << endl;
    for (int l = 0; l < k; l++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) adj[i][j] = 0;
                adj[i][j] = min(adj[i][j], adj[i][l] + adj[l][j]);
            }
        }
    }
    for (auto x : adj) {
        for (auto y : x)
            if (y == mod) cout << -1 << " ";
            else cout << y << " ";
        cout << endl;
    }

skip:;



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}