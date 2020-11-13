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
inline ostream &operator<<(ostream &os, const set<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
	for (auto i : t) os << i.first << " : " << i.second << endl;
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
	for (pair<T1, T2> &t : v) is >> t.first >> t.second;
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

struct CentroidDecomposition {
	vector<set<int>> tree, ctree;
	vector<int> sz;
	int root = 0;

	CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
		int n = tree.size();
		sz = vector<int>(n);
		ctree = vector<set<int>>(n);
		build(0, -1);
	}

	void build(int u, int p) {
		int n = dfs(u, p);
		int centroid = dfs(u, p, n);
		if (p == -1) root = centroid;
		else ctree[centroid].insert(p), ctree[p].insert(centroid);
		while (!tree[centroid].empty()) {
			auto x = *tree[centroid].begin();
			tree[x].erase(centroid);
			tree[centroid].erase(x);
			build(x, centroid);
		}
	}

	int dfs(int u, int p) {
		sz[u] = 1;
		for (auto x : tree[u])
			if (x != p) sz[u] += dfs(x, u);
		return sz[u];
	}

	int dfs(int u, int p, int n) {
		for (auto x : tree[u])
			if (x != p and sz[x] > n / 2) return dfs(x, u, n);
		return u;
	}
};


void solve() {
	ll n; cin >> n;
	vector<set<int>> v(n);
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		v[a - 1].insert(b - 1);
		v[b - 1].insert(a - 1);
	}
	CentroidDecomposition cd(v);
	queue<array<ll, 3>> q;
	q.push({cd.root, -1, 0});
	vector<char> ans(n);
	while (!q.empty()) {
		auto [node, p, lvl] = q.front();
		q.pop();
		ans[node] = char(lvl + 'A');
		for (auto x : cd.ctree[node]) {
			if (x != p) {
				q.push({x, node, lvl + 1});
			}
		}
	}
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
