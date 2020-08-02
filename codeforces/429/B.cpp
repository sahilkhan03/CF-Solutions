
// Problem : B. Working out
// Contest : Codeforces - Codeforces Round #245 (Div. 1)
// URL : https://codeforces.com/contest/429/problem/B
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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vl> v(n, vl(m)); cin >> v;
	vector<vl> p1(n, vl(m)), p2(n, vl(m)), p3(n, vl(m)), p4(n, vl(m));
	p1[0][0] = v[0][0];
	for(int i = 1; i < m; i++) p1[0][i] = v[0][i] + p1[0][i - 1];
	for(int i = 1; i < n; i++) p1[i][0] = v[i][0] + p1[i - 1][0];
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) p1[i][j] = max(p1[i][j - 1], p1[i - 1][j]) + v[i][j];
	}
	p2[n - 1][m - 1] = v[n - 1][m - 1];
	for(int i = n - 2; ~i; i--) p2[i][m - 1] = p2[i + 1][m - 1] + v[i][m - 1];
	for(int i = m - 2; ~i; i--) p2[n - 1][i] = p2[n - 1][i + 1] + v[n - 1][i];
	for(int i = n - 2; ~i; i--) {
		for(int j = m - 2; ~j; j--) p2[i][j] = max(p2[i + 1][j], p2[i][j + 1]) + v[i][j];
	}
	p3[n - 1][0] = v[n - 1][0];
	for(int i = n - 2; ~i; i--) p3[i][0] = p3[i + 1][0] + v[i][0];
	for(int i = 1; i < m; i++) p3[n - 1][i] = p3[n - 1][i - 1] + v[n - 1][i];
	for(int i = n - 2; ~i; i--) {
		for(int j = 1; j < m; j++) p3[i][j] = max(p3[i + 1][j], p3[i][j - 1]) + v[i][j];
	}
	p4[0][m - 1] = v[0][m - 1];
	for(int i = m - 2; ~i; i--) p4[0][i] = p4[0][i + 1] + v[0][i];
	for(int i = 1; i < n; i++) p4[i][m - 1] = p4[i - 1][m - 1] + v[i][m - 1];
	for(int i = 1; i < n; i++) {
		for(int j = m - 2; ~j; j--) {
			p4[i][j] = max(p4[i - 1][j], p4[i][j + 1]) + v[i][j];
		}
	}
	ll ans = 0;
	for(int i = 1; i < n - 1; i++) {
		for(int j = 1; j < m - 1; j++) {
			ans = max({ans, p1[i - 1][j] + p2[i + 1][j] + p3[i][j - 1] + p4[i][j + 1],
			p1[i][j - 1] + p2[i][j + 1] + p3[i + 1][j] + p4[i - 1][j]});
		}
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
