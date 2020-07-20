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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vl> v(n, vl(6));
        cin >> v;
        debug(v);
        vl ans = { -100000, 100000, 100000, -100000}; // {L U R D}
        for (int i = 0; i < n; i++) {
            vl cur = {v[i][0], v[i][1], v[i][0], v[i][1]};
            if (v[i][2]) cur[0] = -1e5;
            if (v[i][3]) cur[1] = 1e5;
            if (v[i][4]) cur[2] = 1e5;
            if (v[i][5]) cur[3] = -1e5;
            debug(cur);
            if (ans[0] > cur[2] or cur[0] > ans[2] or ans[1] < cur[3] or ans[3] > cur[1]) {
                cout << "0" << endl;
                goto skip;
            }
            ans[0] = max(ans[0], cur[0]);
            ans[1] = min(ans[1], cur[1]);
            ans[2] = min(ans[2], cur[2]);
            ans[3] = max(ans[3], cur[3]);
        }
        cout << 1 << " " << ans[0] <<  " " << ans[1] << endl;
skip:;
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}