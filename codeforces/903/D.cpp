#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pl, null_type, less<pl>, rb_tree_tag, tree_order_statistics_node_update>

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

template <class T> struct fenwick_tree {
public:
	fenwick_tree() : _n(0) {}
	fenwick_tree(int n) : _n(n), data(n) {}

	void add(int p, T x) {
		assert(0 <= p && p < _n);
		p++;
		while (p <= _n) {
			data[p - 1] += T(x);
			p += p & -p;
		}
	}

	T sum(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		return sum(r) - sum(l);
	}

private:
	int _n;
	std::vector<T> data;

	T sum(int r) {
		T s = 0;
		while (r > 0) {
			s += data[r - 1];
			r -= r & -r;
		}
		return s;
	}
};


void solve() {
	ll n; cin >> n;
	fenwick_tree<ll> fen1(n + 10), fen2(n + 10);
	vector<pl> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].F;
		v[i].S = i;
	}
	sort(all(v));
	vl inv(n);
	ordered_set s;
	for (int i = 0; i < n; i++) inv[v[i].S] = i;
	sort(all(v), [&](pl & a, pl & b) -> bool {
		return a.S < b.S;
	});
	// debug(inv);
	long double ans = 0;
	s.insert({1e9 + 7, n + 1});
	s.insert({ -1e9, -1});
	for (int i = 0; i < n; i++) {
		auto idx1 = prev(s.lower_bound({v[i].F - 1, -1e9}));
		auto idx2 = s.upper_bound({v[i].F + 1, 1e9});
		// debug(*idx1, *idx2);
		ll sum = fen1.sum(0, idx1->S + 1) + fen1.sum(idx2->S, n + 2);
		ll c = fen2.sum(0, idx1->S + 1) + fen2.sum(idx2->S, n + 2);
		ans += c * v[i].F - sum;
		// debug(sum, c);
		s.insert({v[i].F, inv[i]});
		fen1.add(inv[i], v[i].F);
		fen2.add(inv[i], 1);
	}
	printf("%.0Lf\n", ans);
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
