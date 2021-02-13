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
	ll n; cin >> n;
	pl t; cin >> t;
	ll st = (t.F - 1) * n  + t.S - 1;
	cin >> t;
	ll ed =  (t.F - 1) * n  + t.S - 1;
	vector<string> s(n);
	cin >> s;
	dsu d(n * n);
	vector<vi> vis(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] and s[i][j] == '0') {
				queue<pl> q;
				q.push({i, j});
				while (!q.empty()) {
					auto [l, r] = q.front();
					q.pop();
					if (vis[l][r] or s[l][r] == '1') continue;
					vis[l][r] = 1;
					d.merge(i * n + j, l * n + r);
					if (l + 1 < n) q.push({l + 1, r});
					if (l > 0) q.push({l - 1, r});
					if (r + 1 < n) q.push({l, r + 1});
					if (r > 0) q.push({l, r - 1});
				}
			}
		}
	}
	ll ans = 1e18;
	if (d.same(st, ed)) {
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < n * n; j++) {
			if (d.same(i, st) and d.same(ed, j)) {
				ll x1 = i / n, x2 = j / n, y1 = i % n, y2 = j % n;
				debug(x1, y1, x2, y2);
				ans = min(ans, abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1));
			}
		}
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
