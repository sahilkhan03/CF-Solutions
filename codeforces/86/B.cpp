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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j  + 1 < m; j++) {
			if (s[i][j] == '.' and s[i][j + 1] == '.')
				s[i][j] = s[i][j + 1] = char('0' + 3 * (i % 3) + ((j + (i + j) % 2) % 3));
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i + 1 < n; i++) {
			if (s[i][j] == '.' and s[i + 1][j] == '.')
				s[i][j] = s[i + 1][j] = char('0' + 3 * (i % 3) + ((j + (i + j) % 2) % 3));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '.') continue;
			if (j > 0 and s[i][j - 1] != '#') s[i][j] = s[i][j - 1];
			else if (j + 1 < m and s[i][j + 1] != '#') s[i][j] = s[i][j + 1];
			else if (i > 0 and s[i - 1][j] != '#') s[i][j] = s[i - 1][j];
			else if (i + 1 < n and s[i + 1][j] != '#') s[i][j] = s[i + 1][j];
			else  {
				cout << -1 << endl;;
				return;
			}
		}
	}
	for (auto &x : s) cout << x << endl;
	return;
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