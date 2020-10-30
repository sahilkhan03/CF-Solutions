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
	ll n, k;
	cin >> n >> k;
	vl v(n); cin >> v;
	sort(all(v));
	ll ans = 1e18;
	vl pre(n + 1), suf(n + 2);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + v[i];
		suf[n - i] = suf[n - i + 1] + v[n - i - 1];
	}
	for (int l = 0; l < n; l++) {
		auto it = lower_bound(all(v), v[l]) - v.begin();
		ll cost = it * v[l] - pre[it];
		if (cost > k) break;
		ll rem = k - cost;
		ll lo = v[l], hi = v.back(), mid, r = v.back();
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			auto it1 = v.end() - upper_bound(all(v), mid);
			ll c = suf[n - it1 + 1] - it1 * mid;
			if (c > rem) lo = mid + 1;
			else hi = mid - 1, r = mid;
		}
		ans = min(ans, r - v[l]);
	}
	for (int r = n - 1; r >= 0; r--) {
		auto it = v.end() - upper_bound(all(v), v[r]);
		ll cost = suf[n - it + 1] - it * v[r];
		if (cost > k) break;
		ll rem = k - cost;
		ll lo = v[0], hi = v[r], mid, l = v[0];
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			auto it1 = lower_bound(all(v), mid) - v.begin();
			ll c = it1 * mid - pre[it1];
			if (c > rem) hi = mid - 1;
			else lo = mid + 1, l = mid;
		}
		ans = min(ans, v[r] - l);
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
