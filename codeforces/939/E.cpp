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

void solve() {
	int q; cin >> q;
	vl pre = {0};
	ld mx = 0;
	auto calc = [&](ll x) {
		return mx - (mx + pre[x]) / (x + 1);
	};
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			cin >> mx;
			pre.pb(pre.back() + mx);
		}
		else {
			ll lo = 0, hi = pre.size() - 1;
			while (lo <= hi) {
				ll mid = lo + (hi - lo) / 2;
				ld f1 = calc(max(lo, mid - 1)), f2 = calc(mid), f3 = calc(min(hi, mid + 1));
				if (f2 >= f1 and f2 >= f3) {
					printf("%.10Lf\n", f2);
					break;
				}
				if (f1 > f2) hi = mid - 1;
				else lo = mid + 1;
			}
		}
		debug(pre);
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
