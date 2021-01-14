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

const ll mod = 998244353;

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	ll ans = 0;
	vl cnt(12);
	for (auto x : v) cnt[ll(log10(x)) + 1]++;
	for (int i = 0; i < n; i++) {
		ll num = v[i], sz = log10(v[i]) + 1, used = 0, ls = 0;
		for (ll j = 1, pw = 100, k = 11; j <= sz; j++) {
			(ls += (num % 10) * k) %= mod;
			num /= 10;
			(ans += ((2 * num * pw + ls) % mod) * cnt[j]) %= mod;
			used += cnt[j];
			(k *= 100) %= mod;
			(pw *= 100) %= mod;
			debug(num, ls, k, pw, used, ans);
		}
		(ans += (n - used) * ls) %= mod;
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
