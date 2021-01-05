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

const ll mod = 1e9 + 7;

vl sieve(1e6 + 5);

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	map<ll, ll> m;
	for (int i = 0; i < n; i++) {
		m.clear();
		while (v[i] != 1) {
			m[sieve[v[i]]]++;
			v[i] /= sieve[v[i]];
		}
		for (auto x : m) if (x.S & 1) v[i] *= x.F;
	}
	debug(v);
	m.clear();
	for (int i = 0; i < n; i++) m[v[i]]++;
	ll one = 0, odd = 0, mx = 0;
	for (auto x : m) {
		if (x.F == 1 or x.S % 2 == 0) one += x.S;
		else odd = max(odd, x.S);
		mx = max(mx, x.S);
	}
	ll q; cin >> q;
	while (q--) {
		ll w; cin >> w;
		if (!w) cout << mx << endl;
		else cout << max(one, odd) << endl;
	}
}

int main()
{
	fast;
	ll T = 1;
	cin >> T;
	sieve[0] = sieve[1] = 1;
	for (int i = 2; i < 1e6 + 5; i++) {
		if (!sieve[i]) {
			for (int j = i; j < 1e6 + 5; j += i) {
				if (!sieve[j]) sieve[j] = i;
			}
		}
	}
	while (T--) {
		solve();
	}
	return 0;
}
