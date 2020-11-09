#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
ll n, k;
struct SegTree
{
	int size;
	vl val;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		val = vl(2 * size, 1);
	}
	SegTree(vl &v) {
		size = 1;
		while (size < v.size()) size *= 2;
		val = vl(2 * size, 1);
		build(v);
	}
	void build(vl &v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < v.size())
				val[x] = v[lx] % k;
			return;
		}
		int mid = (lx + rx) / 2;
		build(v, 2 * x + 1, lx, mid);
		build(v, 2 * x + 2, mid, rx);
		val[x] = (val[2 * x + 1] * val[2 * x + 2]) % k;
	}
	void build(vl &v) {
		build(v, 0, 0, size);
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
		val[x] = val[2 * x + 1] + val[2 * x + 2];
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	ll query(int l, int r, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return 1;
		if (l <= lx and rx <= r) return val[x];
		int mid = (lx + rx) / 2;
		return query(l, r, 2 * x + 1, lx, mid) * query(l, r, 2 * x + 2, mid, rx) % k;
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

void solve() {
	cin >> n >> k;
	vl v(n); cin >> v;
	SegTree seg(v);
	debug(seg.val);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll last = i - 1;
		for (int j = n - i; j; j /= 2) {
			debug(seg.query(i, last + j + 1), i, last + j + 1);
			while (last + j < n and seg.query(i, last + j + 1) != 0)
				last += j;
		}
		ans += n - last - 1;
		debug(i, last);
	}
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
