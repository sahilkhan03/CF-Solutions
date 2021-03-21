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
	vector<pl> v(n);
	cin >> v;
	bool f1 = 0, f2 = 0;
	int c = 0;
	for (auto [a, b] : v) {
		if (b > 0) f1 = 1;
		else if (b < 0) f2 = 1;
		else c++;
	}
	if (c > 1 or (f1 and f2)) {
		cout << -1 << endl;
		return;
	}
	for (auto& [a, b] : v) b = abs(b);
	auto calc = [&](ld rad) {
		ld l = -1e18, r = 1e18;
		for (auto [x, y] : v) {
			ld b = -2 * x;
			ld c = x * x + y * y - 2 * y * rad;
			if (b * b - 4 * c < 0) return false;
			ld d = sqrtl(b * b - 4 * c);
			l = max(l, (-b - d) / 2);
			r = min(r, (-b + d) / 2);
		}
		return (l <= r);
	};
	ld lo = 0, hi = 1e18, mid, ans = 1e18;
	for (int i = 0; i < 200; i++) {
		mid = (lo + hi) / 2;
		if (calc(mid)) hi = mid, ans = mid;
		else lo = mid;
	}
	printf("%.10Lf\n",  ans);
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
