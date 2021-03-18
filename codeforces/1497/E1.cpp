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

vi sieve(5e3);
vi primes;

void solve() {
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	ll ans = 1;
	map<ll, ll> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < primes.size(); j++) {
			ll x = primes[j] * primes[j];
			if (x > v[i]) break;
			while (v[i] % x == 0) v[i] /= x;
		}
		if (m[v[i]]) {
			ans++;
			m.clear();
		}
		m[v[i]]++;
	}
	cout << ans << endl;
}

int main()
{
	fast;
	for (int i = 2; i < 5e3; i++) {
		if (!sieve[i]) {
			primes.pb(i);
			for (int j = i; j < 5e3; j += i) {
				sieve[j] = 1;
			}
		}
	}
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
