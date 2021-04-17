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

vi sieve(2e6 + 5);

set<ll> primes, cur;
void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	for (int i = 2; i < 2e6 + 5; i++) {
		if (!sieve[i]) {
			primes.insert(i);
			for (int j = i ; j < 2e6 + 5 ; j += i)
				sieve[j] = i;
		}
	}
	debug(primes.size());
	ll num, i = 0, f = 0;
	while (i < n and !f) {
		while (true) {
			num = v[i];
			cur.clear();
			while (num != 1) {
				cur.insert(sieve[num]);
				num /= sieve[num];
			}
			for (auto x : cur) {
				if (primes.find(x) == primes.end()) {
					v[i]++; f = 1;
					goto skip;
				}
			}
			for (auto x : cur) primes.erase(x);
			cout << v[i++] << " ";
			break;
skip:;
		}
	}
	for (auto x : primes) {
		if (i >= n) break;
		cout << x << " ";
		i++;
	}
	cout << endl;
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
