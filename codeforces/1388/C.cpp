
// Problem : C. Uncle Bogdan and Country Happiness
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/C
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

ll n, m;
vl pi, dif;
vector<vl> v;
bool ans = 1;

pl dfs(ll u, ll p) {
	if(!ans) return {0, 0};
	ll h = 0, b = 0, tp = pi[u];
	for(auto x: v[u]) {
		if(x != p) {
			debug(x + 1, u + 1);
			auto tmp = dfs(x, u);
			if(!ans) return {0, 0};
			h += tmp.F, b += tmp.S, tp += tmp.F + tmp.S;
		}
	}
	ll H = (tp + dif[u])/2, B = tp - H;
	ll cH = H - h, cB = B - b;
	if(pi[u] > cB) {
		cH -= pi[u] - cB; cB = 0;
	}
	else cB -= pi[u];
	debug(u + 1, H, B, cH, cB);
	if(cB > 0 or cH < 0 or H < 0 or B < 0 or H + B != tp or H - B != dif[u]) {
		ans = 0; 
		return {0, 0};
	}
	return {H, B};
}

void solve() {
	ans = 1;
	cerr << endl;
	cin >> n >> m;
	pi.clear(); dif.clear(); v.clear();
	pi.resize(n); dif.resize(n); v.resize(n);
	cin >> pi >> dif;
	for(int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	auto res = dfs(0, -1);
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	fast;
   ll t = 1;
   cin >> t;
   while(t--) {
   	solve();
   }
	return 0;
}
