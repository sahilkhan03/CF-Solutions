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

ll modpow(ll n, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

void solve() {
	ll n; cin >> n;
	string s; cin >> s;
	vector<vector<vl>> dp(4, vector<vl>(4, vl(n + 1)));
	ll ans = 0;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int qc = 0; qc <= 3; qc++) {
			for (int pre = 0; pre <= 3; pre++) {
				dp[pre][qc][i] = dp[pre][qc][i - 1];
				bool f = (s[i - 1] == '?');
				if ((pre == s[i - 1] - 'a' + 1 or f) and qc - f >= 0 and pre > 0)
					(dp[pre][qc][i] += dp[pre - 1][qc - f][i - 1]) %= mod;
			}
		}
	}
	ll c = 0;
	for (auto x : s) c += (x == '?');
	for (int i = 0; i <= 3 and c - i >= 0; i++) {
		debug(dp[3][i][n]);
		(ans += (dp[3][i][n] * modpow(3, c - i)) % mod) %= mod;
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
