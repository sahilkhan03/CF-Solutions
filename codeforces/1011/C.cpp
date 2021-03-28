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
	ll n, m;
	cin >> n >> m;
	vl a(n), b(n);
	cin >> a >> b;
	if (find(all(a), 1) != a.end() or find(all(b), 1) != b.end()) {
		cout << -1 << endl;
		return;
	}
	auto check = [&] (ld w) {
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			ld req = (m + w) * 1.0 / a[i];
			if (w < req) return 0;
			w -= req;
			req = (m + w) * 1.0 / b[i];
			if (w < req) return 0;
			w -= req;
		}
		return 1;
	};
	ld ans = 0, lo = 0, hi = 1.1e9, mid;
	while (hi - lo > 1e-8) {
		mid = (lo + hi) / 2;
		if (check(mid)) ans = mid, hi = mid;
		else lo = mid;
	}
	printf("%.10Lf\n", ans);
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
