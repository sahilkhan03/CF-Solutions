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
	ll n; cin >> n;
	vector<vl> v(n);
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		v[x - 1].pb(i);
		v[i].pb(x - 1);
	}
	vl s(n); cin >> s;
	ll ans = 0;
	function<void(ll, ll, ll, ll)> dfs = [&](ll u, ll p, ll lvl, ll sum) {
		if (ans == -1) return;
		ll c = 0;
		if (lvl & 1) {
			if (sum > s[u]) {
				ans = -1;
				return;
			}
			ans += s[u] - sum;
			c = s[u] - sum;
		}
		else {
			if (v[u].size() > 1) {
				c = 1e9;
				for (auto x : v[u]) {
					if (x != p) c = min(c, s[x] - sum);
				}
				if (c < 0) {
					ans = -1;
					return;
				}
			}
			ans += c;
		}
		for (auto x : v[u]) {
			if (x != p) {
				dfs(x, u, lvl + 1, sum + c);
			}
		}
	};
	dfs(0, -1, 1, 0);
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
