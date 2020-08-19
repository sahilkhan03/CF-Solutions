
// Problem : C. Hard problem
// Contest : Codeforces - Codeforces Round #367 (Div. 2)
// URL : https://codeforces.com/contest/706/problem/C
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

bool check(int i, bool rev1, bool rev2) {
	ll n1 = s[i - 1].size(), n2 = s[i].size();
	if(!rev1 and !rev2) {
		for(int j = 0; j < min(n1, n2); j++) {
			if(s[i - 1][j] < s[i][j]) return 1;
			else if(s[i - 1][j] > s[i][j]) return 0;
		}
	}
	else if(rev1 and !rev2) {
		for(int j = n1 - 1, k = 0; j >= 0 and k < n2; j--, k++) {
			if(s[i - 1][j] < s[i][k]) return 1;
			else if(s[i - 1][j] > s[i][k]) return 0;
		}
	}
	else if(!rev1 and rev2) {
		for(int j = 0, k = n2 - 1; j < n1 and k >= 0; j++, k--) {
			if(s[i - 1][j] < s[i][k]) return 1;
			else if(s[i - 1][j] > s[i][k]) return 0;
		}	
	}
	else {
		for(int j = n1 - 1, k = n2 - 1; j >= 0 and k >= 0; j--, k--) {
			if(s[i - 1][j] < s[i][k]) return 1;
			else if(s[i - 1][j] > s[i][k]) return 0;
		}
	}
	return (n1 <= n2);
}

void solve() {
	ll n; cin >> n;
	vl cost(n); cin >> cost;
	s.resize(n); cin >> s;
	vector<vl> dp(2, vl(n, 1e18));
	dp[0][0] = 0; dp[1][0] = cost[0];
	for(int i = 1; i < n; i++) {
		dp[0][i] = (check(i, 0, 0) ? dp[0][i - 1] : 1e18);
		if(check(i, 1, 0)) dp[0][i] = min(dp[0][i], dp[1][i - 1]);
		dp[1][i] = (check(i, 0, 1) ? dp[0][i - 1] + cost[i]: 1e18);
		if(check(i, 1, 1)) dp[1][i] = min(dp[1][i], dp[1][i - 1] + cost[i]);
	}
	ll ans = min(dp[0][n - 1], dp[1][n - 1]);
	if(ans >= 1e18) cout << -1 << endl;
	else cout << ans << endl;
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
