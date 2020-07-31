
// Problem : D. Captain Flint and Treasure
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
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

vl cur;
vector<bool> vis;
vector<vl> v;

void dfs(ll u) {
	if(vis[u]) return;
	for(auto x: v[u]) {
		if(!vis[x]) dfs(x);
	}
	vis[u] = 1;
	cur.pb(u + 1);
	return;
}

void solve() {
	ll n; cin >> n;
	vis.resize(n , 0);
	v.resize(n); cur.clear();
	vl val(n); cin >> val;
	vl pos(n); cin >> pos;
	for(int i = 0; i < n; i++) {
		if(pos[i] != -1) {
			v[i].pb(pos[i] - 1);
		}
	}
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(!vis[i]) dfs(i);
	}
	debug(v, cur);
	vis = vector<bool>(n, 0);
	vl ans;
	for(int i = n - 1; i >= 0; i--) {
		ll idx = cur[i] - 1;
		if(val[idx] < 0) continue;
		vis[i] = 1;
		ans.pb(cur[i]);
		sum += val[idx];
		if(pos[idx] != -1)
			val[pos[idx] - 1] += val[idx];
		debug(val[cur[i] - 1]);
	}
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			ans.pb(cur[i]);
			sum += val[cur[i] - 1];
			debug(i);
		}
	}
	cout << sum << endl << ans << endl;
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
