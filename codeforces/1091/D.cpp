#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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

const ll mod = 998244353;

vl fact(1e6 + 4), inv(1e6 + 4);

ll modpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

ll calc(ll n, ll k) {
	ll ans = (fact[n] * (n + 1 - k)) % mod;
	return (ans * inv[n + 2 - k]) % mod;
}

void solve() {
	ll n; cin >> n;
	if (n < 3) {
		cout << n << endl;
		return;
	}
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = modpow(fact[i], mod - 2);
	}
	ll ans = fact[n];
	for (int i = n - 2; i; i--) {
		(ans += i * calc(n, i + 2)) %= mod;
	}
	cout << ans << endl;
}

int main()
{
	fast;
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
