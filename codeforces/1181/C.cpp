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
void __print(bool x) {cerr << x;}

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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    cin >> s;
    vector<vl> v(n, vl(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j]) continue;
            v[i][j] = 1;
            for (int k = i + 1; k < n; k++)
                if (s[k][j] == s[k - 1][j]) v[k][j] = v[k - 1][j] + 1;
        }
    }
    debug(v);
    ll ans = 0, len = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            ll c = v[i][j];
            if (i - c >= 0 and v[i][j] <= v[i - c][j] and i + c < n and c == v[i + c][j]) {
                if (j > 0 and v[i][j - 1] == c and v[i - c][j - 1] >= c and v[i + c][j - 1] == c and s[i][j] == s[i][j - 1] and s[i - c][j - 1] == s[i - c][j] and s[i + c][j] == s[i + c][j - 1]) len++;
                else {
                    ans += len * (len + 1) / 2;
                    len = 1;
                }
            }
            else {
                ans += len * (len + 1) / 2;
                len = 0;
            }
        }
        if (len) ans += len * (len  + 1) / 2;
        len = 0;
    }
    cout << ans << endl ;


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s";
#endif

    return 0;
}
