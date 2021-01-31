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

bool check(vi &a, vi &b, vi &c, vi &d) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] >= c[i] or b[i] >= d[i]) goto skip;
	}
	return 1;
skip:;
	for (int i = 0; i < n; i++) {
		if (a[i] >= d[i] or b[i] >= c[i]) return 0;
	}
	return 1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m)), b(n, vi(m));
	cin >> a >> b;
	vi pref, pres;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
			if ((i > 0 and a[i][j] <= a[i - 1][j]) or (j > 0 and a[i][j] <= a[i][j - 1]) or (i > 0 and b[i][j] <= b[i - 1][j]) or (j  > 0 and b[i][j] <= b[i][j - 1])) swap(a[i][j], b[i][j]);
			if ((i > 0 and a[i][j] <= a[i - 1][j]) or (j > 0 and a[i][j] <= a[i][j - 1]) or (i > 0 and b[i][j] <= b[i - 1][j]) or (j  > 0 and b[i][j] <= b[i][j - 1])) {
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	cout << "Possible" << endl;
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