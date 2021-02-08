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

bool query(int r, int c) {
	cout << "? 1 " << c << " " << r << " " << c << endl << flush;
	int x; cin >> x;
	return (x & 1);
}

bool query1(int r, int c) {
	cout << "? " << r << " 1 " << r << " " << c << endl << flush;
	int x; cin >> x;
	return (x & 1);
}

void solve() {
	int n; cin >> n;
	vi o;
	for (int i = 1; i <= n; i++) {
		cout << "? 1 " << i << " " << n << " " << i << endl << flush;
		int x; cin >> x;
		if (x & 1) o.pb(i);
	}
	if (!o.empty()) {
		int ans1 = n, ans2 = n;
		for (int a = n; a; a /= 2) {
			while (ans1 - a > 0 and query(ans1 - a, o[0])) ans1 -= a;
			while (ans2 - a > 0 and query(ans2 - a, o[1])) ans2 -= a;
		}
		cout << "! " << ans1 << " " << o[0] << " " << ans2 << " " << o[1] << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << " 1 " << i << " " << n << endl << flush;
		int x; cin >> x;
		if (x & 1) o.pb(i);
	}
	int ans = n;
	for (int a = n; a; a /= 2) {
		while (ans - a > 0 and query1(o[0], ans - a)) ans -= a;
	}
	cout << "! " << o[0] << " " << ans << " " << o[1] << " " << ans << endl;
	return;
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
