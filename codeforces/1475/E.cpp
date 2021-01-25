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

ll modpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		p /= 2, (n *= n) %= mod;
	}
	return ans;
}

ll calc(ll n, ll k) {
	if (k > n - k) k = n - k;
	ll ans = 1;
	for (ll i = 1; i <= k; i++) {
		(ans *= n - i + 1) %= mod;
		(ans *= modpow(i, mod - 2)) %= mod;
	}
	return ans;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	sort(all(v), greater<ll>());
	ll cnt = count(all(v), v[k - 1]), r = count(v.begin(), v.begin() + k, v[k - 1]);
	cout << calc(cnt, r) << endl;
}

int main()
{
	fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
