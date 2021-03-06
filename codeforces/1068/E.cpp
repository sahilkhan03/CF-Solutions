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
ll n, sz, st, ed, k;
vector<vl> v;
pl mx = {0, 0};
vl dia, cur;
bool f = 0;
void dfs(ll u, ll p, ll lvl) {
	cur.pb(u);
	mx = max(mx, {lvl, u});
	if (f and u == ed) {
		dia = cur;
		return;
	}
	for (auto x : v[u]) {
		if (x != p) {
			dfs(x, u, lvl + 1);
		}
	}
	cur.pop_back();
}

bool check(ll u, ll p, ll lvl) {
	if (v[u].size() == 1) {
		return (lvl == sz);
	}
	for (auto x : v[u]) {
		if (x != p) {
			if (!check(x, u, lvl + 1)) return 0;
		}
	}
	if (u == dia[dia.size() / 2]) return (v[u].size() >= 3);
	return (v[u].size() > 3);
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	dfs(0, -1, 0);
	st = mx.S;
	mx = {0, 0};
	dfs(st, -1, 0);
	f = 1;
	ed = mx.S; sz = mx.F / 2;
	dfs(st, -1, 0);
	debug(dia);
	if (mx.F % 2 or sz != k) {
		cout << "No" << endl;
		return;
	}
	if (check(dia[dia.size() / 2], -1, 0)) cout << "Yes" << endl;
	else cout << "No" << endl;
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
