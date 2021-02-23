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
	vector<vl> edge(m, vl(3));
	cin >> edge;
	vector<vl> v;
	vi vis;
	function<bool(ll)> dfs = [&](ll i) {
		if (vis[i] == 2) return 0;
		if (vis[i] == 1) return 1;
		vis[i] = 1;
		for (auto x : v[i]) {
			if (dfs(x)) return 1;
		}
		vis[i] = 2;
		return 0;
	};
	auto calc = [&](ll c) {
		v = vector<vl> (n);
		vis = vi(n);
		for (int i = 0; i < m; i++) {
			if (edge[i][2] > c) v[edge[i][0] - 1].pb(edge[i][1] - 1);
		}
		for (int i = 0; i < n; i++) {
			if (dfs(i)) return 0;
		}
		return 1;
	};
	ll ans = 1e9;
	for (ll st = 1e9; st; st /= 2) {
		while (ans - st >= 0 and calc(ans - st)) ans -= st;
	}
	v = vector<vl> (n);
	vis = vi(n);
	for (int i = 0; i < m; i++) {
		if (edge[i][2] > ans) v[edge[i][0] - 1].pb(edge[i][1] - 1);
	}
	vi tps;
	function<void(ll)> dfs2 = [&](ll i) {
		if (vis[i]) return;
		vis[i] = 1;
		for (auto x : v[i]) {
			dfs2(x);
		}
		tps.pb(i);
	};
	for (int i = 0; i < n; i++) {
		dfs2(i);
	}
	debug(tps);
	vi inv(n);
	for (int i = n - 1; i >= 0; i--) {
		inv[tps[i]] = i;
	}
	vl vans;
	for (int i = 0; i < m; i++) {
		if (edge[i][2] <= ans and inv[edge[i][0] - 1] < inv[edge[i][1] - 1])
			vans.pb(i + 1);
	}
	cout << ans << " " << vans.size() << endl;
	cout << vans << endl;
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
