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
	vl v(n + 1);
	v[0] = -1e18;
	for (int i = 0; i < n; i++) cin >> v[i + 1];
	vector<vector<vl>> dp(2, vector<vl>((n + 1) / 2 + 1, vl(n + 1, 1e18)));
	dp[0][0][0] = 0;
	vector<vl> h((n + 1) / 2 + 1, vl(n + 1));
	for (int i = 0; i <= (n + 1) / 2; i++) h[i][0] = -1e18;
	for (int i = 0; i <= n; i++) dp[0][0][i] = 0, h[0][i] = v[i];
	for (int k = 1; k <= (n + 1) / 2; k++) {
		for (int i = 1; i <= n; i++) {
			if (k > (i + 1) / 2) continue;
			dp[0][k][i] = dp[0][k][i - 1];
			h[k][i] = v[i];
			ll res = dp[1][k][i - 1] + max(0ll, v[i] - v[i - 1] + 1);
			if (res <= dp[0][k][i])
				dp[0][k][i] = res, h[k][i] = min(v[i], v[i - 1] - 1);
			dp[1][k][i] = dp[0][k - 1][i - 1] + max(0ll, h[k - 1][i - 1] - v[i] + 1);
			debug(k, i, dp[0][k][i], dp[1][k][i], h[k][i]);
		}
	}
	for (int i = 1; i <= (n + 1) / 2; i++)
		cout << min(dp[0][i][n], dp[1][i][n]) << " ";
	cout << endl;
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
