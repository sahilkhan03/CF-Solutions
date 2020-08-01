
// Problem : E. Two Teams
// Contest : Codeforces - Codeforces Round #552 (Div. 3)
// URL : https://codeforces.com/contest/1154/problem/E
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
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	multiset<pl> s;
	multiset<ll> pos;
	for(int i = 0; i < n; i++) pos.insert(i), s.insert({v[i], i});
	vector<char> ans(n, '0');
	int f = 0;
	while(!s.empty()) {
		ll idx = s.rbegin() -> S;
		char cur = char(f + '1');
		ans[idx] = cur;
		debug(f, idx);
		s.erase(s.find({v[idx], idx}));
		auto it = pos.find(idx);
		ll c = k;
		for(auto i = next(it); i != pos.end() and c; c--) {
			ans[*i] = cur;
			s.erase(s.find({v[*i], *i}));
			i++;
			pos.erase(prev(i));
		}
		debug(pos, s);
		c = k;
		auto i = prev(it);
		while(c-- and it != pos.begin()) {
			ans[*i] = cur;
			s.erase(s.find({v[*i], *i}));
			if(i == pos.begin()) {
				pos.erase(i);
				break;
			}
			i--;
			pos.erase(next(i));
		}
		pos.erase(it);
		debug(pos, s);
		f = !f;
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
