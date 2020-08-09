
// Problem : E. Minimal Diameter Forest
// Contest : Codeforces - Codeforces Round #527 (Div. 3)
// URL : https://codeforces.com/contest/1092/problem/E
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
vector<pl> dia;
vector<vl> v;
bitset<1005> vis;

void calc(ll u) {
	queue<vl> q;
	q.push({u, -1, 0});
	pl mx = {u, 0};
	debug(u, mx);
	while(!q.empty()) {
		auto tp = q.front(); q.pop();
		vis[tp[0]] = 1;
		if(mx.S < tp[2]) mx = {tp[0], tp[2]};
		for(auto x: v[tp[0]]) {
			if(x != tp[1]) q.push({x, tp[0], tp[2] + 1});
		}
	}
	q = queue<vl>();
	q.push({mx.F, -1, 0});
	pl dis = {mx.F, 0};
	vl par(1005, -1);
	while(!q.empty()) {
		auto tp = q.front(); q.pop();
		if(dis.S < tp[2]) dis = {tp[0], tp[2]};
		par[tp[0]] = tp[1];
		for(auto x: v[tp[0]]) {
			if(x != tp[1]) q.push({x, tp[0], tp[2] + 1});
		}
	}
	ll len = dis.S / 2, pt = dis.F;
	while(len--) pt = par[pt];
	dia.pb({dis.S, pt});
}

void solve() {
	ll n, m; 
	cin >> n >> m;
	v.resize(n);
	while(m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 0; i < n; i++) if(!vis[i]) calc(i);
	sort(all(dia), greater<pl>());
	vector<pl> ans;
	for(int i = 1; i < dia.size(); i++) {
		v[dia[i].S].pb(dia[0].S),
		v[dia[0].S].pb(dia[i].S);
		ans.pb({dia[i].S + 1, dia[0].S + 1});
	}
	calc(0);
	cout << dia.back().F << endl;
	for(auto x: ans) cout << x << endl;
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
