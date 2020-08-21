
// Problem : D. Yet Another Problem On a Subsequence
// Contest : Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1000/problem/D
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

const ll mod = 998244353;
vl fact(1005), inv(1005);

ll modpow(ll n, ll p) {
	ll ans = 1;
	while(p) {
		if(p & 1) (ans*=n) %= mod;
		(n*=n) %= mod, p /= 2;
	}
	return ans;
}

ll calc(ll n, ll r) {
	if(n < r) return 0;
	ll ans = fact[n];
	(ans *= inv[r]) %= mod;
	(ans *= inv[n- r]) %= mod;
	return ans;
}

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	fact[0] = 1, inv[0] = 1;
	for(int i = 1; i <= 1001; i++) {
		fact[i] = (fact[i - 1]*i)%mod;
		inv[i] = modpow(fact[i], mod - 2);
	}
	vl dp(n + 1, 0);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ll y = 0;
		if(v[i - 1] > 0) y = calc(n - i, v[i - 1]);
		(ans += y * (dp[i - 1] + 1)) %= mod;
		debug(i, ans);
		for(int j = 1; j < i; j++) {
			ll cur = 0;
			if(v[j - 1] > 0) cur = calc(i - j, v[j - 1]);
			(dp[i] += (dp[j - 1] + 1)*cur) %= mod;
		}
	}
	debug(dp);
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
