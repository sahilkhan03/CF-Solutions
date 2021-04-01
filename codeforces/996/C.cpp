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
	ll n, k;
	cin >> n >> k;
	vector<vl> ans, v(4, vl(n));
	cin >> v;
	vector<pl> dest(k + 1), cur(k + 1);
	for (int i = 0; i < n; i++) {
		if (v[0][i]) dest[v[0][i]] = {0, i};
		if (v[3][i]) dest[v[3][i]] = {3, i};
		if (v[1][i]) cur[v[1][i]] = {1, i};
		if (v[2][i]) cur[v[2][i]] = {2, i};
	}
	vector<vi> vis(4, vi(n));
	auto chng = [&](ll i, ll a, ll b) {
		ans.pb({i, a + 1, b + 1});
		v[cur[i].F][cur[i].S] = 0;
		v[a][b] = i;
		cur[i] = {a, b};
	};
	function<bool(ll, ll)> move = [&](ll a, ll b) {
		if (a > 2 or a < 1 or b >= n or b < 0 or vis[a][b])
			return 0;
		if (!v[a][b]) return 1;
		vis[a][b] = 1;
		if (a == 1 and !vis[a + 1][b] and move(a + 1, b)) {
			chng(v[a][b], a + 1, b);
			return 1;
		}
		if (a == 2 and !vis[a - 1][b] and move(a - 1, b)) {
			chng(v[a][b], a - 1, b);
			return 1;
		}
		if (b < n - 1 and !vis[a][b + 1] and move(a, b + 1)) {
			chng(v[a][b], a, b + 1);
			return 1;
		}
		if (b > 0 and !vis[a][b - 1] and move(a, b - 1)) {
			chng(v[a][b], a, b - 1);
			return 1;
		}
		return 0;
	};
	for (int i = 1; i <= k; i++) {
		if (dest[i].S == cur[i].S and abs(dest[i].F - cur[i].F) == 1) {
			chng(i, dest[i].F, dest[i].S);
		}
	}
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if (v[1][i] == 0 or v[2][i] == 0) {
			f = 1;
			break;
		}
	}
	if (!f) {
		cout << -1 << endl;
		return;
	}
	for (int i = 1; i <= k; i++) {
		if (cur[i] != dest[i]) {
			while (cur[i].S < dest[i].S) {
				vis = vector<vi>(4, vi(n));
				vis[cur[i].F][cur[i].S] = 1;
				move(cur[i].F, cur[i].S + 1);
				chng(i, cur[i].F, cur[i].S + 1);
			}
			while (cur[i].S > dest[i].S) {
				vis = vector<vi>(4, vi(n));
				vis[cur[i].F][cur[i].S] = 1;
				move(cur[i].F, cur[i].S - 1);
				chng(i, cur[i].F, cur[i].S - 1);
			}
			if (cur[i].F - dest[i].F == 2) {
				vis = vector<vi>(4, vi(n));
				vis[cur[i].F][cur[i].S] = 1;
				move(cur[i].F - 1, cur[i].S);
				chng(i, cur[i].F - 1, cur[i].S);
			}
			if (cur[i].F - dest[i].F == -2) {
				vis = vector<vi>(4, vi(n));
				vis[cur[i].F][cur[i].S] = 1;
				move(cur[i].F + 1, cur[i].S);
				chng(i, cur[i].F + 1, cur[i].S);
			}
			chng(i, dest[i].F, dest[i].S);
		}
	}
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << endl;
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
