
// Problem : F2. Pictures with Kittens (hard version)
// Contest : Codeforces - Codeforces Round #521 (Div. 3)
// URL : https://codeforces.com/contest/1077/problem/F2
// Memory Limit : 512 MB
// Time Limit : 2500 ms
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

template<typename T> struct rmq {
	vector<T> v;
	ll n; static const ll b = 30;
	vector<ll> mask, t;
	ll op(ll x, ll y) { return v[x] > v[y] ? x : y; }
	ll msb(ll x) { return __builtin_clz(1)-__builtin_clz(x); }
	ll small(ll r, ll sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (ll i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (ll i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (ll j = 1; (1<<j) <= n/b; j++) for (ll i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	T query(ll l, ll r) {
		if (r-l+1 <= b) return v[small(r, r-l+1)];
		ll ans = op(small(l+b-1), small(r));
		ll x = l/b+1, y = r/b-1;
		if (x <= y) {
			ll j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return v[ans];
	}
};


const ll mod = 1e9 + 7;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vl v(n); cin >> v;
	vl dp(n + 1, -1e18);
	dp[0] = 0;
	rmq<ll> rm(dp);
	for(ll use = 1; use <= x; use++) {
		debug(use, dp);
		for(ll i = 1; i <= n; i++) {
			dp[i] = rm.query(max(0ll, i - k), i - 1) + v[i - 1];
		}
		rm = rmq<ll>(dp);
	}
	debug(rm.query(n - k + 1, n));
	cout << max(-1ll, rm.query(n - k + 1, n)) << endl;
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
