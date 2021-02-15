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

bool check(ll num) {
	while (num) {
		ll r = num % 10;
		if (r != 4 and r != 7) return 0;
		num /= 10;
	}
	return 1;
}

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	map<ll, set<ll>> inv;
	ll e = -1;
	for (int i = 0; i < n; i++) {
		inv[v[i]].insert(i);
		if (check(v[i])) e = v[i];
	}
	vl v1 = v;
	sort(all(v));
	debug(v);
	if (e == -1) {
		if (v1 != v) cout << -1 << endl;
		else cout << 0 << endl;
		return;
	}
	auto swp = [&](int i, int j) {
		inv[v1[i]].erase(inv[v1[i]].find(i));
		inv[v1[j]].erase(inv[v1[j]].find(j));
		inv[v1[i]].insert(j);
		inv[v1[j]].insert(i);
		swap(v1[i], v1[j]);
	};
	vector<pl> ans;
	for (int i = 0; i < n; i++) {
		if (v[i] == e) continue;
		if (i != *inv[e].begin()) {
			ans.pb({i + 1, *inv[e].begin() + 1});
			swp(i, *inv[e].begin());
			debug(ans.back());
		}
		if (i != *inv[v[i]].begin()) {
			ans.pb({i + 1, *inv[v[i]].begin() + 1});
			swp(i, *inv[v[i]].begin());
			debug(ans.back());
		}
		inv[v[i]].erase(inv[v[i]].find(i));
		debug(v1);
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
