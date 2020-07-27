
// Problem : E. Vasya and a Tree
// Contest : Codeforces - Educational Codeforces Round 54 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1076/problem/E
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

const ll mod = 1e9 + 7;
vector<vl> v;
vector<vector<pl>> upd;
const ll N = 5e5;
vl res, fen(N, 0);
void add(ll i, ll d, ll x) {
	ll j = i;
	while(j < N) {
		fen[j] += x;
		j += j & (-j);	
	}
	j = i + d + 1;
	while(j < N) {
		fen[j] -= x;
		j += j & (-j);	
	}
	return;
}

ll sum(int i) {
	ll ans = 0;
	while(i) {
		ans += fen[i];
		i -= i & (-i);
	}
	return ans;
}
void dfs(ll u, ll p, ll dis) {
	for(auto& x: upd[u]) add(dis, x.F, x.S);
	res[u] = sum(dis);
	for(auto& x: v[u]) {
		if(x != p) dfs(x, u, dis + 1);
	}
	for(auto& x: upd[u]) add(dis, x.F, -x.S);
}

int main()
{
    fast;
 	 ll n; scanf("%lld", &n);
 	 v.resize(n); upd.resize(n); res.resize(n);
 	 for(ll i = 0; i < n - 1; i++) {
 	 	ll a, b; scanf("%lld %lld", &a, &b);
 	 	a--, b--;
 	 	v[a].pb(b);
 	 	v[b].pb(a);
 	 }
 	 ll m; scanf("%lld", &m);
 	 while(m--) {
 	 	ll u, d, x;
 	 	scanf("%lld %lld %lld", &u, &d, &x);
 	 	u--; d = min(d, n);
 	 	upd[u].push_back({d, x}); 
 	 }
 	 dfs(0, -1, 1);
 	 for(auto x: res) printf("%lld ", x);
    printf("\n");
    return 0;
}
