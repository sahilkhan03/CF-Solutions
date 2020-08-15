
// Problem : 
// 			E - Picking Goods
// 			
// 		
// Contest : AtCoder - AtCoder Beginner Contest 175
// URL : https://atcoder.jp/contests/abc175/tasks/abc175_e
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
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

const ll mod = 1e9 + 7;

void solve() {
	ll r, c, k;
	cin >> r >> c >> k;
	vector<vl> v(r, vl(c, 0));
	while(k--) {
		ll a, b, x;
		cin >> a >> b >> x;
		v[a - 1][b - 1] = x;
	}
	debug(v);
	vector<vector<vl>> dp(4, vector<vl>(r + 1, vl(c + 1, 0)));
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			for(int cnt = 0; cnt < 4; cnt++) {
				if(!cnt) {
					dp[0][i][j] = max(dp[0][i][j], dp[0][i][j - 1]);
					for(int l = 0; l < 4; l++) 
						dp[0][i][j] = max(dp[0][i][j], dp[l][i - 1][j]);
				}
				else if(cnt == 1) {
					dp[1][i][j] = max(dp[1][i][j - 1], dp[0][i][j - 1] + v[i - 1][j - 1]);
					for(int l = 0; l < 4; l++)
						dp[1][i][j] = max(dp[1][i][j], dp[l][i - 1][j] + v[i - 1][j - 1]);
				}
				else {
					dp[cnt][i][j] = max(dp[cnt][i][j - 1], dp[cnt - 1][i][j - 1] + v[i - 1][j - 1]);
				}
				debug(cnt, i, j, dp[cnt][i][j]);
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < 4; i++) ans = max(ans, dp[i][r][c]);
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
