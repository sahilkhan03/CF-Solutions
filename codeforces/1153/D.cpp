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
	vector<vi> v(n);
	vi op(n); cin >> op;
	for (int i = 0; i < n - 1; i++) {
		int x; cin >> x;
		v[i + 1].pb(x - 1);
		v[x - 1].pb(i + 1);
	}
	int c = 0;
	for (int i = 1; i < n; i++) if (v[i].size() == 1) c++;
	vi rem, cnt(n, 1);
	for (int i = c; i > 0; i--) rem.pb(i);
	function<void(int, int)> dfs = [&](int u, int p) {
		int mn = n, sum = 0;
		if (v[u].size() == 1 and u) return;
		for (auto x : v[u]) {
			if (x != p) {
				dfs(x, u);
				mn = min(mn, cnt[x]);
				sum += cnt[x];
			}
		}
		if (op[u]) {
			for (int i = 0; i < sum - mn; i++) rem.pop_back();
			cnt[u] = mn;
		} else cnt[u] = sum;
		// debug(cnt[u]);
	};
	dfs(0, -1);
	cout << rem.back() << endl;
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
