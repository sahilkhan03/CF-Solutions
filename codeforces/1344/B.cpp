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

bool vis[1001][1001];
void solve() {
	ll n, m; cin >> n >> m;
	vector<string> s(n);
	cin >> s;
	bool row = 0, col = 0;
	for (int i = 0; i < n; i++) {
		ll c = 0;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#' and (j - 1 < 0 or s[i][j - 1] == '.')) c++;
		}
		if (c > 1) {
			cout << -1 << endl;
			return;
		}
		if (!c) row = 1;
	}
	for (int j = 0; j < m; j++) {
		ll c = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][j] == '#' and (i - 1 < 0 or s[i - 1][j] == '.')) c++;
		}
		if (c > 1) {
			cout << -1 << endl;
			return;
		}
		if (!c) col = 1;
	}
	if (row ^ col) {
		cout << -1 << endl;
		return;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#' and !vis[i][j]) {
				queue<pl> q; q.push({i, j});
				while (!q.empty()) {
					auto tp = q.front(); q.pop();
					if (vis[tp.F][tp.S] or s[tp.F][tp.S] != '#') continue;
					vis[tp.F][tp.S] = 1;
					if (tp.F < n - 1) q.push({tp.F + 1, tp.S});
					if (tp.S < m - 1) q.push({tp.F, tp.S + 1});
					if (tp.F > 0) q.push({tp.F - 1, tp.S});
					if (tp.S > 0) q.push({tp.F, tp.S - 1 });
				}
				ans++;
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
