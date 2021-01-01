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

struct SegTree
{
	int size;
	vector<array<int, 6>> val;
	SegTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		val = vector<array<int , 6>>(2 * size, {0, 0, 0, 0, 0, 0});
	}
	void set(int i, int v, int x, int lx, int rx) {
		if (i < lx or i >= rx) return;
		if (rx - lx == 1) {
			val[x] = {v, max(v, 0), min(v, 0), min(v, 0), val[x][4], v + val[x][4]};
			return;
		}
		int mid = (lx + rx) / 2;
		set(i, v, 2 * x + 1, lx, mid);
		set(i, v, 2 * x + 2, mid, rx);
		val[x][0] = val[2 * x + 1][0] + val[2 * x + 2][0];
		val[x][1] = max({val[2 * x + 1][1], val[2 * x + 2][1], val[x][0] - val[2 * x + 1][2] - val[2 * x + 2][3]});
		val[x][2] = min(val[2 * x + 1][2], val[2 * x + 1][0] + val[2 * x + 2][2]);
		val[x][3] = min(val[2 * x + 2][3], val[2 * x + 2][0] + val[2 * x + 1][3]);
		val[x][5] = min(val[2 * x + 1][5], val[2 * x + 2][5]) + val[x][4];
	}
	void setr(int l, int r, int v, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return;
		if (lx >= l and rx <= r) {
			val[x][4] += v;
			val[x][5] += v;
			return;
		}
		int mid = (lx + rx) / 2;
		setr(l, r, v, 2 * x + 1, lx, mid);
		setr(l, r, v, 2 * x + 2, mid, rx);
		val[x][5] = min(val[2 * x + 1][5], val[2 * x + 2][5]) + val[x][4];
	}
	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r or rx <= l) return 0;
		if (lx >= l and rx <= r) {
			return val[x][0];
		}
		int mid = (lx + rx) / 2;
		return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	void set(int v, int l, int r) {
		setr(l, r, v, 0, 0, size);
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

void solve() {
	int n, sz = 0; scanf("%d\n", &n);
	int cur = 0;
	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &v[i]);
		if (v[i] == 'R') cur++;
		else if (v[i] == 'L') cur = max(0, cur - 1);
		sz = max(sz, cur + 3);
	}
	cur = 0;
	SegTree seg(sz);
	vector<char> s(sz, ' ');
	for (int i = 0; i < n; i++) {
		char c = v[i];
		if (c == 'R') cur++;
		else if (c == 'L') cur = max(0, cur - 1);
		else {
			if (s[cur] == '(') {
				seg.set(cur, 0);
				seg.set(-1, cur + 1, n);
			}
			else if (s[cur] == ')') {
				seg.set(cur, 0);
				seg.set(1, cur + 1, n);
			}
			s[cur] = c;
			if (s[cur] == '(')  {
				seg.set(cur, 1);
				seg.set(1, cur + 1, n);
			}
			else if (s[cur] == ')') {
				seg.set(cur, -1);
				seg.set(-1, cur + 1, n);
			}
		}
		auto& tp = seg.val[0];
		if (tp[0] or tp[5] < 0) printf("-1 ");
		else printf("%d ", tp[1]);
	}
}

int main()
{
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
