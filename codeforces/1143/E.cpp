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
	int n, m, q;
	cin >> n >> m >> q;
	vi v(n), pre(n + 1);
	cin >> v;
	pre[v[0]] = v[n - 1];
	for (int i = 1; i < n; i++) pre[v[i]] = v[i - 1];
	vi ls(n + 1, -1e9), lf(m, -1e9);
	vector<vi> lca(20, vi(m, -1e9));
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		lca[0][i] = ls[pre[x]];
		for (int j = 1; j < 20 and lca[j - 1][i] >= 0; j++) {
			lca[j][i] = lca[j - 1][lca[j - 1][i]];
		}
		ls[x] = i;
		if (i > 0) lf[i] = lf[i - 1];
		int cur = n - 1, pos = i;
		for (int st = 20; st >= 0; st--) {
			while (cur - (1 << st) >= 0 and pos >= 0) {
				pos = lca[st][pos];
				cur -= (1 << st);
			}
		}
		lf[i] = max(lf[i], pos);
	}
	string ans;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (lf[r - 1] >= l - 1) ans += '1';
		else ans += '0';
	}
	cout << ans << endl;
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
