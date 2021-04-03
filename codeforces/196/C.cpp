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
	int n; cin >> n;
	vector<vi> v(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	vector<array<ll, 3>> pts(n);
	for (int i = 0; i < n; i++) {
		cin >> pts[i][0] >> pts[i][1];
		pts[i][2] = i;
	}
	vi ans(n), sub(n);
	function<void(int, int)> calc = [&](int u, int p) {
		sub[u] = 1;
		for (auto x : v[u]) {
			if (x != p) {
				calc(x, u);
				sub[u] += sub[x];
			}
		}
	};
	calc(0, -1);
	function<void(int, int, int, int)> recur = [&](int u, int p, int l, int r) {
		int id = min_element(pts.begin() + l, pts.begin() + r) - pts.begin();
		swap(pts[l], pts[id]);
		ans[pts[l][2]] = u + 1;
		sort(pts.begin() + l + 1, pts.begin() + r, [&](const array<ll, 3> & a, const array<ll, 3> & b) -> bool {
			// ld ang1 = atan2(a[1] - pts[l][1], a[0] - pts[l][0]);
			// ld ang2 = atan2(b[1] - pts[l][1], b[0] - pts[l][0]);
			// return ang1 < ang2;
			return (a[0] - pts[l][0]) * (b[1] - pts[l][1]) -  (a[1] - pts[l][1]) * (b[0] - pts[l][0]) > 0;
		});
		int s = l + 1;
		for (auto x : v[u]) {
			if (x != p) {
				recur(x, u, s, s + sub[x]);
				s += sub[x];
			}
		}
	};
	recur(0, -1, 0, n);
	cout << ans << endl;
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
