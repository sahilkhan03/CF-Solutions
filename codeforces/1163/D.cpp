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

vector<vi> calc(string s) {
	int n = s.size();
	s += '#';
	vector<vi> nxt(n + 1, vi(26));
	vi kmp(n + 1); kmp[0] = -1;
	int i = 0, j = -1;
	while (i < n) {
		while (j >= 0 and s[i] != s[j]) j = kmp[j];
		i++, j++;
		kmp[i] = j;
	}
	for (int i = 0; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			int j = i;
			while (j >= 0 and c != s[j]) j = kmp[j];
			nxt[i][c - 'a'] = j + 1;
		}
	}
	return nxt;
}

void solve() {
	string v, s, t;
	cin >> v >> s >> t;
	int k = v.size(), n = s.size(), m = t.size();
	vector<vector<vi>> dp(k + 1, vector<vi>(n + 1, vi(m + 1, -1e9)));
	auto nxts = calc(s), nxtt = calc(t);
	dp[0][0][0] = 0;
	for (int i = 0; i < k; i++) {
		for (int ps = 0; ps <= n; ps++) {
			for (int pt = 0; pt <= m; pt++) {
				for (char c = 'a'; c <= 'z'; c++) {
					if (c == v[i] or v[i] == '*') {
						int ns = nxts[ps][c - 'a'], nt = nxtt[pt][c - 'a'];
						dp[i + 1][ns][nt] = max(dp[i + 1][ns][nt], dp[i][ps][pt] + (ns == n) - (nt == m));
					}
				}
			}
		}
	}
	int ans = -1e9;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			ans = max(ans, dp[k][i][j]);
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
