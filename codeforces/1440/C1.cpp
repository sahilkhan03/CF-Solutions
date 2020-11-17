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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<string> v(n);
	cin >> v;
	vector<vector<pl>> ans;
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 2; j++) {
			if (v[i][j] == '1') {
				ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i + 2, j + 1}});
				ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i + 2, j + 2}});
				ans.pb({{i + 1, j + 1}, {i + 2, j + 1}, {i + 2, j + 2}});
				debug(i, j, v[i][j]);
			}
		}
	}
	int i , j;
	i = n - 1;
	for ( j = 0; j <= m - 2; j++) {
		if (v[i][j] == '1') {
			ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i, j + 1}});
			ans.pb({{i + 1, j + 1}, {i + 1, j + 2}, {i, j + 2}});
			ans.pb({{i + 1, j + 1}, {i, j + 1}, {i, j + 2}});
		}
	}

	j = m - 1;
	for ( i = 0; i <= n - 2; i++) {
		if (v[i][j] == '1') {
			ans.pb({{i + 1, j + 1}, {i + 1, j}, {i + 2, j + 1}});
			ans.pb({{i + 1, j + 1}, {i + 1, j}, {i + 2, j}});
			ans.pb({{i + 1, j + 1}, {i + 2, j + 1}, {i + 2, j}});
		}
	}
	i = n - 1, j = m - 1;
	if (v[i][j] == '1') {
		ans.pb({{i + 1, j + 1}, {i + 1, j}, {i, j + 1}});
		ans.pb({{i + 1, j + 1}, {i + 1, j}, {i, j}});
		ans.pb({{i + 1, j + 1}, {i, j}, {i, j + 1}});
	}

	cout << ans.size() << endl;
	for (auto x : ans) {
		for (auto y : x) cout << y << " ";
		cout << endl;
	}

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
