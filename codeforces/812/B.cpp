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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	cin >> s;
	vector<pl> v(n, {m + 1, 0});
	for (int i = 0; i < n; i++) {
		for (ll j = 0; j < s[i].size(); j++) {
			if (s[n - i - 1][j] == '1') v[i].F = min(v[i].F, j), v[i].S = max(v[i].S, j);
		}
	}
	while (!v.empty() and !v.back().S) v.pop_back();
	ll ans = 1e18;
	if (v.empty()) {
		cout << 0 << endl;
		return;
	}
	function<void(ll, ll, ll)> calc = [&](ll cur, ll lvl, ll pre) {
		debug(cur, lvl, pre);
		if (lvl == v.size() - 1) {
			if (!pre) cur += v[lvl].S;
			else cur += m + 1 - v[lvl].F;
			debug(cur);
			ans = min(ans, cur);
			return;
		}
		if (!pre) calc(cur + 2 * v[lvl].S + 1, lvl + 1, 0), calc(cur + m + 2, lvl + 1, 1);
		else calc(cur + m + 2, lvl + 1, 0), calc(cur + 2 * (m + 1 - v[lvl].F) + 1, lvl + 1, 1);
	};
	calc(0, 0, 0);
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
