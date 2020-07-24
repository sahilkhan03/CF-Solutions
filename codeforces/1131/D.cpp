
// Problem : D. Gourmet choice
// Contest : Codeforces - Codeforces Round #541 (Div. 2)
// URL : https://codeforces.com/contest/1131/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

vl link, sz;

ll find(ll a) {
	while(a != link[a]) a = link[a];
	return a;
}

void unite(ll a, ll b) {
	a = find(a), b = find(b);
	if(sz[a] > sz[b]) swap(a, b);
	link[a] = b;
	sz[b] += sz[a];
}
vl vis;
vector<vl> v;
bool ans = 1;
void dfs(ll u) {
	if(!ans) return;
	vis[u] = 1;
	for(auto x: v[u]) {
		if(vis[x] == 1) {
			ans = 0;
			return;
		}
		if(vis[x] == 0) dfs(x);
	}
	vis[u] = 2;
	return;
}
vl res;
void dfs1(ll u) {
	if(res[u] != -1) return;
	res[u] = 1;
	ll f = find(u);
	for(auto x: v[f]) {
		dfs1(x);
		res[u] = max(res[u], res[x] + 1);
	}
}
int main()
{
    fast;
	ll n, m;
	cin >> n >> m;
	link.resize(n + m);
	v.resize(n + m);
	vis.resize(n + m, 0);
	sz.resize(n + m, 1);
	res.resize(n + m, -1);
	for(int i = 0; i < n  + m; i++) 
		link[i] = i;
	vector<string> s(n);
	cin >> s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i][j] == '=') unite(i, n + j);
		}
	}
	debug(link);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i][j] == '>') v[find(i)].pb(find(n + j));
			else if(s[i][j] == '<') v[find(n + j)].pb(find(i));
		}
	}
	debug(v);
	for(int i = 0; i < n + m; i++) {
		if(!ans) {
			cout << "No" << endl;
			return 0;
		}
		if(!vis[find(i)]) {
			dfs(find(i));
		}
	}
	for(int i = 0; i < n + m; i++) {
		if(res[i] == -1) dfs1(i);
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++) 
		cout << res[i] << " ";
	cout << endl;
	for(int i = 0; i < m; i++) 
	cout << res[n + i] << " ";
    return 0;
}
