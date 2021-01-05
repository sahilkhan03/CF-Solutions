#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
	vector<vl> v(n), ans(n, vl(2, 1e18));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].pb(b);
	}
	vl dis(n), vis(n);
	queue<pl> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [i, d] = q.front();
		q.pop();
		if (vis[i]) continue;
		vis[i] = 1, dis[i] = d;
		for (auto x : v[i]) q.push({x, d + 1});
	}
	vector<vl> vis1(n, vl(2, 0));
	function<ll(int, int)> dfs = [&](int u, int f) {
		if (vis1[u][f]) return ans[u][f];
		vis1[u][f] = 1;
		ans[u][f] = min(ans[u][f], dis[u]);
		for (auto x : v[u]) {
			if (dis[u] < dis[x]) ans[u][f] = min(ans[u][f], dfs(x, f));
			else if (!f) ans[u][f] = min(ans[u][f], dfs(x, 1));
		}
		return ans[u][f];
	};
	for (int i = 0; i < n; i++) dfs(i, 0);
	for (int i = 0; i < n; i++) cout << min(ans[i][0], ans[i][1]) << " ";
	cout << endl;
}

int main()
{
	fast;
	ll T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
