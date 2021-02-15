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

struct cmp
{
	bool operator()(const vl& a, const vl &b) const {
		if (a[3] == b[3])
			return a[2] > b[2];
		return a[3] > b[3];
	}
};

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<pl> best(n + 1, { -1, -1});
	vector<vl> e(k, vl(4));
	cin >> e;
	sort(all(e));
	multiset<vl, cmp> s;
	ll j = 0;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() and (*s.begin())[1] < i) s.erase(s.begin());
		while (j < k and e[j][0] <= i) s.insert(e[j++]);
		if (s.empty()) continue;
		auto& tp = *s.begin();
		best[i] = {tp[2], tp[3]};
	}
	vector<vl> dp(n + 1, vl(m + 1));
	for (ll i = n; i ; i--) {
		for (ll j = 0; j <= m; j++) {
			if (best[i].F != -1)
				dp[i][j] = (best[i].F + 1 <= n ? dp[best[i].F + 1][j] : 0) + best[i].S;
			else
				dp[i][j] = (i + 1 <= n ? dp[i + 1][j] : 0);
			if (j > 0)
				dp[i][j] = min(dp[i][j], (i + 1 <= n ? dp[i + 1][j - 1] : 0));
			// debug(i, j, dp[i][j]);
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= m; i++) ans = min(ans, dp[1][i]);
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
