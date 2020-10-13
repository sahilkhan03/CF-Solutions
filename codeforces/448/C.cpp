/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
const ll mod = 1e9 + 7;
ll n;
vl v;
RMQ<ll> rm(vl({1}));
ll calc(ll l, ll r, ll h) {
	if (l > r) return 0;
	ll mn = rm.query(l, r);
	ll ls = l, ans = mn - h;
	for (int i = l; i <= r; i++) {
		if (v[i] == mn) {
			ans += calc(ls, i - 1, mn);
			ls = i + 1;
		}
		if (i == r and v[i] != mn) ans += calc(ls, i, mn);
	}
	return min(ans, r - l + 1);
}

void solve() {
	cin >> n;
	v = vl(n); cin >> v;
	rm = RMQ(v);
	cout << calc(0, n - 1, 0) << endl;
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
