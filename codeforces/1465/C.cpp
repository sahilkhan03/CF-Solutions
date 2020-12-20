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
map<ll, pl> row, col;
map<pl, ll> vis;
ll n, m, ans = 0;

void dfs(pl cur, pl p) {
	debug(cur, vis[cur]);
	if (vis[cur] == 2) return;
	else if (vis[cur] == 1) {
		ans++;
		debug(cur);
		vis[cur] = 2;
		return;
	}
	vis[cur] = 1;
	if (cur.F == cur.S) {
		ans--;
		return;
	}
	debug("-- ", cur, vis[cur]);
	if (row.find(cur.S) == row.end()) {
		row[cur.S] = cur;
		row.erase(row.find(cur.F));
	}
	else if (p != row[cur.S]) {
		dfs(row[cur.S], cur);
		row[cur.S] = cur;
		row.erase(row.find(cur.F));
	}
	else if (col.find(cur.F) == col.end()) {
		col[cur.F] = cur;
		col.erase(col.find(cur.S));
	}
	else {
		dfs(col[cur.F], cur);
		col[cur.F] = cur;
		col.erase(col.find(cur.S));
	}
	vis[cur] = 2;
}

void solve() {
	cin >> n >> m;
	ans = m;
	vis.clear();
	row.clear(); col.clear();
	vector<pl> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
		row[v[i].F] = v[i];
		col[v[i].S] = v[i];
	}
	for (int i = 0; i < m; i++) {
		if (!vis[v[i]]) {
			dfs(v[i], { -1, -1});
		}
	}
	cout << ans << endl;
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
