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
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<vi> v(n), cost(n, vi(k, 1e9)), tp(k);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		tp[x - 1].pb(i);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	vi vis;
	for (int i = 0; i < k; i++) {
		vis = vi(n);
		queue<pl> q;
		for (auto x : tp[i]) q.push({x, 0});
		while (!q.empty()) {
			auto [u, dis] = q.front();
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			cost[u][i] = min(cost[u][i], int(dis));
			for (auto x : v[u]) q.push({x, dis + 1});
		}
	}
	for (int i = 0; i < n; i++) {
		sort(all(cost[i]));
		cout << accumulate(cost[i].begin(), cost[i].begin() + s, 0ll) << " ";
	}
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
