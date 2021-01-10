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
int n, m, t = 0;
vector<vi> v;
vi col;
vector<pl> inout;

void dfs(int u, int p) {
	inout[u].F = t++;
	for (int x : v[u])
		if (x != p) dfs(x, u);
	inout[u].S = t;
}

struct SegTree
{
	int size;
	vl val, lazy;
	SegTree(vl &v) {
		size = 1;
		while (size < v.size()) size *= 2;
		val = lazy = vl(2 * size, 0);
		build(v);
	}
	void propagate(int node) {
		if (2 * node + 2  < 2 * size)
			lazy[2 * node + 1] = lazy[2 * node + 2] = lazy[node];
		val[node] = lazy[node];
		lazy[node] = 0;
	}
	void build(vl &v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < v.size())
				val[x] = v[lx];
			return;
		}
		int mid = (lx + rx) / 2;
		build(v, 2 * x + 1, lx, mid);
		build(v, 2 * x + 2, mid, rx);
		val[x] = (val[2 * x + 1] | val[2 * x + 2]);
	}
	void build(vl &v) {
		build(v, 0, 0, size);
	}
	void set(int l, int r, ll v, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return;
		if (l <= lx and rx <= r) {
			lazy[x] = v;
			propagate(x);
			return;
		}
		int mid = (lx + rx) / 2;
		set(l, r, v, 2 * x + 1, lx, mid);
		set(l, r, v, 2 * x + 2, mid, rx);
		val[x] = (val[2 * x + 1] | val[2 * x + 2]);
	}
	void set(int l, int r, ll v) {
		set(l, r, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lazy[x]) propagate(x);
		if (lx >= r or rx <= l) return 0;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return (query(l, r, 2 * x + 1, lx, mid) | query(l, r, 2 * x + 2, mid, rx));
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


void solve() {
	cin >> n >> m;
	col = vi(n);
	cin >> col;
	v = vector<vi>(n);
	inout = vector<pl>(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	dfs(0, -1);
	vl cl(n);
	for (int i = 0; i < n; i++) {
		cl[inout[i].F] = (1ll << col[i]);
	}
	SegTree seg(cl);
	while (m--) {
		int x; cin >> x;
		if (x == 1) {
			int a, b;
			cin >> a >> b;
			seg.set(inout[a - 1].F, inout[a - 1].S, (1ll << b));
		}
		else {
			int u; cin >> u;
			cout << __builtin_popcountll(seg.query(inout[u - 1].F, inout[u - 1].S)) << endl;
		}
	}
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
