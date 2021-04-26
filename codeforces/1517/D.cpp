#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define ll int
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

struct cmp {
	bool operator()(const array<ll, 4>& a, const array<ll, 4>& b) {
		if (a[0] == b[0]) return a[3] < b[3];
		return a[0] > b[0];
	}
};

void solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vi> h(n, vi(m - 1));
	vector<vi> v(n - 1, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++)
			scanf("%d", &h[i][j]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &v[i][j]);
	}
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("-1 ");
			}
			printf("\n");
		}
		return;
	}
	k /= 2;
	vector<vi> dp(n, vi(m));
	while (k--) {
		vector<vi> ndp(n, vi(m, mod));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + 1 < n) ndp[i][j] = min(ndp[i][j], v[i][j] + dp[i + 1][j]);
				if (i > 0) ndp[i][j] = min(ndp[i][j], v[i - 1][j] + dp[i - 1][j]);
				if (j + 1 < m) ndp[i][j] = min(ndp[i][j], h[i][j] + dp[i][j + 1]);
				if (j > 0) ndp[i][j] = min(ndp[i][j], h[i][j - 1] + dp[i][j - 1]);
			}
		}
		dp = ndp;
	}
	for (auto& x : dp) {
		for (auto& y : x) printf("%d ", 2 * y);
		printf("\n");
	}
}

int main()
{
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
