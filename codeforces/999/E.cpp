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
	int n, m, r;
	cin >> n >> m >> r;
	vector<vi> v(n);
	vi vis(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
	}
	queue<int> q;
	q.push(r - 1);
	while (!q.empty()) {
		auto tp = q.front(); q.pop();
		if (vis[tp]) continue;
		vis[tp] = 1;
		for (auto x : v[tp]) q.push(x);
	}
	int cnt = 0, ans = 0;
	vi nvis;
	function<void(int)> dfs = [&](int i) {
		if (nvis[i]) return;
		cnt++;
		nvis[i] = 1;
		for (auto x : v[i]) dfs(x);
	};
	function<void(int)> dfs2 = [&] (int i) {
		if (vis[i]) return;
		vis[i] = 1;
		for (auto x : v[i]) dfs2(x);
	};
	vector<pl> val;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		if (!vis[i]) {
			nvis = vis;
			dfs(i);
		}
		val.pb({cnt, i});
	}
	sort(all(val), greater<pl>());
	for (int i = 0; i < n; i++) {
		if (!vis[val[i].S]) {
			ans++;
			dfs2(val[i].S);
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
