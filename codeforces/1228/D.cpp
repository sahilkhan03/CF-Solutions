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
	if (!m) {
		cout << -1 << endl;
		return;
	}
	vector<set<ll>> v(n);
	vector<pl> e;
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		v[a].insert(b);
		v[b].insert(a);
		e.pb({a, b});
	}
	vl ans(n, 3), c(3);
	ans[e[0].F] = 1, ans[e[0].S] = 2, c[2] = n;
	for (int i = 0; i < n; i++) {
		if (v[e[0].F].find(i) == v[e[0].F].end()) ans[i] = 1, c[0]++, c[2]--;
		else if (v[e[0].S].find(i) == v[e[0].S].end()) ans[i] = 2, c[1]++, c[2]--;
	}
	if (!c[0] or !c[1] or !c[2]) {
		cout << -1 << endl;
		return;
	}
	for (pl x : e) {
		if (ans[x.F] == ans[x.S]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (n - v[i].size() != c[ans[i] - 1]) {
			debug(i);
			cout << -1 << endl;
			return;
		}
	}
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
