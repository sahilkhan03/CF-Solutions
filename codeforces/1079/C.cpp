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
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	vl ans(n);
	vector<vi> dp(n, vi(5, -1));
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	dp[0][3] = 1;
	dp[0][4] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (v[i] == v[i - 1]) {
					if (j != k and dp[i - 1][k] != -1) dp[i][j] = k;
				}
				else if (v[i] > v[i - 1]) {
					if (j > k and dp[i - 1][k] != -1) dp[i][j] = k;
				}
				else if (j < k and dp[i - 1][k] != -1) dp[i][j] = k;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (dp[n - 1][i] != -1) {
			int cur = i;
			for (int j = n - 1; j >= 0; j--) {
				ans[j] = cur + 1;
				cur = dp[j][cur];
			}
			cout << ans << endl;
			return;
		}
	}
	cout << -1 << endl;
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
