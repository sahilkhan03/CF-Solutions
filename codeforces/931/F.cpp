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

struct SegTree
{
	int size;
	vl val;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		val = vl(2 * size, 0);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (i < lx or i >= rx) return;
		if (rx - lx == 1) {
			val[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		set(i, v, 2 * x + 1, lx, mid);
		set(i, v, 2 * x + 2, mid, rx);
		val[x] = max(val[2 * x + 1], val[2 * x + 2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return 0;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return max(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
	}
	ll query(int r) {
		return query(0, r, 0, 0, size);
	}
};


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pl> v(n);
	cin >> v;
	sort(all(v));
	vl cnt(m);
	multiset<ll> s;
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (!s.empty() and * s.begin() < i) s.erase(s.begin());
		while (j < n and v[j].F - 1 <= i) s.insert(v[j++].S - 1);
		cnt[i] = s.size();
	}
	debug(cnt);
	SegTree seg(n);
	vl pre(m), suf(m);
	for (int i = 0; i < m; i++) {
		pre[i] = 1 + seg.query(cnt[i] + 1);
		seg.set(cnt[i], pre[i]);
	}
	seg = SegTree(n);
	for (int i = m - 1; i >= 0; i--) {
		suf[i] = 1 + seg.query(cnt[i] + 1);
		seg.set(cnt[i], suf[i]);
	}
	ll ans = 0;
	for (int i = 0; i < m; i++)
		ans = max(ans, pre[i] + suf[i] - 1);
	cout << ans << endl;
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
