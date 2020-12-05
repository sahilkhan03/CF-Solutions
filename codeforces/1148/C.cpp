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

vl v, inv;
void cswap(ll p1, ll p2) {
	swap(v[p1], v[p2]);
	inv[v[p1]] = p1;
	inv[v[p2]] = p2;
}

void solve() {
	ll n; cin >> n;
	v.resize(n), inv.resize(n + 1); cin >> v;
	for (int i = 0; i < n; i++) inv[v[i]] = i;
	vector<pl> ans;
	for (int i = 2; i < n; i++) {
		ll cur = inv[i];
		if (i <= n / 2) {
			if (cur >= n / 2) {
				ans.pb({1, cur + 1});
				cswap(cur, 0);
				cur = 0;
			}
			ans.pb({cur + 1, n});
			ans.pb({n, i});
			cswap(cur, n - 1);
			cswap(n - 1, i - 1);
		}
		else {
			if (cur < n / 2) {
				ans.pb({cur + 1, n});
				cswap(cur, n - 1);
				cur = n - 1;
			}
			ans.pb({1, cur + 1});
			ans.pb({1, i});
			cswap(cur, 0);
			cswap(0, i - 1);
		}
	}
	if (v[0] != 1) ans.pb({1, n});
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
