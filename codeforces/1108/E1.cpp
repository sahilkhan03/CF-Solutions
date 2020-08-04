
// Problem : E1. Array and Segments (Easy version)
// Contest : Codeforces - Codeforces Round #535 (Div. 3)
// URL : https://codeforces.com/contest/1108/problem/E1
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

void solve() {
	ll n, m; 
	cin >> n >> m;
	vl v(n); cin >> v;
	vector<pl> seg(m); cin >> seg;
	ll ans = *max_element(all(v)) - *min_element(all(v));
	vl va;
	vector<vl> pts(n + 1);
	for(int j = 0; j < m; j++) {
		pl x = seg[j];
		for(int i = x.F; i <= x.S; i++) pts[i].pb(j); 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ll e1 = v[i - 1], e2 = v[j - 1];
			for(auto y: pts[i]) {
				pl x = seg[y];
				e1--;
				if(x.F <= j and  j <= x.S) e2--;
			}
			if(max(e1, e2) - min(e1, e2) > ans) {
				ans = max(e1, e2) - min(e1, e2);
				va = pts[i];
			}
		}
	}
	cout << ans << endl;
	cout << va.size() << endl;
	for(auto x: va) cout << x + 1 << " ";
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
