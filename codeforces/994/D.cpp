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
	int n, m;
	cin >> n >> m;
	vector<pl> a(n), b(m);
	cin >> a >> b;
	vl cnt(10);
	for (int i = 0; i < n; i++) {
		ll p = 0, q = 0;
		for (int j = 0; j < m; j++) {
			ll m1 = (a[i].F == b[j].F or a[i].F == b[j].S);
			ll m2 = (a[i].S == b[j].F or a[i].S == b[j].S);
			if (m1 and m2) continue;
			p += m1, q += m2;
		}
		if (p and q) {
			cout << -1 << endl;
			return;
		}
		if (p) cnt[a[i].F] = 1;
		else if (q) cnt[a[i].S] = 1;
	}
	for (int i = 0; i < m; i++) {
		ll p = 0, q = 0;
		for (int j = 0; j < n; j++) {
			ll m1 = (b[i].F == a[j].F or b[i].F == a[j].S);
			ll m2 = (b[i].S == a[j].F or b[i].S == a[j].S);
			if (m1 and m2) continue;
			p += m1, q += m2;
		}
		if (p and q) {
			cout << -1 << endl;
			return;
		}
		if (p) cnt[b[i].F] = 1;
		else if (q) cnt[b[i].S] = 1;
	}
	if (count(all(cnt), 1) > 1) cout << 0 << endl;
	else cout << max_element(all(cnt)) - cnt.begin() << endl;
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
