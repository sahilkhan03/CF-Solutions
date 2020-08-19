
// Problem : B. Segment Occurrences
// Contest : Codeforces - Educational Codeforces Round 48 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1016/problem/B
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
const ll mod1 = 17, mod2 = 31;

ll modpow(ll n, ll p, ll mod) {
	ll ans = 1;
	while(p) {
		if(p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

void solve() {
	ll n, m, q;
	cin >> n >> m >> q;
	string s, t; cin >> s >> t;
	ll hash1 = 0, hash2 = 0;
	for(int i = 0; i < t.size(); i++) 
		hash1 = ((hash1*mod1) + t[i])%mod,
		hash2 = ((hash2*mod2) + t[i]) %mod;
	debug(hash1, hash2);
	vl pre(s.size() + 1, 0), ph1(s.size() + 1, 0), ph2(s.size() + 1, 0);
	ll ch1 = 0, ch2 = 0;
	for(int i = 0; i < s.size(); i++) {
		ch1 = ((ch1*mod1) + s[i])%mod;
		ch2 = ((ch2*mod2) + s[i]) %mod;
		ph1[i + 1] = ch1, ph2[i + 1] = ch2;
		if(i >= t.size() - 1) {
			ll cur1 = (ph1[i + 1] - ph1[i + 1 - t.size()]*modpow(mod1, t.size(), mod) + mod*mod)%mod;
			ll cur2 = (ph2[i + 1] - ph2[i + 1 - t.size()]*modpow(mod2, t.size(), mod) + mod*mod)%mod;
			if(cur1 == hash1 and cur2 == hash2) pre[i + 1]++;
		}
		pre[i + 1] += pre[i];
	}
	debug(ph1);
	debug(pre);
	while(q--) {
		ll l, r;
		cin >> l >> r;
		if(r - l + 1 < t.size()) {
			cout << 0 << endl;
			continue;
		}
		cout << pre[r] - pre[l + t.size() - 2] << endl;
	}
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
