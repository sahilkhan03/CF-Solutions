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
	vl v(n); cin >> v;
	vl ls(n + 1, -1);
	vl v1 = {v[0]};
	for (int i = 1; i < n; i++) {
		if (v[i] != v1.back()) v1.pb(v[i]);
	}
	v = v1, n = v1.size();
	vl dp(n);
	dp[0] = 1; ls[v[0]] = 0;
	ll ans = n;
	debug(v);
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + (i > 1 ? (v[i] != v[i - 2]) : 1);
		debug(i, '.' , ls[v[i]]);
		if (ls[v[i]] != -1)
			dp[i] = min(dp[i], dp[ls[v[i]] + 1] + (i - ls[v[i]] - 2));
		debug(i, dp[i]);
		ans = min(ans, dp[i] + n - i - 1);
		ls[v[i]] = i;
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
