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

void solve() {
	ll n, t;
	cin >> n >> t;
	vi v(n); cin >> v;
	function<vi(int)> build = [&](int tm) {
		vi ret(n * tm);
		for (int i = 0; i < n; i++) ret[i] = v[i];
		for (int i = 1; i < tm; i++) {
			for (int j = 0; j < n; j++)
				ret[i * n + j] = v[j];
		}
		return ret;
	};
	function<vi(vi)> calc = [&](vi a) {
		int n = a.size();
		vi res(n), dp(n + 5, 301);
		dp[0] = -1;
		for (int i = 0; i < n; i++) {
			res[i] = upper_bound(all(dp), a[i]) - dp.begin();
			dp[res[i]] = a[i];
		}
		return res;
	};
	if (t <= 2 * n) {
		vi ret = build(t);
		ret = calc(ret);
		cout << *max_element(all(ret)) << endl;
		return;
	}
	vi ret = build(n), pre = calc(ret);
	for (int i = 0; i < ret.size(); i++) ret[i] = 301 - ret[i];
	reverse(all(ret));
	vi suf = calc(ret);
	reverse(all(suf));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (auto x : v) cnt += (x == v[i]);
		for (int j = 0; j < n; j++) {
			if (v[j] < v[i]) continue;
			ans = max(ans, pre[(n - 1) * n + i] + cnt * (t - 2 * n) + suf[j]);
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
