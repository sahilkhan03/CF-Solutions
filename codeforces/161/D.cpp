/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

int ans = 0, n, k;
vector<vi> v, dp, dp2;

void dfs(ll u, ll p) {
	dp[u][0] = 1;
	for (auto x : v[u]) {
		if (x != p) {
			dfs(x, u); dp[u][1]++;
			for (int j = 2; j <= k; j++) dp[u][j] += dp[x][j - 1];
		}
	}
}

void dfs2(ll u, ll p) {
	if (!u) dp2[u] = dp[u];
	else {
		dp2[u][0] = 1; dp2[u][1] = v[u].size();
		for (int i = 2; i <= k; i++) {
			dp2[u][i] = dp[u][i] + dp2[p][i - 1] - (i - 2 >= 0 ? dp[u][i - 2] : 0);
		}
	}
	for (auto x : v[u]) {
		if (x != p) {
			dfs2(x, u);
		}
	}
}

void solve() {
	cin >> n >> k;
	v = vector<vi>(n);
	dp = dp2 = vector<vi> (n, vi(k + 1));
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(0, -1);
	dfs2(0, -1);
	ll ans = 0;
	debug(dp);
	debug(dp2);
	for (int i = 0; i < n; i++) ans += dp2[i][k];
	cout << ans / 2 << endl;
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
