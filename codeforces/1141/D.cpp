
// Problem : D. Colored Boots
// Contest : Codeforces - Codeforces Round #547 (Div. 3)
// URL : https://codeforces.com/contest/1141/problem/D
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
	ll n; cin >> n;
	string a, b;
	cin >> a >> b;
	vector<vl> v1(26), v2(26);
	vl aq, bq;
	for(int i = 0; i < n; i++) {
		if(a[i] == '?') aq.pb(i + 1);
		else v1[a[i] - 'a'].pb(i + 1);
		if(b[i] == '?') bq.pb(i + 1);
		else v2[b[i] - 'a'].pb(i + 1);
	}
	ll p1 = 0, p2 = 0;
	vector<pl> ans;
	debug(v1); debug(v2);
	for(int i = 0; i < 26; i++) {
		ll j = 0;
		while(j < min(v1[i].size(), v2[i].size())) {
			ans.pb({v1[i][j], v2[i][j]}); j++;
		}
		while(j < v1[i].size() and p2 < bq.size()) {
			ans.pb({v1[i][j], bq[p2]}); j++, p2++;
		}
		while(j < v2[i].size() and p1 < aq.size()) {
			ans.pb({aq[p1], v2[i][j]}); j++, p1++;
		}
	}
	while(p1 < aq.size() and p2 < bq.size()) {
		ans.pb({aq[p1], bq[p2]}); p1++, p2++;
	}
	cout << ans.size() << endl;
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
