
// Problem : F. Yet another 2D Walking
// Contest : Codeforces - Codeforces Round #515 (Div. 3)
// URL : https://codeforces.com/contest/1066/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
	ll n; cin >> n;
	map<ll, vector<pl>> m;
	while(n--) {
		ll a, b;
		cin >> a >> b;
		m[max(a, b)].pb({a, b});
	}
	for(auto& x: m) {
		sort(all(x.S),[](pl a, pl b) -> bool{
			if(a.F == b.F) return a.S > b.S;
			return a.F < b.F;
	   });
	} 
	ll sz = m.size();
	vector<vl> dp(2, vl(sz + 1));
	dp[0][0] = dp[1][0] = 0;
	m[0].pb({0, 0});
	ll i = 1;
	for(auto it = next(m.begin()); it != m.end(); it++) {
		auto& pre = prev(it)->S;
		auto& cur = it->S;
		debug(cur);
		pl fs = cur[0], ls = cur.back();
		pl pfs = pre[0], pls = pre.back();
		ll cdis = abs(fs.F - ls.F) + abs(fs.S - ls.S);
		dp[0][i] = cdis + min(dp[1][i - 1] + abs(fs.F - pfs.F) + abs(fs.S - pfs.S),
		                   dp[0][i - 1] + abs(fs.F - pls.F) + abs(fs.S - pls.S));
		dp[1][i] = cdis + min(dp[1][i - 1] + abs(ls.F - pfs.F) + abs(ls.S - pfs.S),
		                   dp[0][i - 1] + abs(ls.F - pls.F) + abs(ls.S - pls.S));
		debug(dp[0][i], dp[1][i]);
		i++;
	}
	cout << min({dp[0][sz], dp[1][sz]}) << endl;
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
