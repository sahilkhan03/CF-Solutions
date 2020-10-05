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
	if (p < 0) return 0;
	while (p) {
		if (p & 1) (ans *= n) %= mod;
		(n *= n) %= mod, p /= 2;
	}
	return ans;
}

void solve() {
	string s; cin >> s;
	ll ans = 0, n = s.size();
	vl lf(1e6 + 5);
	lf[0] = 1;
	for (int i = 1; i < lf.size(); i++) {
		lf[i] = (lf[i - 1] * 10 + i + 1) % mod;
	}
	for (ll i = 0; i < s.size(); i++) {
		ll num = (modpow(10, n - i - 1) * ((i * (i + 1) / 2) % mod)) % mod;
		ll fs = 0;
		fs = (modpow(9, mod - 2) * (modpow(10, n - i - 1) - 1)) % mod;
		(fs *= n - i - 1) %= mod;
		(num += fs) %= mod;
		if (n - i - 3 >= 0)
			num = (num - lf[n - i - 3] + mod) % mod;
		(ans += num * (s[i] - '0')) %= mod;
		debug(i, fs, num);
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
