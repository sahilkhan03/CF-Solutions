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
	ll n, t;
	cin >> n >> t;
	if (n == 1) {
		ll x; cin >> x;
		if (x <= t) cout << x << endl;
		else cout << 0 << endl;
		return;
	}
	vl v1, v2;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (i < n / 2) v1.pb(x);
		else v2.pb(x);
	}
	ll n1 = v1.size(), n2 = v2.size();
	vl ls1, ls2;
	for (int i = 0; i < (1 << n1); i++) {
		ll cur = 0;
		for (int j = 0; j < n1; j++) {
			if (i & (1 << j)) cur += v1[j];
		}
		ls1.pb(cur);
	}
	for (int i = 0; i < (1 << n2); i++) {
		ll cur = 0;
		for (int j = 0; j < n2; j++) {
			if (i & (1 << j)) cur += v2[j];
		}
		ls2.pb(cur);
	}
	sort(all(ls2));
	sort(all(ls1));
	ll ans = 0;
	for (int i = 0; i < ls1.size(); i++) {
		ll cur = ls1[i];
		auto it = upper_bound(all(ls2), t - cur);
		if (it != ls2.begin()) {
			it = prev(it);
			debug(cur, *it);
			ans = max(ans, cur + *it);
		}
	}
	debug(ls1, ls2);
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
