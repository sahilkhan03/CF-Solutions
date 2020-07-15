/*
    Author : DemonStar
*/

#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")
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

const ll mod = 1e9 + 7;


int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    ll n;
    cin >> n;
    vector<pl> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    vl p(n + 1, -1);
    vl ans(n);
    sort(all(v));
    vl dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - 3 >= 0 and dp[i] > dp[i - 3] + v[i - 1].first - v[i - 3].first) {
            dp[i] = dp[i - 3] + v[i - 1].first - v[i - 3].first;
            p[i] = i - 3;
        }
        if (i - 4 >= 0 and dp[i] > dp[i - 4] + v[i - 1].first - v[i - 4].first) {
            dp[i] = dp[i - 4] + v[i - 1].first - v[i - 4].first;
            p[i] = i - 4;
        }

        if (i - 5 >= 0 and dp[i] > dp[i - 5] + v[i - 1].first - v[i - 5].first) {
            dp[i] = dp[i - 5] + v[i - 1].first - v[i - 5].first;
            p[i] = i - 5;
        }
    }
    debug(p);
    ll i = n, cur = 1;
    while (p[i] != -1) {
        for (int j = p[i] + 1; j <= i; j++) {
            ans[v[j - 1].second] = cur;
        }
        cur++;
        i = p[i];
    }
    cout << dp[n] << " " << cur - 1 << endl;
    cout << ans << endl;



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
