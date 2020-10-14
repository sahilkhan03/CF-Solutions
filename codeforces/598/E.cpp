#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

void solve() {
	vector<vector<vl>> dp(31, vector<vl> (31, vl(51, 1e18)));
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			for (int k = 0; k <= 50; k++) {
				if (!k or i * j == k) {
					dp[i][j][k] = 0;
					continue;
				}
				for (int l = 1; l < i; l++) {
					for (int r = 0; r <= k; r++) {
						dp[i][j][k] = min(dp[i][j][k], j * j + min(dp[l][j][r] + dp[i - l][j][k - r], dp[l][j][k - r] + dp[i - l][j][r]));
					}
				}
				for (int l = 1; l < j; l++) {
					for (int r = 0; r <= k; r++) {
						dp[i][j][k] = min(dp[i][j][k], i * i + min(dp[i][l][r] + dp[i][j - l][k - r], dp[i][l][k - r] + dp[i][j - l][r]));
					}
				}
			}
		}
	}
	ll t; cin >> t;
	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		cout << dp[a][b][c] << endl;
	}
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
