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
	int n, m, r;
	cin >> n >> m >> r;
	vector<vi> v(n);
	scc_graph g(n);
	vector<pl> ed;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		g.add_edge(a - 1, b - 1);
		ed.pb({a - 1, b - 1});
	}
	auto grp = g.scc();
	vi inv(n);
	for (int i = 0; i < grp.size(); i++) {
		for (auto x : grp[i]) inv[x] = i;
	}
	int ans = 0;
	vi cnt(grp.size());
	for (auto x : ed) {
		if (inv[x.S] != inv[x.F]) cnt[inv[x.S]]++;
	}
	debug(cnt);
	for (int i = 0; i < cnt.size(); i++) if (!cnt[i] and i != inv[r - 1]) ans++;
	cout << ans << endl;
}

int main()
{
	fast;
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
