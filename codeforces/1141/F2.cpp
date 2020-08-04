// Problem : F2. Same Sum Blocks (Hard)
// Contest : Codeforces - Codeforces Round #547 (Div. 3)
// URL : https://codeforces.com/contest/1141/problem/F2
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	“Whether you think you can, or you think you can’t – you’re right” - Henry Ford 
*/

#pragma GCC optimize("Ofast")
// #pragma GCC target ("sse4")
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
set<ll> s;
void solve() {
	ll n; cin >> n;
	vl v(n), pre(n + 1, 0); cin >> v;
	for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];
	unordered_map<ll, vector<pl>> m;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			m[pre[j] - pre[i - 1]].pb({i, j});
		}
	}
	ll mxs = 1, mxe = v[0];
	for(auto x: m) {
		vector<pl> &ar = x.second;
		sort(all(ar));
		ll lt = 0, c = 0;
		for(int i = 0; i < ar.size(); i++) {
			if(ar[i].F > lt) c++, lt = ar[i].S;
			else lt = min(lt, ar[i].S);
		}
		if(c > mxs) mxs = c, mxe = x.F;
	}
	cout << mxs << endl;
	vector<pl> ans;
	vector<pl> &ar = m[mxe];
	ll lt = 0;
	debug(ar);
	for(int i = 0; i < ar.size(); i++) {
		if(ar[i].F > lt) {
			ans.pb(ar[i]);
			lt = ar[i].S;
		}
		else if(lt > ar[i].S) {
			ans.pop_back();
			lt = ar[i].S;
			ans.pb({ar[i]});
		};
	}
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