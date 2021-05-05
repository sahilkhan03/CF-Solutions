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
	ll n, m, w;
	cin >> n >> m >> w;
	vector<vl> v(n, vl(m)), d(n, vl(m, 1e18)), s(n, vl(m, 1e18));
	cin >> v;
	queue<array<ll, 3>> q;
	q.push({0, 0, 0});
	ll mns = 1e18, mnd = 1e18;
	vector<vi> vis(n, vi(m));
	while (!q.empty()) {
		auto [c, i, j] = q.front();
		q.pop();
		if (vis[i][j]) continue;
		vis[i][j] = 1;
		s[i][j] = c;
		if (v[i][j]) mns = min(mns, v[i][j] + c * w);
		if (i + 1 < n and v[i + 1][j] != -1 and !vis[i + 1][j])
			q.push({c + 1, i + 1, j});
		if (j + 1 < m and v[i][j + 1] != -1 and !vis[i][j + 1])
			q.push({c + 1, i, j + 1});
		if (i > 0 and v[i - 1][j] != -1 and !vis[i - 1][j])
			q.push({c + 1, i - 1, j});
		if (j > 0 and v[i][j - 1] != -1 and !vis[i][j - 1])
			q.push({c + 1, i, j - 1});
	}
	vis = vector<vi> (n, vi(m));
	q = queue<array<ll, 3>>();
	q.push({0, n - 1, m - 1});
	while (!q.empty()) {
		auto [c, i, j] = q.front();
		q.pop();
		if (vis[i][j]) continue;
		vis[i][j] = 1;
		d[i][j] = c;
		if (v[i][j]) mnd = min(mnd, v[i][j] + c * w);
		if (i + 1 < n and v[i + 1][j] != -1 and !vis[i + 1][j])
			q.push({c + 1, i + 1, j});
		if (j + 1 < m and v[i][j + 1] != -1 and !vis[i][j + 1])
			q.push({c + 1, i, j + 1});
		if (i > 0 and v[i - 1][j] != -1 and !vis[i - 1][j])
			q.push({c + 1, i - 1, j});
		if (j > 0 and v[i][j - 1] != -1 and !vis[i][j - 1])
			q.push({c + 1, i, j - 1});
	}
	ll ans = 1e18;
	if (s[n - 1][m - 1] != 1e18) ans = s[n - 1][m - 1] * w;
	ans = min(ans, mns + mnd);
	cout << (ans >= 1e18 ? -1 : ans) << endl;
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
