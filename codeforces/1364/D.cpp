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

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vl> v(n);
	vector<pl> e;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e.pb({a, b});
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	if (m == n - 1) {
		vector<vl> ind(2, vl());
		queue<pl> q;
		q.push({0, 0});
		vl vis(n, 0);
		while (!q.empty()) {
			auto [i, d] = q.front();
			q.pop();
			if (vis[i]) continue;
			vis[i] = 1;
			ind[d].pb(i);
			for (auto x : v[i]) {
				q.push({x, d ^ 1});
			}
		}
		int id = (ind[0].size() < ind[1].size());
		cout << 1 << endl;
		for (int i = 0; i < (k + 1) / 2 ; i++)
			cout << ind[id][i] + 1 << " ";
		cout << endl;
		return;
	}
	bool f = 0;
	vl cyc, vis(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		if (f) return;
		cyc.pb(u + 1);
		// debug(u, vis[u]);
		if (vis[u]) {
			auto it = find(all(cyc), u + 1);
			cyc = vl(it + 1, cyc.end());
			f = 1;
			return;
		}
		vis[u] = 1;
		for (auto x : v[u]) {
			if (x != p) dfs(x, u);
		}
		if (!f) cyc.pop_back();
	};
	dfs(0, -1);
	debug(cyc.size(), cyc);
	set<ll> s(all(cyc));
	set<pl> cure;
	ll i = 0, j = cyc.size() - 1;
	for (int i = 0; i < cyc.size() - 1; i++) cure.insert({cyc[i], cyc[i + 1]}), cure.insert({cyc[i + 1], cyc[i]});
	cure.insert({cyc[0], cyc.back()});
	cure.insert({cyc.back(), cyc[0]});
	for (auto x : e) {
		if (s.find(x.F) != s.end() and s.find(x.S) != s.end() and cure.find(x) == cure.end()) {
			while (cyc[i] != x.F and cyc[i] != x.S) {
				i++;
				cure.erase({cyc[i], cyc[i - 1]});
				cure.erase({cyc[i - 1], cyc[i]});
				s.erase(cyc[i - 1]);
			}
			while (cyc[j] != x.F and cyc[j] != x.S) {
				j--;
				cure.erase({cyc[j], cyc[j + 1]});
				cure.erase({cyc[j + 1], cyc[j]});
				s.erase(cyc[j + 1]);
			}
			cure.insert({x.S, x.F});
			cure.insert(x);
		}
	}
	debug(i, j);
	cyc = vl(cyc.begin() + i, cyc.begin() + j + 1);
	if (cyc.size() <= k) {
		cout << 2 << endl;
		cout << cyc.size() << endl;
		cout << cyc << endl;
		return;
	}
	cout << 1 << endl;
	for (int i = 0; i < (k + 1) / 2 ; i++) cout << cyc[i * 2] << " ";
	cout << endl;
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
