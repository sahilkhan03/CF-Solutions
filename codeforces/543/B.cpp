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
	int n, m;
	cin >> n >> m;
	vector<vi> v(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	vector<vi> dis(n, vi(n));
	for (int i = 0; i < n; i++) {
		queue<pl> q;
		vector<bool> vis(n);
		q.push({i, 0});
		while (!q.empty()) {
			auto [j, d] = q.front();
			q.pop();
			if (vis[j]) continue;
			vis[j] = 1;
			dis[i][j] = d;
			for (auto x : v[j]) {
				q.push({x, d + 1});
			}
		}
	}
	vi a(3), b(3);
	cin >> a >> b;
	a[0]--, b[0]--, a[1]--, b[1]--;
	if (dis[a[0]][a[1]] > a[2] or dis[b[0]][b[1]] > b[2]) {
		cout << -1 << endl;
		return;
	}
	int ans = max(0, m - dis[a[0]][a[1]] - dis[b[0]][b[1]]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dis[a[0]][i] + dis[i][j] + dis[a[1]][j] <= a[2] and dis[b[0]][i] + dis[i][j] + dis[b[1]][j] <= b[2]) {
				ans = max(ans, m - dis[a[0]][i] - dis[b[0]][i] - dis[a[1]][j] - dis[b[1]][j] - dis[i][j]);
			}
			if (dis[a[0]][j] + dis[i][j] + dis[a[1]][i] <= a[2] and dis[b[0]][i] + dis[i][j] + dis[b[1]][j] <= b[2]) {
				ans = max(ans, m - dis[a[0]][j] - dis[b[0]][i] - dis[a[1]][i] - dis[b[1]][j] - dis[i][j]);
			}
			if (dis[a[0]][i] + dis[i][j] + dis[a[1]][j] <= a[2] and dis[b[0]][j] + dis[i][j] + dis[b[1]][i] <= b[2]) {
				ans = max(ans, m - dis[a[0]][i] - dis[b[0]][j] - dis[a[1]][j] - dis[b[1]][i] - dis[i][j]);
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
