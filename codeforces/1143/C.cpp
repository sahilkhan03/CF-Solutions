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
	int n, r = 0; cin >> n;
	vector<vi> v(n);
	vi c(n), ans;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == -1) {
			r = i;
			continue;
		}
		c[i] = b;
		v[i].pb(a - 1);
		v[a - 1].pb(i);
	}
	function<void(int, int)> dfs = [&](int u, int p) {
		bool f = c[u];
		for (auto x : v[u]) {
			if (x != p) {
				dfs(x, u);
				debug(x, c[x]);
				f = (f and c[x]);
			}
		}
		debug(u, f);
		if (f) ans.pb(u + 1);
	};
	dfs(r, -1);
	sort(all(ans));
	if (ans.empty()) cout << -1 << endl;
	else cout << ans << endl;
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
