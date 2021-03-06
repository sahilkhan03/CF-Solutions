
// Problem : C. Vasya and Multisets
// Contest : Codeforces - Educational Codeforces Round 51 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1051/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
	ll n; cin >> n;
	vl v(n); cin >> v;
	vector<vl> pos(105, vl());
	for(int i = 0; i < n; i++) pos[v[i]].pb(i);
	vector<vl> cnt(105, vl());
	for(int i = 0; i < 105; i++) {
		cnt[pos[i].size()].pb(i);
	}
	debug(cnt);
	vector<char> ans(n, '.');
	for(int i = 0; i < cnt[2].size(); i++) {
		ans[pos[cnt[2][i]][0]] = 'A';
		ans[pos[cnt[2][i]][1]] = 'A';
	}
	debug(cnt[1].size());
	for(int i = 0; i < cnt[1].size(); i++) 
		if(i & 1) ans[pos[cnt[1][i]][0]] = 'A';
		else ans[pos[cnt[1][i]][0]] = 'B';
	bool f = (cnt[1].size() % 2);
	if(f) {
		ll j = 3;
		while(j < 103 and cnt[j].empty()) j++;
		if(j > 100) {
			cout << "NO" << endl;
			return;
		}
		ans[pos[cnt[j][0]][0]] = 'A';
		for(int i = 1; i < pos[cnt[j][0]].size(); i++)
			ans[pos[cnt[j][0]][i]] = 'B';
	}
	for(auto& x: ans) if(x == '.') x = 'A';
	cout << "YES" << endl;
	for(auto x: ans) cout << x;
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
