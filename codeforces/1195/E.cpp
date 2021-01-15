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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	ll g, x, y, z;
	cin >> g >> x >> y >> z;
	vector<deque<pair<int, int>>> col(m);
	deque<pair<int, int>> cur;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cur.clear();
		for (int j = 0; j < m; j++) {
			if (i >= a and !col[j].empty() and col[j].front().S == i - a)
				col[j].pop_front();
			while (!col[j].empty() and col[j].back().F >= g) col[j].pop_back();
			col[j].push_back({g, i});
			if (j >= b and !cur.empty() and cur.front().S == j - b)
				cur.pop_front();
			while (!cur.empty() and cur.back().F >= col[j].front().F)
				cur.pop_back();
			cur.push_back({col[j].front().F, j});
			if (i >= a - 1 and j >= b - 1) ans += cur.front().F;
			(g = g * x + y) %= z;
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
