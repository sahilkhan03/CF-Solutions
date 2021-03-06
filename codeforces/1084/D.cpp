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
	vl w(n); cin >> w;
	ll ans = *max_element(all(w));
	vector<vector<pl>> v(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		v[a].pb({b, c});
		v[b].pb({a, c});
		ans = max(ans, w[a] + w[b] - c);
	}
	vl dp(n);
	function<void(ll, ll)> dfs = [&](ll u, ll p) {
		pl mx = {0, 0};
		dp[u] = w[u];
		for (auto x : v[u]) {
			if (x.F != p) {
				dfs(x.F, u);
				mx = max({mx, {mx.F, dp[x.F] - x.S}, {dp[x.F] - x.S, mx.F}});
				dp[u] = max(dp[u], dp[x.F] - x.S + w[u]);
			}
		}
		debug(u, mx);
		ans = max(ans, w[u] + mx.F + mx.S);
	};
	dfs(0, -1);
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
