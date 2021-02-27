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
ll n, m;
vl g, dp1, dp2;
ll calc(vl &dp, ll mask, bool f) {
	if (!mask) return 0;
	ll idx = (f ? (mask >> (m / 2)) : mask);
	if (dp[idx]) return dp[idx];
	ll ans = 1;
	for (int j = 0; j < 40; j++) {
		if (mask & (1ll << j)) {
			ans = max(ans, calc(dp, mask ^ (1ll << j), f));
			ans = max(ans, 1 + calc(dp, mask & g[j], f));
		}
	}
	return dp[idx] = ans;
}

void solve() {
	cin >> n >> m;
	vector<pair<ll, string>> v(n);
	map<string, ll> inv;
	ll c = 0, i = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].F; v[i].S = ".";
		if (v[i].F == 2) {
			cin >> v[i].S;
			if (inv.find(v[i].S) == inv.end()) inv[v[i].S] = c++;
		}
	}
	if (m == 1) {
		cout << 1 << endl;
		return;
	}
	g.resize(m);
	dp1.resize(1ll << (m / 2)), dp2.resize(1ll << (m - m / 2));
	for (int i = 0; i < m; i++) {
		g[i] = (1ll << m) - 1;
		g[i] ^= (1ll << i);
	}
	while (i < n) {
		ll j = i;
		while (j < n and v[j].F == 1) j++;
		vl tmp;
		while (j < n and v[j].F == 2) tmp.pb(inv[v[j++].S]);
		for (int i = 0; i < tmp.size(); i++) {
			for (int j = i + 1; j < tmp.size(); j++) {
				if (g[tmp[i]] & (1ll << tmp[j]))
					g[tmp[i]] ^= (1ll << tmp[j]);
				if (g[tmp[j]] & (1ll << tmp[i]))
					g[tmp[j]] ^= (1ll << tmp[i]);
			}
		}
		i = j;
	}
	calc(dp1, (1ll << (m / 2)) - 1, 0);
	calc(dp2, (1ll << m) - (1ll << (m / 2)), 1);
	ll ans = 0;
	for (ll mask = 0; mask < (1ll << (m / 2)); mask++) {
		ll j = 0;
		for (int i = m / 2; i < m; i++) {
			if ((g[i] & mask) == mask) j |= (1ll << i);
		}
		ans = max(ans, dp2[j >> (m / 2)] + dp1[mask]);
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
