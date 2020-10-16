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

template<typename T> struct RMQ {
	vector<T> v; int n;
	static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) {
		return v[x] < v[y] ? x : y;
	}

	int lsb(int x) {
		return x & -x;
	}

	int msb_index(int x) {
		return __builtin_clz(1) - __builtin_clz(x);
	}

	int small(int r, int size = b) {
		int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));
		return r - dist_from_r;
	}

	RMQ(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {
			curr_mask = (curr_mask << 1) & ((1 << b) - 1);
			while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i) {
				curr_mask ^= lsb(curr_mask);
			}
			curr_mask |= 1;

			mask[i] = curr_mask;
		}

		for (int i = 0; i < n / b; i++) t[i] = small(b * i + b - 1);
		for (int j = 1; (1 << j) <= n / b; j++) for (int i = 0; i + (1 << j) <= n / b; i++)
				t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
	}
	T query(int l, int r) {
		if (r - l + 1 <= b) return v[small(r, r - l + 1)];
		int ans = op(small(l + b - 1), small(r));
		int x = l / b + 1, y = r / b - 1;
		if (x <= y) {
			int j = msb_index(y - x + 1);
			ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
		}
		return v[ans];
	}
};


template<typename T> struct RMxQ {
	vector<T> v; int n;
	static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) {
		return v[x] > v[y] ? x : y;
	}

	int lsb(int x) {
		return x & -x;
	}

	int msb_index(int x) {
		return __builtin_clz(1) - __builtin_clz(x);
	}

	int small(int r, int size = b) {
		int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));
		return r - dist_from_r;
	}

	RMxQ(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {
			curr_mask = (curr_mask << 1) & ((1 << b) - 1);
			while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i) {
				curr_mask ^= lsb(curr_mask);
			}
			curr_mask |= 1;

			mask[i] = curr_mask;
		}

		for (int i = 0; i < n / b; i++) t[i] = small(b * i + b - 1);
		for (int j = 1; (1 << j) <= n / b; j++) for (int i = 0; i + (1 << j) <= n / b; i++)
				t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
	}
	T query(int l, int r) {
		if (r - l + 1 <= b) return v[small(r, r - l + 1)];
		int ans = op(small(l + b - 1), small(r));
		int x = l / b + 1, y = r / b - 1;
		if (x <= y) {
			int j = msb_index(y - x + 1);
			ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
		}
		return v[ans];
	}
};

void solve() {
	ll n; cin >> n;
	vl v(3 * n), ans(3 * n + 2, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i + n] = v[i + 2 * n] = v[i];
	}
	RMQ<ll> rmq(v);
	RMxQ<ll> rmx(v);
	ans[3 * n - 1] = 1;
	for (int i = 3 * n - 2; i >= 0; i--) {
		ll lo = i, hi = 3 * n - 1, mid, idx = 3 * n - 1;
		while (lo <= hi) {
			mid = lo  + (hi - lo ) / 2;
			if (rmx.query(i, mid) == v[i]) idx = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		lo = i, hi = idx;
		ll cr = -1;
		while (lo <= hi) {
			mid = lo  + (hi - lo ) / 2;
			if (rmq.query(i, mid) * 2 < v[i]) cr = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		debug(i, idx, cr, ans[i]);
		if (cr == -1) ans[i] = ans[idx + 1] + idx - i + 1;
		else ans[i] = cr - i;
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] >= 2 * n) cout << -1 << " ";
		else cout << ans[i] << " ";
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
