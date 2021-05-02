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
	int n, m;
	cin >> n >> m;
	map<pl, vector<pl>> v;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		while (x--) {
			int j; cin >> j;
			v[ {i, 0}].pb({j, 1});
			v[ {i, 1}].pb({j, 0});
		}
	}
	int s, cyc = 0;
	cin >> s;
	map<pl, int> vis;
	vector<pl> cur, ans;
	function<void(int, int)> dfs = [&](int u, int f) {
		debug(u, f, vis[ {u, f}]);
		if (!ans.empty() or vis[ {u, f}] == 2) return;
		if (vis[ {u, f}] == 1) {
			cyc = 1;
			return;
		}
		vis[ {u, f}] = 1;
		cur.pb({u, f});
		if (!f and v[ {u, f}].empty()) {
			ans = cur;
			return;
		}
		for (auto x : v[ {u, f}]) {
			dfs(x.F, x.S);
		}
		vis[ {u, f}] = 2;
		cur.pop_back();
	};
	dfs(s, 1);
	if (!ans.empty()) {
		cout << "Win" << endl;
		for (auto x : ans) cout << x.F << " ";
		cout << endl;
	}
	else if (cyc) cout << "Draw" << endl;
	else cout << "Lose" << endl;
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
