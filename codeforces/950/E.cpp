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


template <class E> struct csr {
	std::vector<int> start;
	std::vector<E> elist;
	csr(int n, const std::vector<std::pair<int, E>>& edges)
		: start(n + 1), elist(edges.size()) {
		for (auto e : edges) {
			start[e.first + 1]++;
		}
		for (int i = 1; i <= n; i++) {
			start[i] += start[i - 1];
		}
		auto counter = start;
		for (auto e : edges) {
			elist[counter[e.first]++] = e.second;
		}
	}
};
struct scc_graph {
public:
	scc_graph(int n) : _n(n) {}

	int num_vertices() { return _n; }

	void add_edge(int from, int to) { edges.push_back({from, {to}}); }

	std::pair<int, std::vector<int>> scc_ids() {
		auto g = csr<edge>(_n, edges);
		int now_ord = 0, group_num = 0;
		std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
		visited.reserve(_n);
		auto dfs = [&](auto self, int v) -> void {
			low[v] = ord[v] = now_ord++;
			visited.push_back(v);
			for (int i = g.start[v]; i < g.start[v + 1]; i++) {
				auto to = g.elist[i].to;
				if (ord[to] == -1) {
					self(self, to);
					low[v] = std::min(low[v], low[to]);
				} else {
					low[v] = std::min(low[v], ord[to]);
				}
			}
			if (low[v] == ord[v]) {
				while (true) {
					int u = visited.back();
					visited.pop_back();
					ord[u] = _n;
					ids[u] = group_num;
					if (u == v) break;
				}
				group_num++;
			}
		};
		for (int i = 0; i < _n; i++) {
			if (ord[i] == -1) dfs(dfs, i);
		}
		for (auto& x : ids) {
			x = group_num - 1 - x;
		}
		return {group_num, ids};
	}

	std::vector<std::vector<int>> scc() {
		auto ids = scc_ids();
		int group_num = ids.first;
		std::vector<int> counts(group_num);
		for (auto x : ids.second) counts[x]++;
		std::vector<std::vector<int>> groups(ids.first);
		for (int i = 0; i < group_num; i++) {
			groups[i].reserve(counts[i]);
		}
		for (int i = 0; i < _n; i++) {
			groups[ids.second[i]].push_back(i);
		}
		return groups;
	}

private:
	int _n;
	struct edge {
		int to;
	};
	std::vector<std::pair<int, edge>> edges;
};

void solve() {
	int n, m, h;
	cin >> n >> m >> h;
	vi u(n); cin >> u;
	scc_graph g(n);
	map<pl, bool> used;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if ((u[a] + 1) % h == u[b] and !used[ {a, b}]) {
			g.add_edge(a, b), used[ {a, b}] = 1;
		}
		if ((u[b] + 1) % h == u[a] and !used[ {b, a}]) {
			g.add_edge(b, a), used[ {b, a}] = 1;
		}
	}
	auto v = g.scc();
	vector<set<int>> vv(v.size());
	vi ids(n);
	for (int i = 0; i < v.size(); i++) {
		for (auto x : v[i]) ids[x] = i;
	}
	for (auto [x, b] : used) {
		if (ids[x.F] != ids[x.S])
			vv[ids[x.F]].insert(ids[x.S]);
	}
	int mn = -1;
	for (int i = 0; i < v.size(); i++) {
		debug(i, vi(all(vv[i])));
		if (vv[i].empty()) {
			if (mn == -1 or v[mn].size() > v[i].size())
				mn = i;
		}
	}
	cout << v[mn].size() << endl;
	for (auto x : v[mn]) cout << x + 1 << " ";
	cout << endl;
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
