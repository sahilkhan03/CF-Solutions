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
	int n, k, ans = 0;
	cin >> n >> k;
	vi v(n * k); cin >> v;
	vi fav(n); cin >> fav;
	vi h(k); cin >> h;
	vi cnt(1e5 + 5), done(1e5 + 5);
	for (int i = 0; i < n * k; i++) cnt[v[i]]++;
	for (int i = 0; i < n; i++) {
		if (!done[fav[i]]) {
			done[fav[i]] = 1;
			vector<vi> dp(n + 1, vi(cnt[fav[i]] + 1, -1e9));
			dp[0][0] = 0;
			for (int j = 1; j <= n; j++) {
				for (int used = 0; used <= cnt[fav[i]]; used++) {
					dp[j][used] = dp[j - 1][used];
					for (int l = 1; l <= k and used - l >= 0; l++)
						dp[j][used] = max(dp[j][used], dp[j - 1][used - l] + h[l - 1] * (fav[j - 1] == fav[i]));
				}
			}
			debug(fav[i], dp[n][cnt[fav[i]]]);
			ans += dp[n][cnt[fav[i]]];
		}
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
