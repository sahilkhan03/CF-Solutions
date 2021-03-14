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
	ll n, m;
	cin >> n >> m;
	ll r, c;
	cin >> r >> c;
	r--, c--;
	ll x, y;
	cin >> x >> y;
	vector<string> s(n);
	cin >> s;
	queue<array<ll, 4>> q;
	q.push({r, c, 0, 0});
	ll ans = 0;
	vector<vi> vis(n, vi(m)), use(n, vi(m, mod));
	while (!q.empty()) {
		auto [i, j, lf, rg] = q.front();
		q.pop();
		vis[i][j] = 1;
		debug(i, j, lf, rg);
		if (i + 1 < n and s[i + 1][j] != '*' and use[i + 1][j] > lf) {
			use[i + 1][j] = lf;
			q.push({i + 1, j, lf, rg});
		}
		if (i > 0 and s[i - 1][j] != '*' and use[i - 1][j] > lf) {
			use[i - 1][j] = lf;
			q.push({i - 1, j, lf, rg});
		}
		if (j + 1 < m and s[i][j + 1] != '*' and rg < y and use[i][j + 1] > lf) {
			use[i][j + 1] = lf;
			q.push({i, j + 1, lf, rg + 1});
		}
		if (j > 0 and s[i][j - 1] != '*' and lf < x and use[i][j - 1] > lf + 1) {
			use[i][j - 1] = lf + 1;
			q.push({i, j - 1, lf + 1, rg});
		}
	}
	q = queue<array<ll, 4>>();
	q.push({r, c, 0, 0});
	use = vector<vi> (n, vi(m, mod));
	while (!q.empty()) {
		auto [i, j, lf, rg] = q.front();
		q.pop();
		vis[i][j] = 1;
		debug(i, j, lf, rg);
		if (i + 1 < n and s[i + 1][j] != '*' and use[i + 1][j] > rg) {
			use[i + 1][j] = rg;
			q.push({i + 1, j, lf, rg});
		}
		if (i > 0 and s[i - 1][j] != '*' and use[i - 1][j] > rg) {
			use[i - 1][j] = rg;
			q.push({i - 1, j, lf, rg});
		}
		if (j + 1 < m and s[i][j + 1] != '*' and rg < y and use[i][j + 1] > rg + 1) {
			use[i][j + 1] = rg + 1;
			q.push({i, j + 1, lf, rg + 1});
		}
		if (j > 0 and s[i][j - 1] != '*' and lf < x and use[i][j - 1] > rg) {
			use[i][j - 1] = rg;
			q.push({i, j - 1, lf + 1, rg});
		}
	}
	for (auto& x : vis) ans += accumulate(all(x), 0);
	cout << ans << endl;
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
