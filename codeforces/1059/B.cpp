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
	vector<string> s(n);
	cin >> s;
	vector<vi> vis(n, vi(m));
	auto check = [&](int i, int j) {
		for (int l = i - 1; l <= i + 1; l++) {
			for (int r = j - 1; r <= j + 1; r++) {
				if (l == i and r == j) continue;
				if (l < 0 or l >= n or r < 0 or r >= m) return 0;
				if (s[l][r] == '.') return 0;
			}
		}
		return 1;
	};
	auto fil = [&](int i, int j) {
		for (int l = i - 1; l <= i + 1; l++) {
			for (int r = j - 1; r <= j + 1; r++) {
				if (l == i and r == j) continue;
				vis[l][r] = 1;
			}
		}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check(i, j)) fil(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#' and !vis[i][j]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
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
