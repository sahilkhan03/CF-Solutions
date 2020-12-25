#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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

int m, d;

ll calc(string& s) {
	int n = s.size();
	vector<vector<vl>> dp(2, vector<vl>(n, vl(m, 0)));
	for (int i = 1; i < s[0] - '0'; i++) if (i != d) dp[0][0][i % m]++;
	if (s[0] - '0' != d) dp[1][0][(s[0] - '0') % m]++;
	for (int i = 0; i < n - 1; i++) {
		if (i & 1) {
			for (int md = 0; md < m; md++) {
				for (int x = 0; x < 10; x++) {
					if (x == d) continue;
					(dp[0][i + 1][(md * 10 + x) % m] += dp[0][i][md]) %= mod;
					if (x < s[i + 1] - '0')
						(dp[0][i + 1][(md * 10 + x) % m] += dp[1][i][md]) %= mod;
				}
				if (s[i + 1] - '0' != d)
					(dp[1][i + 1][(md * 10 + s[i + 1] - '0') % m] += dp[1][i][md]) %= mod;
			}
		}
		else {
			for (int md = 0; md < m; md++) {
				(dp[0][i + 1][(md * 10 + d) % m] += dp[0][i][md]) %= mod;
				if (d < s[i + 1] - '0')
					(dp[0][i + 1][(md * 10 + d) % m] += dp[1][i][md]) %= mod;
				else if (d == s[i + 1] - '0')
					(dp[1][i + 1][(md * 10 + d) % m] += dp[1][i][md]) %= mod;
			}
		}
	}
	debug(dp);
	return (dp[0][n - 1][0] + dp[1][n - 1][0]) % mod;
}

bool check(string& a) {
	ll md = 0;
	for (int i = 0; i < a.size(); i++) {
		if (i & 1) {
			if (a[i] - '0' != d) return 0;
		}
		else if (a[i] - '0' == d) return 0;
		md = (md * 10 + a[i] - '0') % m;
	}
	return !md;
}

void solve() {
	cin >> m >> d;
	string a, b;
	cin >> a >> b;
	cout << (calc(b) - calc(a) + check(a) + mod) % mod << endl;
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
