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

bitset<1001> vis;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<map<ll, ll>> v(n);
	vector<vl> e;
	for (int i = 0; i < m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		v[a][b] = w;
		v[b][a] = w;
		e.pb({a, b, w});
	}
	vector<vl> dis(n, vl(n, mod));
	for (int i = 0; i < n; i++) {
		vis.reset();
		priority_queue<pl, vector<pl>, greater<pl>> pq;
		pq.push({0, i});
		while (!pq.empty()) {
			pl tp = pq.top(); pq.pop();
			if (vis[tp.S]) continue;
			vis[tp.S] = 1;
			dis[i][tp.S] = tp.F;
			for (auto x : v[tp.S]) {
				if (dis[i][x.F] > tp.F + x.S and !vis[x.F]) {
					dis[i][x.F] = tp.F + x.S;
					pq.push({tp.F + x.S, x.F});
				}
			}
		}
	}
	vector<pl> rte;
	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		rte.pb({a, b});
		ans += dis[a][b];
	}
	for (vl& x : e) {
		ll cur = 0;
		debug(x);
		for (pl& r : rte) {
			cur += min(dis[r.F][r.S] , min(dis[x[0]][r.F] + dis[x[1]][r.S], dis[x[1]][r.F] + dis[x[0]][r.S]));
		}
		ans = min(ans, cur);
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
