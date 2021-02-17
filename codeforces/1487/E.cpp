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

void in(vector<pl> &v) {
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i].F;
		v[i].S = i;
	}
}

void calc(vector<pl> &a, vector<pl> &b) {
	sort(all(a));
	set<ll> s;
	for (int i = 0; i < b.size(); i++) s.insert(i);
	ll m; cin >> m;
	vector<set<ll>> v(a.size());
	while (m--) {
		ll x, y;
		cin >> x >> y;
		v[x - 1].insert(y - 1);
	}
	vl tmp(b.size(), 1e18);
	for (auto x : a) {
		if (s.empty()) break;
		vl rem;
		for (auto y : s) {
			if (v[x.S].find(y) == v[x.S].end()) {
				tmp[y] = x.F;
				rem.pb(y);
			}
		}
		for (auto y : rem) s.erase(s.find(y));
	}
	for (int i = 0; i < b.size(); i++)
		b[i].F += tmp[i];
}

void solve() {
	ll n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	vector<pl> a(n1), b(n2), c(n3), d(n4);
	in(a); in(b); in(c); in(d);
	calc(a, b); calc(b, c); calc(c, d);
	ll ans = min_element(all(d))->F;
	cout << (ans >= 1e18 ? -1 : ans) << endl;
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
