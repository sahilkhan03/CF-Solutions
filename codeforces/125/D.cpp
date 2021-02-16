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

bool check(vl &v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] != v[1] - v[0]) return 0;
	}
	return 1;
}

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	if (n == 2) {
		cout << v[0] << endl;
		cout << v[1] << endl;
		return;
	}
	vector<vl> pos = {{0, 1}, {1, 2}, {0, 2}};
	for (auto& x : pos) {
		vl a, b;
		for (int i = 0; i < n; i++) {
			debug(i, a, b);
			if (i <= x[1]) {
				if (find(all(x), i) == x.end()) b.pb(v[i]);
				else a.pb(v[i]);
				continue;
			}
			bool f1 = (v[i] - a.back() == a[1] - a[0]);
			bool f2 = (b.empty() or b.size() < 2 or v[i] - b.back() == b[1] - b[0]);
			if (f1 and f2) {
				if (i == n - 1) b.pb(v[i]);
				else {
					if (!b.empty() and v[i + 1] - v[i] == v[i] - b.back())
						b.pb(v[i]);
					else a.pb(v[i]);
				}
			}
			else if (f1) a.pb(v[i]);
			else b.pb(v[i]);
		}
		if (check(b)) {
			cout << a << endl;
			cout << b << endl;
			return;
		}
	}
	cout << "No solution" << endl;
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