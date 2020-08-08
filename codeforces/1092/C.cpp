
// Problem : C. Prefixes and Suffixes
// Contest : Codeforces - Codeforces Round #527 (Div. 3)
// URL : https://codeforces.com/contest/1092/problem/C
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
vector<vector<pair<string, ll>>> sz;
bool check(string &s) {
	for(int i = 1; i < s.size(); i++) {
		string pre = s.substr(0, i), 
				 suf = s.substr(s.size() - i);
		if((sz[i][0].F == pre and sz[i][1].F == suf) or 
		    (sz[i][1].F == pre and sz[i][0].F == suf)) continue;
		return 0; 		
	}
	return 1;
}

void solve() {
	ll n; cin >> n;
	sz.resize(n);
	for(int i = 0; i < 2*n - 2; i++) {
		string t; cin >> t;
		sz[t.size()].pb({t, i});
	}
	vector<char> ans(2*n - 2, '.');
	string ans1 = sz[n - 1][0].F + sz[n - 1][1].F.back(),
			 ans2 = sz[n - 1][1].F + sz[n - 1][0].F.back();
	string an;
	if(check(ans1)) an = ans1;
	else an = ans2;
	for(int i = 1; i < n; i++) {
		string pre = an.substr(0, i), 
				 suf = an.substr(n - i);
		if(sz[i][0].F == pre and sz[i][1].F == suf) 
			ans[sz[i][0].S] = 'P', ans[sz[i][1].S] = 'S';
		else ans[sz[i][0].S] = 'S', ans[sz[i][1].S] = 'P';
	}
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
