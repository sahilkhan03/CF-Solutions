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
int n;

int ask(int l, int r) {
	cout << "? " << l << " " << r << endl << flush;
	int x; cin >> x;
	return x;
}

struct LazySegTree1
{
	int size;
	vl val, lazy;
	LazySegTree1() {}
	LazySegTree1(int _n) {
		size = 1;
		while (size < _n) size *= 2;
		val = vl(2 * size, 1e18);
		lazy = vl(2 * size, 0);
	}
	void propagate(int node) {
		if (2 * node + 2  < 2 * size) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		val[node] += lazy[node];
		lazy[node] = 0;
	}
	void rset(int l, int r, ll v, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return;
		if (l <= lx and rx <= r) {
			lazy[x] = v;
			propagate(x);
			return;
		}
		int mid = (lx + rx) / 2;
		rset(l, r, v, 2 * x + 1, lx, mid);
		rset(l, r, v, 2 * x + 2, mid, rx);
		val[x] = min(val[2 * x + 1], val[2 * x + 2]);
	}
	void rset(int l, int r, ll v) {
		rset(l, r, v, 0, 0, size);
	}
	void set(int l, ll v, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (l >= rx or l < lx) return;
		if (rx - lx == 1 and l == lx) {
			val[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		set(l, v, 2 * x + 1, lx, mid);
		set(l, v, 2 * x + 2, mid, rx);
		val[x] = min(val[2 * x + 1], val[2 * x + 2]);
	}
	void set(int l, ll v) {
		set(l, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return 1e18;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return min(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


struct LazySegTree2
{
	int size;
	vl val, lazy;
	LazySegTree2() {}
	LazySegTree2(int _n) {
		size = 1;
		while (size < _n) size *= 2;
		val = vl(2 * size, -1e18);
		lazy = vl(2 * size, 0);
	}
	void propagate(int node) {
		if (2 * node + 2  < 2 * size) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		val[node] += lazy[node];
		lazy[node] = 0;
	}
	void rset(int l, int r, ll v, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return;
		if (l <= lx and rx <= r) {
			lazy[x] = v;
			propagate(x);
			return;
		}
		int mid = (lx + rx) / 2;
		rset(l, r, v, 2 * x + 1, lx, mid);
		rset(l, r, v, 2 * x + 2, mid, rx);
		val[x] = max(val[2 * x + 1], val[2 * x + 2]);
	}
	void rset(int l, int r, ll v) {
		rset(l, r, v, 0, 0, size);
	}
	void set(int l, ll v, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (l >= rx or l < lx) return;
		if (rx - lx == 1 and l == lx) {
			val[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		set(l, v, 2 * x + 1, lx, mid);
		set(l, v, 2 * x + 2, mid, rx);
		val[x] = max(val[2 * x + 1], val[2 * x + 2]);
	}
	void set(int l, ll v) {
		set(l, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return -1e18;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return max(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

LazySegTree1 seg1;
LazySegTree2 seg2;
vi vis;
void solve() {
	int k; cin >> k;
	int lo = n, hi = 1, mid, ans;
	for (ll st = 1e6; st; st /= 2) {
		while (lo - st > 0 and seg1.query(lo - st, n + 1) >= k) lo -= st;
		while (hi + st <= n and seg2.query(1, hi + st + 1) <= k) hi += st;
	}
	ans = hi;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		ll sum = seg1.query(mid, mid + 1);
		if (!vis[mid]) {
			sum = mid - ask(1, mid);
			seg1.set(mid, sum);
			seg2.set(mid, sum);
			vis[mid] = 1;
		}
		if (sum >= k) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	seg1.rset(ans, n + 1, -1);
	seg2.rset(ans, n + 1, -1);
	cout << "! " << ans << endl << flush;
}

int main()
{
	// fast;
	int T = 1;
	cin >> n >> T;
	seg1 = LazySegTree1(n + 3);
	seg2 = LazySegTree2(n + 3);
	vis = vi(n + 5);
	seg1.set(0, -1e18);
	seg2.set(n + 1, 1e18);
	while (T--) {
		solve();
	}
	return 0;
}
