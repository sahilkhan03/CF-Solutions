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

vector<vi> pos(3e5 + 5);

ll freq(int x, int l, int r) {
	return upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
}

struct SegTree
{
	int size;
	vl val;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		val = vl(2 * size, 0);
	}
	SegTree(vl &v) {
		size = 1;
		while (size < v.size()) size *= 2;
		val = vl(2 * size, 0);
		build(v);
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
		val[x] = (freq(val[2 * x + 1], lx, rx - 1) > freq(val[2 * x + 2], lx, rx - 1) ? val[2 * x + 1] : val[2 * x + 2]);
	}
	void build(vl &v) {
		build(v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return 0;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		int a = query(l, r, 2 * x + 1, lx, mid), b = query(l, r, 2 * x + 2, mid, rx);
		return (freq(a, l, r - 1) > freq(b, l, r - 1) ? a : b);
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


void solve() {
	int n, q;
	cin >> n >> q;
	vl arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pos[arr[i]].pb(i);
	}
	SegTree seg(arr);
	while (q--) {
		int l, r, ans = 1;
		cin >> l >> r;
		l--, r--;
		int x = seg.query(l, r + 1);
		int cnt = freq(x, l, r);
		if (cnt > (r - l + 1) / 2) ans = 1 + cnt - ((r - l + 1) - cnt + 1);
		cout << ans << endl;
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
