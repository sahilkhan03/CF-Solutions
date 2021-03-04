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

ll calc(ll n, ll r) {
	if (n < r) return 0;
	if (r > n - r) r = n - r;
	if (!r) return 1;
	ll ans = 1;
	for (ll i = 1; i <= r; i++) {
		ans *= n - i + 1;
		ans /= i;
	}
	return ans;
}

void solve() {
	ll n, t;
	cin >> n >> t;
	ll c = log2(t) + 1;
	if (t != (1ll << (c - 1))) {
		cout << 0 << endl;
		return;
	}
	n++;
	ll j = log2(n);
	ll ans = calc(j, c--);
	for (ll i = j - 1; i >= 0 and c > 0; i--) {
		if (n & (1ll << i)) {
			ans += calc(i, c--);
		}
	}
	cout << ans + (!c) - (t == 1) << endl;
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
