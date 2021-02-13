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
	ll n, m;
	cin >> n >> m;
	vector<pl> v(m);
	cin >> v;
	vector<multiset<pl>> st(n);
	for (auto x : v) {
		x.F--, x.S--;
		st[x.F].insert({x.S + n * (x.S < x.F) - x.F, x.S});
	}
	for (int i = 0; i < n; i++) {
		ll del = 0, ans = 0, j = i;
		auto s = st;
		vl tmp(n);
		while (del < m) {
			del += tmp[j];
			tmp[j] = 0;
			if (!s[j].empty()) {
				tmp[s[j].rbegin()->S]++;
				s[j].erase(prev(s[j].end()));
			}
			debug(j, del);
			(j += 1) %= n;
			ans++;
		}
		cout << ans - 1 << " ";
	}
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
