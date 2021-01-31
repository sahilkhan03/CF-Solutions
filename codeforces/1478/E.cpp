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

struct LazySegTree
{
	int size;
	vl val, lazy;
	LazySegTree(string& v) {
		size = 1;
		while (size < v.size()) size *= 2;
		val = vl(2 * size, -1);
		lazy = vl(2 * size, -1);
		build(v);
	}
	void propagate(int node, int len) {
		if (2 * node + 2  < 2 * size)
			lazy[2 * node + 1] = lazy[2 * node + 2] = lazy[node];
		val[node] = lazy[node] * len;
		lazy[node] = -1;
	}
	void build(string &v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < v.size())
				val[x] = v[lx] - '0';
			return;
		}
		int mid = (lx + rx) / 2;
		build(v, 2 * x + 1, lx, mid);
		build(v, 2 * x + 2, mid, rx);
		val[x] = val[2 * x + 1] + val[2 * x + 2];
	}
	void build(string &v) {
		build(v, 0, 0, size);
	}
	void set(int l, int r, ll v, int x, int lx, int rx) {
		if (lazy[x] != -1) propagate(x, rx - lx);
		if (lx >= r or rx <= l) return;
		if (l <= lx and rx <= r) {
			lazy[x] = v;
			propagate(x, rx - lx);
			return;
		}
		int mid = (lx + rx) / 2;
		set(l, r, v, 2 * x + 1, lx, mid);
		set(l, r, v, 2 * x + 2, mid, rx);
		val[x] = val[2 * x + 1] + val[2 * x + 2];
	}
	void set(int l, int r, ll v) {
		set(l, r, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lazy[x] != -1) propagate(x, rx - lx);
		if (lx >= r or rx <= l) return 0;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


void solve() {
	int n, q;
	cin >> n >> q;
	string s, t;
	cin >> s >> t;
	vector<pl> qr(q);
	cin >> qr;
	LazySegTree seg(t);
	for (int i = q - 1; i >= 0; i--) {
		auto [l, r] = qr[i];
		int sum = seg.query(l - 1, r);
		if (2 * sum == r - l + 1) {
			cout << "NO" << endl;
			return;
		}
		seg.set(l - 1, r, (2 * sum > r - l + 1));
	}
	for (int i = 0; i < n; i++) {
		if (s[i] - '0' != seg.query(i, i + 1)) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
