/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

ll ans = 0;
multiset<ll> s;
vector<vl> g, v;
pl dfs(ll u, ll p) {
	s.insert(v[u][0]);
	ll a = (!v[u][1] and v[u][2]), b = (v[u][1] and !v[u][2]);
	for (auto x : g[u]) {
		if (x != p) {
			pl t = dfs(x, u);
			a += t.F, b += t.S;
		}
	}
	ll x = min(a, b);
	ans += *s.begin() * x;
	a -= x, b -= x;
	s.erase(s.find(v[u][0]));
	return {a, b};
}

void solve() {
	ll n; cin >> n;
	g.resize(n); v.resize(n, vl(3));
	ll c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		c1 += v[i][1], c2 += v[i][2];
	}
	for (int i = 0; i < n - 1; i++) {
		ll a, b; cin >> a >> b;
		g[a - 1].pb(b - 1);
		g[b - 1].pb(a - 1);
	}
	if (c1 != c2) {
		cout << -1 << endl;
		return;
	}
	dfs(0, -1);
	cout << ans * 2 << endl;
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
