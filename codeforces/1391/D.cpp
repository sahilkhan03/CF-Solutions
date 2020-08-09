
// Problem : D. 505
// Contest : Codeforces - Codeforces Round #663 (Div. 2)
// URL : https://codeforces.com/contest/1391/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
vector<string> s;

ll calc2() {
	ll ans = 1e18, n = s.size(), m = s[0].size();
	if(n <= m) {
		vector<vl> dp(4, vl(m + 1, 0));
		for(int i = 1; i <= m; i++) {
			dp[0][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '0');
			dp[0][i] += min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '1');
			dp[1][i] += min(dp[0][i - 1], dp[3][i - 1]);
			dp[2][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '0');
			dp[2][i] += min(dp[0][i - 1], dp[3][i - 1]);
			dp[3][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '1');
			dp[3][i] += min(dp[1][i - 1], dp[2][i - 1]);
		}
		for(int i = 0; i < 4; i++) ans = min(ans, dp[i][m]);
	}
	else {
		vector<vl> dp(4, vl(n + 1, 0));
		for(int i = 1; i <= n; i++) {
			dp[0][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '0');
			dp[0][i] += min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '1');
			dp[1][i] += min(dp[0][i - 1], dp[3][i - 1]);
			dp[2][i] = (s[i - 1][0]!= '1') + (s[i - 1][1] != '0');
			dp[2][i] += min(dp[0][i - 1], dp[3][i - 1]);
			dp[3][i] = (s[i - 1][0] != '1') + (s[i - 1][1] != '1');
			dp[3][i] += min(dp[1][i - 1], dp[2][i - 1]);
		}
		for(int i = 0; i < 4; i++) ans = min(ans, dp[i][n]);
	}
	return ans;
}


ll calc3() {
	ll ans = 1e18, n = s.size(), m = s[0].size();
	if(n <= m) {
		vector<vl> dp(8, vl(m + 1, 0));
		for(int i = 1; i <= m; i++) {
			dp[0][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '0') + (s[2][i - 1] != '0');
			dp[0][i] += min(dp[5][i - 1], dp[2][i - 1]);
			
			dp[1][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '0') + (s[2][i - 1] != '1');
			dp[1][i] += min(dp[4][i - 1], dp[3][i - 1]);
			
			dp[2][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '1') + (s[2][i - 1] != '0');
			dp[2][i] += min(dp[0][i - 1], dp[7][i - 1]);
			
			dp[3][i] = (s[0][i - 1] != '0') + (s[1][i - 1] != '1') + (s[2][i - 1] != '1');
			dp[3][i] += min(dp[6][i - 1], dp[1][i - 1]);
			
			dp[4][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '0') + (s[2][i - 1] != '0');
			dp[4][i] += min(dp[1][i - 1], dp[6][i - 1]);
			
			dp[5][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '0') + (s[2][i - 1] != '1');
			dp[5][i] += min(dp[0][i - 1], dp[7][i - 1]);
			
			dp[6][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '1') + (s[2][i - 1] != '0');
			dp[6][i] += min(dp[4][i - 1], dp[3][i - 1]);
			
			dp[7][i] = (s[0][i - 1] != '1') + (s[1][i - 1] != '1') + (s[2][i - 1] != '1');
			dp[7][i] += min(dp[5][i - 1], dp[2][i - 1]);
		}
		for(int i = 0; i < 8; i++) ans = min(ans, dp[i][m]);
	}
	else {
		
		vector<vl> dp(8, vl(n + 1, 0));
		for(int i = 1; i <= n; i++) {
			dp[0][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '0') + (s[i - 1][2] != '0');
			dp[0][i] += min(dp[5][i - 1], dp[2][i - 1]);
			
			dp[1][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '0') + (s[i - 1][2]!= '1');
			dp[1][i] += min(dp[4][i - 1], dp[3][i - 1]);
			
			dp[2][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '1') + (s[i - 1][2] != '0');
			dp[2][i] += min(dp[0][i - 1], dp[7][i - 1]);
			
			dp[3][i] = (s[i - 1][0] != '0') + (s[i - 1][1] != '1') + (s[i - 1][2] != '1');
			dp[3][i] += min(dp[6][i - 1], dp[1][i - 1]);
			
			dp[4][i] = (s[i - 1][0] != '1') + (s[i - 1][1] != '0') + (s[i - 1][2] != '0');
			dp[4][i] += min(dp[1][i - 1], dp[6][i - 1]);
			
			dp[5][i] = (s[i - 1][0] != '1') + (s[i - 1][1] != '0') + (s[i - 1][2] != '1');
			dp[5][i] += min(dp[0][i - 1], dp[7][i - 1]);
			
			dp[6][i] = (s[i - 1][0] != '1') + (s[i - 1][1] != '1') + (s[i - 1][2] != '0');
			dp[6][i] += min(dp[4][i - 1], dp[3][i - 1]);
			
			dp[7][i] = (s[i - 1][0] != '1') + (s[i - 1][1] != '1') + (s[i - 1][2] != '1');
			dp[7][i] += min(dp[5][i - 1], dp[2][i - 1]);
		}
		for(int i = 0; i < 8; i++) ans = min(ans, dp[i][n]);
	}
	return ans;
}



void solve() {
	ll n, m; 
	cin >> n >> m;
	s.resize(n);
	cin >> s;
	if(n > 3 and m > 3) {
		cout << -1 << endl;
		return;
	}
	if(n == 1 or m == 1) {
		cout << 0 << endl;
		return;
	}
	if(min(n, m) == 2) 
	cout << calc2() << endl;
	else cout << calc3() << endl;
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
