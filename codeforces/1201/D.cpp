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
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	map<ll, ll> lf, rg;
	lf[1] = 1, rg[1] = 1;
	for (int i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		if (lf.find(a) == lf.end()) {
			lf[a] = rg[a] = b;
			continue;
		}
		lf[a] = min(lf[a], b);
		rg[a] = max(rg[a], b);
	}
	vl col(q);
	cin >> col;
	sort(all(col));
	map<ll, ll> dp, tmp;
	dp[rg[1]] = lf.rbegin()->F - 1 + rg[1] - 1;
	lf.erase(1);
	for (auto& x : lf) {
		tmp.clear();
		int idx = x.F;
		// debug(idx, vector<pl>(all(dp)));
		tmp[lf[idx]] = tmp[rg[idx]] = 1e18;
		// debug(idx, lf[idx], rg[idx]);
		for (auto& y : dp) {
			auto it = upper_bound(all(col), y.F);
			if (it != col.end()) {
				// debug('f', *it);
				tmp[lf[idx]] = min(tmp[lf[idx]], y.S + abs(*it - y.F) + abs(*it - rg[idx]) + abs(rg[idx] - lf[idx]));
				tmp[rg[idx]] = min(tmp[rg[idx]], y.S + abs(*it - y.F) + abs(*it - lf[idx]) + abs(rg[idx] - lf[idx]));
			}
			if (it != col.begin()) {
				it = prev(it);
				// debug('s', *it);
				tmp[lf[idx]] = min(tmp[lf[idx]], y.S + abs(*it - y.F) + abs(*it - rg[idx]) + abs(rg[idx] - lf[idx]));
				tmp[rg[idx]] = min(tmp[rg[idx]], y.S + abs(*it - y.F) + abs(*it - lf[idx]) + abs(rg[idx] - lf[idx]));
			}
		}
		dp = tmp;
	}
	ll ans = 1e18;
	for (auto x : dp) ans = min(ans, x.S);
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
