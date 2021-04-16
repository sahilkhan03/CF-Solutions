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

ll mpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

vl fact(2.1e5);

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	vl o, z;
	set<ll> s;
	for (int i = 0; i < n; i++) s.insert(i);
	for (int i = 0; i < 33; i++) {
		o.clear(), z.clear();
		for (int j = 0; j < n; j++) {
			if (v[j] & (1ll << i)) o.pb(j);
			else z.pb(j);
		}
		if (z.empty()) continue;
		for (auto x : o) s.erase(x);
	}
	ll sz = s.size();
	(sz *= sz - 1) %= mod;
	cout << fact[n - 2] * sz % mod << endl;
}

int main()
{
	fast;
	int T = 1;
	fact[0] = 1;
	for (int i = 1; i <= 2e5; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
