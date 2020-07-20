/*
    Author : DemonStar
*/
#pragma GCC optimize("Ofast")
// #pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define loop(i, n) for(ll i = 0; i < n; i++)
#define mset(v, a) memset(v, a, sizeof v);
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
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

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vl> v(m, vl(3));
    cin >> v;
    sort(all(v), [](vl a, vl b) -> bool {
        return a[2] < b[2];
    });
    debug(v);
    map<ll, ll> cnt;
    ll c = 0;
    for (int i = 0; i < min(m, k); i++) {
        if (!cnt.count(v[i][0])) cnt[v[i][0]] = c++;
        if (!cnt.count(v[i][1])) cnt[v[i][1]] = c++;
    }
    ll N = c;
    vector<vl> dis(N, vl(N, 1e18));
    for (int i = 0; i < min(m, k); i++) {
        dis[cnt[v[i][0]]][cnt[v[i][1]]] = v[i][2];
        dis[cnt[v[i][1]]][cnt[v[i][0]]] = v[i][2];
    }
    debug(cnt);
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // for (int i = 0; i < dis[0].size(); i++) {
    //     for (int j = 0; j < dis[0].size(); j++)
    //         if (dis[i][j] == 1e18) cerr << -1 << " ";
    //         else cerr << dis[i][j] << " ";
    //     cerr << endl;
    // }
    vl ans;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ans.push_back(dis[i][j]);
    sort(all(ans));
    cout << ans[k - 1] << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}