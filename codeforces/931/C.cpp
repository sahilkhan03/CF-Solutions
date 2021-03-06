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

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	sort(all(v));
	if (v[n - 1] - v[0] < 2) {
		cout << n << endl;
		cout << v << endl;
		return;
	}
	vl cnt(3);
	cnt[0] = upper_bound(all(v), v[0]) - v.begin();
	cnt[1] = upper_bound(all(v), v[0] + 1) - lower_bound(all(v), v[0] + 1);
	cnt[2] = n - cnt[0] - cnt[1];
	ll ans = n, sum = cnt[0] * v[0] + cnt[1] * (v[0] + 1) + cnt[2] * (v[0] + 2);
	vl c = cnt;
	for (ll i = 0; i <= n; i++) {
		ll x = sum - (n - i) * (v[0] + 1) - i * v[0];
		if (x >= 0 and x <= n - i) {
			ll cur = min(cnt[0], i) + min(cnt[2], x) + min(cnt[1], n - i - x);
			if (cur < ans) ans = cur, c = {i, n - i - x, x};
		}
	}
	cout << ans << endl;
	while (c[0]--) cout << v[0] << " ";
	while (c[1]--) cout << v[0] + 1 << " ";
	while (c[2]--) cout << v[0] + 2 << " ";
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
