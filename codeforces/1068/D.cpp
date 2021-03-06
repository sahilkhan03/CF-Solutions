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

const ll mod = 998244353.;

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	vector<vl> dp(2, vl(201));
	if (n == 2) {
		if (v[0] == -1) {
			if (v[1] == -1) {
				cout << 200 << endl;
				return;
			}
			cout << 1 << endl;
			return;
		}
		if (v[1] == -1 or v[0] == v[1]) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}
	if (v[0] == -1) {
		for (int j = 1; j <= 200; j++) {
			dp[0][j] = dp[0][j - 1] + 1;
		}
	} else {
		for (int j = v[0]; j <= 200; j++)
			dp[0][j] = 1;
	}
	for (int i = 1; i < n; i++) {
		vector<vl> dpn(2, vl(201));
		if (i == 1) {
			for (int j = 1; j <= 200; j++) {
				bool f = (v[i] == -1 or v[i] == j);
				dpn[0][j] = dp[0][j - 1] * f;
				dpn[1][j] = (v[i - 1] == -1 or v[i - 1] == j) * f;
			}
		}
		else if (i == n - 1) {
			for (int j = 1; j <= 200; j++) {
				bool f = (v[i] == -1 or v[i] == j);
				dpn[1][j] = ((mod + dp[0][j] - dp[0][j - 1] + dp[1][200] - dp[1][j - 1]) * f) % mod;
			}
		}
		else {
			for (int j = 1; j <= 200; j++) {
				bool f = (v[i] == -1 or v[i] == j);
				dpn[0][j] = ((dp[0][j - 1] + dp[1][j - 1]) * f) % mod;
				dpn[1][j] = ((mod + dp[1][200] - dp[1][j - 1] + dp[0][j] - dp[0][j - 1]) * f) % mod;
			}
		}
		for (int j = 1; j <= 200; j++) {
			dp[0][j] = (dp[0][j - 1] + dpn[0][j]) % mod;
			dp[1][j] = (dp[1][j - 1] + dpn[1][j]) % mod;
		}
	}
	ll ans = 0;
	for (int j = 1; j <= 200; j++) {
		bool f = (v[n - 1] == -1 or v[n - 1] == j);
		(ans += f * (dp[1][j] - dp[1][j - 1] + mod)) %= mod;
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
