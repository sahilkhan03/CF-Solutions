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
	ld r, a, b, x, y;
	cin >> r >> a >> b >> x >> y;
	auto dist = [&](ld p, ld q, ld r, ld s) {
		return sqrtl((p - r) * (p - r) + (q - s) * (q - s));
	};
	auto calc = [&](ld xx) {
		return sqrtl(r * r - (xx - a) * (xx - a));
	};
	if (dist(a, b, x, y) > r) {
		printf("%.10Lf %.10Lf %.10Lf\n", a, b, r);
		return;
	}
	ld mid, y1, y2, y3, dist1, dist2, dist3, lo = a - r, hi = a + r;
	for (int i = 0; i < 100; i++) {
		mid = (lo + hi) / 2;
		y1 = calc(mid - 1e-6), y2 = calc(mid), y3 = calc(mid + 1e-6);
		dist1 = max(dist(x, y, mid - 1e-6, b + y1), dist(x, y, mid - 1e-6, b - y1));
		dist2 = max(dist(x, y, mid, b + y2), dist(x, y, mid, b - y2)),
		dist3 = max(dist(x, y, mid + 1e-6, b + y3), dist(x, y, mid + 1e-6, b - y3));
		if (dist(x, y, mid, b + y2) > dist(x, y, mid, b - y2))
			y2 = b + y2;
		else y2 = b - y2;
		if (dist1 > dist2) hi = mid;
		else if (dist3 > dist2) lo = mid;
		else break;
	}
	printf("%.10Lf %.10Lf %.10Lf\n", (mid + x) / 2, (y2 + y) / 2, dist2 / 2);
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
