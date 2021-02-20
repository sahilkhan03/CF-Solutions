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
	ll n, m, p;
	cin >> n >> m >> p;
	vl s(p); cin >> s;
	vector<string> v(n);
	cin >> v;
	vector<vector<pl>> cas(p);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != '.' and v[i][j] != '#') {
				cas[v[i][j] - '0' - 1].pb({i, j});
			}
		}
	}
	vl ans(p);
	vector<vi> vis(n, vi(m));
	queue<pl> q[p];
	auto check = [&]() {
		for (int i = 0; i < p; i++) {
			if (!q[i].empty()) return 1;
		}
		return 0;
	};
	for (int cur = 0; cur < p; cur++) {
		for (auto& x : cas[cur])
			q[cur].push({x.F, x.S}), vis[x.F][x.S]++, ans[cur]++;
	}
	auto ret = [&] (int i, int j) {
		return (vis[i][j] or v[i][j] != '.');
	};
	function<void(int)> bfs = [&](int cur) {
		queue<array<ll, 3>> qc;
		debug(cur);
		while (!q[cur].empty()) {
			auto tp = q[cur].front();
			q[cur].pop();
			qc.push({tp.F, tp.S, 0});
		}
		while (!qc.empty()) {
			auto [i, j, step] = qc.front();
			qc.pop();
			if (step == s[cur]) {
				q[cur].push({i, j});
				continue;
			}
			if (i + 1 < n and !ret(i + 1, j)) {
				ans[cur]++;
				vis[i + 1][j] = 1;
				qc.push({i + 1, j, step + 1});
			}
			if (i > 0 and !ret(i - 1, j)) {
				ans[cur]++;
				vis[i - 1][j] = 1;
				qc.push({i - 1, j, step + 1});
			}
			if (j > 0 and !ret(i , j - 1)) {
				ans[cur]++;
				vis[i][j - 1] = 1;
				qc.push({i, j - 1, step + 1});
			}
			if (j + 1 < m and !ret(i, j + 1)) {
				ans[cur]++;
				vis[i][j + 1] = 1;
				qc.push({i, j + 1, step + 1});
			}
		}
	};
	int cur = 0;
	while (check()) {
		bfs(cur);
		(cur += 1) %= p;
	}
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
