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

ll n, m, a, b;
vector<set<ll>> v;
vector<bool> vis;
vl path, par;
set<ll> s;
void dfs(ll u) {
	if (u != a)
		par[u] = path[0];
	if (u == b) {
		s.insert(path[0]);
		return;
	}
	if (vis[u]) return;
	vis[u] = 1;
	for (auto x : v[u]) {
		if (!vis[x]) {
			path.pb(x);
			dfs(x);
			path.pop_back();
		}
	}
}

void solve() {
	cin >> n >> m >> a >> b;
	v = vector<set<ll>>(n);
	vis = vector<bool>(n);
	par = vl(n, -1);
	path.clear(); s.clear();
	a--, b--;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		v[x - 1].insert(y - 1);
		v[y - 1].insert(x - 1);
	}
	dfs(a);
	ll ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		if (i == a or i == b) continue;
		if (par[i] == -1) cb++;
		else if (s.find(par[i]) == s.end()) ca++;
	}
	cout << ca * cb << endl;
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
