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
	int n, m;
	cin >> n >> m;
	vl v(n), a, b;
	cin >> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 1) a.pb(v[i]);
		else b.pb(v[i]);
	}
	if (accumulate(all(v), 0ll) < m) {
		cout << -1 << endl;
		return;
	}
	sort(all(a), greater<ll>());
	sort(all(b), greater<ll>());
	vl prea = {0}, preb = {0};
	for (auto x : a) prea.pb(prea.back() + x);
	for (auto x : b) preb.pb(preb.back() + x);
	ll ans = 2 * n, j = preb.size() - 1;
	for (ll i = 0; i < prea.size(); i++) {
		while (j >= 0 and preb[j] + prea[i] >= m) j--;
		if (j + 1 < preb.size() and prea[i] + preb[j + 1] >= m)
			ans = min(ans, i + (j + 1) * 2);
	}
	cout << ans << endl;
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
