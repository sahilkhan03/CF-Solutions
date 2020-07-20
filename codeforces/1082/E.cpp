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

ll calc(vl &v) {
    ll ans = 0, sum = 0;
    for (auto x : v) {
        sum = max(sum + x, x);
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n, c;
    cin >> n >> c;
    vl v(n);
    cin >> v;
    ll ans = 0, C = 0;
    vector<vl> d(5e5 + 5, vl());
    vl pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (v[i] == c) C++;
        else d[v[i]].push_back(i + 1);
        pre[i + 1] = C;
    }   ans = C;
    for (int i = 1; i <= 5e5; i++) {
        if (d[i].empty()) continue;
        vl tmp = {1};
        for (int j = 1; j < d[i].size(); j++) {
            tmp.push_back(-(pre[d[i][j]] - pre[d[i][j - 1]]));
            tmp.push_back(1);
        }
        ans = max(ans, C + calc(tmp));
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}