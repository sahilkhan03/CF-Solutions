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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>


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
ll n, root = 0;
vector<vl> v;
vl c, sz, ans;
ordered_set s;

void subs(ll u, ll p) {
	for (auto x : v[u]) {
		if (x != p) subs(x, u), sz[u] += sz[x];
	}
}

void dfs(ll u, ll p) {
	if (sz[u] - 1 < c[u]) {
		cout << "NO" << endl;
		exit(0);
	}
	ans[u] = *s.find_by_order(c[u]);
	s.erase(s.find(ans[u]));
	for (auto x : v[u]) {
		if (x != p) dfs(x, u);
	}
}

void solve() {
	cin >> n;
	ans.resize(n);
	v.resize(n); c.resize(n); sz.resize(n, 1);
	for (int i = 0; i < n; i++) {
		s.insert(i + 1);
		ll p; cin >> p >> c[i];
		if (!p) root = i;
		else v[p - 1].pb(i), v[i].pb(p - 1);
	}
	subs(root, -1);
	dfs(root, -1);
	cout << "YES" << endl;
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
