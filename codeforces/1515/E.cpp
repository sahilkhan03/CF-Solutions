#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define vi vector<int>
#define endl '\n'

template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
	return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, pair<T1, T2> &t) {
	is >> t.first >> t.second;
	return is;
}

#ifdef LOCAL
#define debug(args...) (Debugger()), args
class Debugger {
public:
	bool first;
	string separator;
	Debugger(const string &_separator = ", ") : first(true), separator(_separator) {}
	template <typename ObjectType>
	Debugger &operator, (const ObjectType &v) {
		if (!first) cerr << separator;
		cerr << v;
		first = false;
		return *this;
	}
	~Debugger() { cerr << endl; }
};
#else
#define debug(args...)
#endif

ll mod;
vl fact(500), inv(500), pw(500);

ll mpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n ) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

void solve() {
	ll n;
	cin >> n >> mod;
	inv[0] = fact[0] = pw[0] = 1;
	for (int i = 1; i <= 500; i++) {
		fact[i] = fact[i - 1] * i % mod;
		pw[i] = pw[i - 1] * 2 % mod;
		inv[i] = mpow(fact[i], mod - 2);
	}
	vector<vl> dp(n + 2, vl(n + 2));
	dp[0][0] = 1;
	for (int len = 0; len < n; len++) {
		for (int cnt = 0; cnt <= len; cnt++) {
			for (int k = 1; len + k + 1 < n + 2; k++) {
				ll x = dp[len][cnt] * pw[k - 1] % mod;
				x = x * fact[cnt + k] % mod;
				x = x * inv[k] % mod;
				x = x * inv[cnt] % mod;
				(dp[len + k + 1][cnt + k] += x) %= mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) (ans += dp[n + 1][i]) %= mod;
	cout << ans << endl;
}

int main()
{
	fast;
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
