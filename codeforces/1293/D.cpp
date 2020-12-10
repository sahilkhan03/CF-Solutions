#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pl pair<unsigned long long, unsigned long long>
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
vl v(6);
pl st;
vector<pl> pts;
ll cabs(ll a, ll b) {
	if (a > b) return a - b;
	return b - a;
}
void solve() {
	cin >> v >> st;
	ll t; cin >> t;
	pts = {{v[0], v[1]}};
	for (int i = 1; i < 100; i++) {
		pl cur = {v[2] * pts[i - 1].F + v[4], v[3] * pts[i - 1].S + v[5]};
		pts.pb(cur);
		if (log10(cur.F) + log10(v[2]) > 18 or log10(cur.S) + log10(v[3]) > 18) break;
	}
	ll ans = 0;
	for (int i = 0; i < pts.size(); i++) {
		ll init = cabs(pts[i].F , st.F) + cabs(pts[i].S , st.S);
		if (init > t) continue;
		ll j = i, cost = 0;
		while (j > 0 and pts[j].F + pts[j].S - pts[j - 1].S - pts[j - 1].F + cost + init <= t) cost += pts[j].F + pts[j].S - pts[j - 1].S - pts[j - 1].F, j--;
		// for (ll k = j; k <= i; k++) {
		// 	ll cur = 0, r = i + 1;
		// 	while (r < pts.size() and 2 * cost + init + cur + pts[r].F + pts[r].S - pts[r - 1].F - pts[r - 1].S <= t) cur += pts[r].F + pts[r].S - pts[r - 1].F - pts[r - 1].S, r++;
		// 	ans = max(ans, r - k);
		// 	if (k != i) cost -= pts[k + 1].F + pts[k + 1].S - pts[k].F - pts[k].S;
		// }
		ll cur = 0, r = i + 1;
		while (r < pts.size() and 2 * cost + init + cur + pts[r].F + pts[r].S - pts[r - 1].F - pts[r - 1].S <= t) cur += pts[r].F + pts[r].S - pts[r - 1].F - pts[r - 1].S, r++;
		ans = max(ans, r - j);
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
