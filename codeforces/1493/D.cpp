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

const ll mod = 1e9 + 7;

vl sieve(1e6);

ll modpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		p /= 2, (n *= n) %= mod;
	}
	return ans;
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vl v(n); cin >> v;
	vector<map<ll, ll>> fac(n);
	ll g = v[0];
	map<ll, ll> pr, cnt;
	for (int i = 0; i < n; i++) {
		g = __gcd(g, v[i]);
		while (v[i] != 1) {
			fac[i][sieve[v[i]]]++;
			pr[sieve[v[i]]] = 0;
			v[i] /= sieve[v[i]];
		}
	}
	for (auto& [x, c] : pr) {
		while (fac[pr[x]][x] > cnt[x]) {
			pr[x]++;
			if (pr[x] == n) pr[x] = 0, cnt[x]++;
		}
	}
	while (q--) {
		ll i, x; cin >> i >> x;
		i--;
		map<ll, ll> fact;
		while (x != 1) {
			fac[i][sieve[x]]++;
			fact[sieve[x]] = 0;
			x /= sieve[x];
		}
		for (auto& [f, c] : fact) {
			while (fac[pr[f]][f] > cnt[f]) {
				pr[f]++;
				if (pr[f] == n) cnt[f]++, c++, pr[f] = 0;
			}
			(g *= modpow(f, c)) %= mod;
			// debug(f, c, cnt[f], pr[f]);
		}
		cout << g << endl;
	}
}

int main()
{
	fast;
	sieve[1] = 1;
	for (int i = 2; i < 1e6; i++) {
		if (!sieve[i]) {
			for (int j = i; j < 1e6; j += i) sieve[j] = i;
		}
	}
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
