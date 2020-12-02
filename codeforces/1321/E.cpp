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

struct SegTree
{
	int size;
	vector<pl> val;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		val = vector<pl>(2 * size, { -mod , 0});
	}
	void set(int l, int r, ll v, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return;
		if (lx >= l and rx <= r) {
			val[x].S += v;
			val[x].F += v;
			return;
		}
		int mid = (lx + rx) / 2;
		set(l, r, v, 2 * x + 1, lx, mid);
		set(l, r, v, 2 * x + 2, mid, rx);
		val[x].F = max(val[2 * x + 1].F, val[2 * x + 2].F) + val[x].S;
	}
	void set(int l, int r, ll v) {
		set(l, r, v, 0, 0, size);
	}
};


vector<pl> uniq(vector<pl> &a) {
	sort(all(a), [](pl & a, pl & b) -> bool {
		if (a.S == b.S) return a.F > b.F;
		return a.S < b.S;
	});
	vector<pl> res;
	ll ls = -1;
	for (auto x : a) {
		if (x.F > ls) {
			ls = x.F;
			res.pb(x);
		}
	}
	return res;
}

void solve() {
	ll n, m, p;
	cin >> n >> m >> p;
	vector<pl> a(n), b(m);
	vector<vl> v(p, vl(3));
	cin >> a >> b >> v;
	a = uniq(a), b = uniq(b);
	sort(all(v));
	SegTree seg(b.size());
	for (int i = 0; i < b.size(); i++) seg.set(i, i + 1, mod - b[i].S);
	ll j = 0, ans = -(a[0].S + b[0].S);
	debug(v);
	for (int i = 0; i < a.size(); i++) {
		while (j < p and v[j][0] < a[i].F) {
			ll idx = -1;
			for (ll st = 1e6; st; st /= 2) {
				while (idx + st < b.size() and b[idx + st].F <= v[j][1])
					idx += st;
			}
			idx++;
			seg.set(idx, b.size(), v[j][2]);
			debug(i, j, idx);
			debug(seg.val);
			ans = max(ans, seg.val[0].F - a[i].S);
			j++;
		}
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
