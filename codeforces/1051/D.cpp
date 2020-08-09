
// Problem : D. Bicolorings
// Contest : Codeforces - Educational Codeforces Round 51 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1051/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
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

const ll mod = 998244353 ;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<vector<vl>> dp(4, vector<vl>(n + 1, vl(2*n + 2)));
	dp[0][1][1] = 1;
	dp[1][1][2] = 1;
	dp[2][1][2] = 1;
	dp[3][1][1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int k = 1; k <= 2*n; k++) {
			(dp[0][i][k] += dp[0][i - 1][k] + dp[1][i - 1][k] + dp[2][i - 1][k] + dp[3][i - 1][k - 1]) %= mod;
			(dp[1][i][k] += dp[0][i - 1][k - 1] + dp[1][i - 1][k] + dp[2][i - 1][max(k - 2, 0)] + dp[3][i - 1][k - 1]) %= mod;
			(dp[2][i][k] += dp[1][i - 1][max(k - 2, 0)] + dp[0][i - 1][k - 1] + dp[2][i - 1][k] + dp[3][i - 1][k - 1]) %= mod;
			(dp[3][i][k] += dp[0][i - 1][k - 1] + dp[1][i - 1][k] + dp[2][i - 1][k] + dp[3][i - 1][k]) %= mod;
		}
	} 
	ll ans = 0;
	for(int i = 0 ; i < 4; i++) (ans += dp[i][n][k]) %= mod;
	cout << ans << endl;
}

int main()
{
	fast;
   ll t = 1;
   // cin >> t;
   while(t--) {
   	solve();
   }
	return 0;
}
