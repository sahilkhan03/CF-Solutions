
// Problem : C. Vasya and Basketball
// Contest : Codeforces - Codeforces Round #281 (Div. 2)
// URL : https://codeforces.com/problemset/problem/493/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*	“Whether you think you can or you think you can’t, you’re right” - Henry Ford */

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
	vl a(n); cin >> a;
	ll m; cin >> m;
	vl b(m); cin >> b;
	sort(all(a)); sort(all(b));
	pl ans = {-1e18, 1e18};
	vl v;
	for(auto x: a) v.pb(x);
	for(auto x: b) v.pb(x);
	sort(all(v));
	for(auto x: v) {
		ll c1 = upper_bound(all(a), x - 1) - a.begin(),
			c2 = upper_bound(all(b), x - 1) - b.begin();
		ll df = c1*2 + (n - c1)*3 - c2*2 - (m - c2)*3;
		if(ans.F - ans.S < df or (ans.F - ans.S == df and ans.F < c1*2 + (n - c1)*3))
			ans = {c1*2 + (n - c1)*3,  c2*2 + (m - c2)*3};
		c1 = upper_bound(all(a), x) - a.begin(),
		c2 = upper_bound(all(b), x) - b.begin();
		df = c1*2 + (n - c1)*3 - c2*2 - (m - c2)*3;
		if(ans.F - ans.S < df or (ans.F - ans.S == df and ans.F < c1*2 + (n - c1)*3))
			ans = {c1*2 + (n - c1)*3,  c2*2 + (m - c2)*3};
		
	}
	cout << ans.F << ":" << ans.S << endl;
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
