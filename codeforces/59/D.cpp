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
	int n; cin >> n;
	vi val(3 * n), vis(3 * n + 1);
	cin >> val;
	vi loc(3 * n + 1);
	vector<vl> v(n, vl(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
			loc[v[i][j]] = i;
		}
	}
	int k, j = 0; cin >> k;
	vi ans, up;
	for (int i = 0; i < loc[k]; i++) {
		for (auto x : v[i]) vis[x] = 1, up.pb(x);
	}
	while (vis[val[j]]) j++;
	debug(k, val[j]);
	if (k != val[j]) {
		for (int i = 1; i <= 3 * n; i++)
			if (i != k) cout << i << " ";
		return;
	}
	for (auto x : v[loc[k]]) if (x != k) ans.pb(x);
	for (int i = loc[k] + 1; i < n; i++) {
		for (auto x : v[i]) ans.pb(x);
	}
	sort(ans.begin(), ans.begin() + 2);
	sort(ans.begin() + 2, ans.end());
	sort(all(up));
	debug(up, ans);
	j = 0;
	for (auto x : ans) {
		while (j < up.size() and up[j] < x) cout << up[j++] << " ";
		cout << x << " ";
	}
	cout << vl(up.begin() + j, up.end()) << endl;
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
