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

struct LCA {
	vector<vector<pl>> v, lca;
	vector<int> dep;
	int n = 0;

	LCA(const vector<vector<pl>>& adj, int root = 0) {
		n = adj.size();
		dep.resize(n);
		lca.resize(n, vector<pl>(int(log2(n) + 2), { -1, 0}));
		v = adj;
		dfs(root, -1, 0, 0);
	}

	void dfs(int u, int p, int w, int lvl) {
		lca[u][0] = {p, w};
		dep[u] = lvl;
		for (int i = 1; (1 << i) <= lvl; i++) {
			lca[u][i] = {lca[lca[u][i - 1].F][i - 1].F, max(lca[lca[u][i - 1].F][i - 1].S, lca[u][i - 1].S)};
		}
		for (auto& x : v[u]) {
			if (x.F != p) dfs(x.F, u, x.S, lvl + 1);
		}
	}

	ll calc(int a, int b) {
		ll ans = 0;
		if (dep[a] > dep[b]) swap(a, b);
		while (dep[b] > dep[a]) {
			ans = max(ans, lca[b][(int)log2(dep[b] - dep[a])].S);
			b = lca[b][(int)log2(dep[b] - dep[a])].F;
		}
		if (a == b) return ans;
		while (true) {
			int jump = 0;
			while ((1 << jump) <= dep[a] and lca[a][jump].F != lca[b][jump].F) jump++;
			if (!jump) break;
			ans = max({ans, lca[a][jump - 1].S, lca[b][jump - 1].S});
			a = lca[a][jump - 1].F;
			b = lca[b][jump - 1].F;
		}
		return max({ans, lca[a][0].S, lca[b][0].S});
	}
};


struct dsu {
public:
	dsu() : _n(0) {}
	dsu(int n) : _n(n), parent_or_size(n, -1) {}

	int merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		int x = leader(a), y = leader(b);
		if (x == y) return x;
		if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
		parent_or_size[x] += parent_or_size[y];
		parent_or_size[y] = x;
		return x;
	}

	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return leader(a) == leader(b);
	}

	int leader(int a) {
		assert(0 <= a && a < _n);
		if (parent_or_size[a] < 0) return a;
		return parent_or_size[a] = leader(parent_or_size[a]);
	}

	int size(int a) {
		assert(0 <= a && a < _n);
		return -parent_or_size[leader(a)];
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> leader_buf(_n), group_size(_n);
		for (int i = 0; i < _n; i++) {
			leader_buf[i] = leader(i);
			group_size[leader_buf[i]]++;
		}
		std::vector<std::vector<int>> result(_n);
		for (int i = 0; i < _n; i++) {
			result[i].reserve(group_size[i]);
		}
		for (int i = 0; i < _n; i++) {
			result[leader_buf[i]].push_back(i);
		}
		result.erase(
		    std::remove_if(result.begin(), result.end(),
		[&](const std::vector<int>& v) { return v.empty(); }),
		result.end());
		return result;
	}

private:
	int _n;
	std::vector<int> parent_or_size;
};

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<pl>> v(n), v1(n);
	vector<array<ll, 4>> edge;
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a - 1].pb({b - 1, c});
		v[b - 1].pb({a - 1, c});
		edge.pb({c, a - 1, b - 1, i});
	}
	sort(all(edge));
	dsu d(n);
	ll cost = 0;
	for (auto& x : edge) {
		if (d.same(x[1], x[2])) continue;
		d.merge(x[1], x[2]);
		v1[x[1]].pb({x[2], x[0]});
		v1[x[2]].pb({x[1], x[0]});
		cost += x[0];
	}
	sort(all(edge), [](const array<ll, 4>& a, const array<ll, 4>&b) -> bool{
		return a[3] < b[3];
	});
	LCA lca(v1);
	for (int i = 0; i < m; i++) {
		cout << cost + edge[i][0] - lca.calc(edge[i][1], edge[i][2]) << endl;
	}
}

int main()
{
	fast;
	ll T = 1;
	solve();
	return 0;
}
