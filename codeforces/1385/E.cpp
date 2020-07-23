
// Problem : E. Directing Edges
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1385/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
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

const ll mod = 1e9 + 7;

vl tpsort;
bool f = 0;
void dfs(vector<vl> &v, vl &state, ll node, ll prev ) {
    if (f) return;
    if (state[node] == 1) {
        f = 1;
        return;
    }
    if (state[node] == 2) return;
    state[node] = 1;
    for (auto x : v[node]) {
        if (x != prev) dfs(v, state, x, node);
    }
    state[node] = 2;
    tpsort.push_back(node);
    return;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--) {
        f = 0;
        tpsort.clear();
        ll n, m;
        cin >> n >> m;
        vector<vl> v(n, vl());
        vector<pl> edge;
        while (m--) {
            ll tp, a, b;
            cin >> tp >> a >> b;
            a--, b--;
            if (tp) v[a].push_back(b);
            edge.push_back({a, b});
        }
        vl pos(n + 1, -1);
        vl state(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (!state[i]) dfs(v, state, i, -1);
            if (f) {
                cout << "NO" << endl;
                goto skip;
            }
        }
        reverse(all(tpsort));
        debug(tpsort);
        cout << "YES" << endl;
        for (int i = 0; i < tpsort.size(); i++) pos[tpsort[i]] = i;
        for (auto x : edge) {
            if (pos[x.first] < pos[x.second]) {
                cout << x.first + 1 << " " << x.second + 1 << endl;
            }
            else cout << x.second + 1 << " " << x.first + 1 << endl;
        }
skip:;
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
