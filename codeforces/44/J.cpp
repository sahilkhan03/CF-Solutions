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
	vector<string> v(n);
	cin >> v;
	vector<vi> vis(n, vi(m));
	function<char(int, int, int)> get = [&](int i, int j, int k) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (k == 0) {
				if (i > 0 and (c == v[i - 1][j] or c == v[i - 1][j + 1] or c == v[i - 1][j + 2])) continue;
				if (j > 0 and c == v[i][j - 1]) continue;
				if (j + 3 < m and c == v[i][j + 3]) continue;
			}
			else {
				if (j > 0 and (c == v[i][j - 1] or c == v[i + 1][j - 1] or c == v[i + 2][j - 1])) continue;
				if (i > 0 and c == v[i - 1][j]) continue;
				if (i + 3 < n and c == v[i + 3][j]) continue;
				if (j + 1 < m and (c == v[i][j + 1] or c == v[i + 1][j + 1] or c == v[i + 2][j + 1])) continue;
			}
			return c;
		}
		return 'z';
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.' or vis[i][j]) continue;
			vis[i][j] = 1;
			if (v[i][j] == 'w' and j + 2 < m and v[i][j + 1] == 'b' and v[i][j + 2] == 'w' and !vis[i][j + 1] and !vis[i][j + 2]) {
				v[i][j] = v[i][j + 1] = v[i][j + 2] = get(i, j, 0);
				vis[i][j + 1] = vis[i][j + 2] = 1;
			}
			else if (v[i][j] == 'w' and i + 2 < n and v[i + 1][j] == 'b' and v[i + 2][j] == 'w' and !vis[i + 1][j] and !vis[i + 2][j]) {
				v[i][j] = v[i + 1][j] = v[i + 2][j] = get(i, j, 1);
				vis[i + 1][j] = vis[i + 2][j] = 1;
			}
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	for (auto& x : v) cout << x << endl;
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
