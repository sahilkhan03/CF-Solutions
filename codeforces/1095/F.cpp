
// Problem : F. Make It Connected
// Contest : Codeforces - Codeforces Round #529 (Div. 3)
// URL : https://codeforces.com/contest/1095/problem/F
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
vl link, sz;

ll find(ll a) {
	while(a != link[a]) a = link[a];
	return a;
}

void unite(ll a, ll b) {
	a = find(a), b = find(b);
	if(sz[a] > sz[b]) swap(a, b);
	sz[b] += sz[a];
	link[a] = b;
}

void solve() {
	ll n, m; 
	cin >> n >> m;
	link = vl(n), sz = vl(n, 1);
	vector<pl> v;
	for(int i = 0; i < n; i++) {
		link[i] = i;
		ll a; cin >> a;
		v.pb({a, i});
	}
	sort(all(v));
	set<vl> edge;
	for(int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge.insert({c, a, b});
	}
	for(int i = 1; i < n; i++) {
		edge.insert({v[i].F + v[0].F, v[i].S, v[0].S});	
	}
	ll ans = 0;
	for(auto x: edge) {
		if(find(x[1]) == find(x[2])) continue;
		ans += x[0];
		unite(x[1], x[2]);
	}
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
