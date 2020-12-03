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
	ll n, m, k;
	cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	if (n == 1) {
		if (k <= m - 1) cout << 1 << endl << k << " R" << endl;
		else cout << 2 << endl << m - 1 << " R" << endl << k - m + 1 << " L" << endl;
		return;
	}
	if (m == 1) {
		if (k <= n - 1) cout << 1 << endl << k << " D" << endl;
		else cout << 2 << endl << n - 1 << " D" << endl << k - n + 1 << " U" << endl;
		return;
	}
	vector<pair<int, string>> ans;
	if (k <= m - 1) ans.pb({k, "R"}), k = 0;
	else ans.pb({m - 1, "R"}), k -= m - 1;
	if (k > 0 and k <= m - 1) ans.pb({k, "L"}), k = 0;
	else if (k > 0) ans.pb({m - 1, "L"}), k -= m - 1;
	debug(k, ans);
	if (k > 0) ans.pb({1, "D"}), k--;
	ll r = 1;
	while (k > 0 and r < n) {
		ll cnt = min(m - 1, k / 3);
		if (cnt) ans.pb({cnt, "RUD"}), k -= 3 * cnt;
		if (cnt < m - 1 and k % 3) ans.pb({1, string("RUD").substr(0, k % 3)}), k -= k % 3;
		cnt = min(k, m - 1);
		if (cnt) ans.pb({cnt, "L"}), k -= cnt;
		if (k and r != n - 1) ans.pb({1, "D"}), k--;
		r++;
	}
	if (k > 0) ans.pb({k, "U"});
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
