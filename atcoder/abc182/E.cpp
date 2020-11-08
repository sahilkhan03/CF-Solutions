#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

bool vis[4][1505][1505];
void solve() {
	ll h, w, n, m;
	cin >> h >> w >> n >> m;
	vector<vl> v(h, vl(w));
	vector<pl> bul(n), bloc(m);
	cin >> bul >> bloc;
	for (auto x : bloc) v[x.F - 1][x.S - 1] = -1;
	queue<array<ll, 3>> q;
	for (auto x : bul) {
		q.push({0, x.F - 1, x.S - 1});
		q.push({1, x.F - 1, x.S - 1});
		q.push({2, x.F - 1, x.S - 1});
		q.push({3, x.F - 1, x.S - 1});
	}
	ll ans = 0;
	while (!q.empty()) {
		auto [dir, i, j] = q.front(); q.pop();
		if (vis[dir][i][j] or v[i][j] == -1) continue;
		debug(dir, i, j);
		vis[dir][i][j] = 1;
		if (dir == 0) {
			if (j + 1 < w) q.push({dir, i, j + 1});
		}
		else if (dir == 1) {
			if (i) q.push({dir, i - 1, j});
		}
		else if (dir == 2) {
			if (j) q.push({dir, i, j - 1});
		}
		else {
			if (i + 1 < h) q.push({dir, i + 1, j});
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (vis[0][i][j] or vis[1][i][j] or vis[2][i][j] or vis[3][i][j]) ans++;
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
