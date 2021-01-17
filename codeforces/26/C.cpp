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

int n, m, a, b, c;

vector<vector<char>> ans;

char gtc(int t, int i, int j) {
	auto& v = ans;
	for (char c = 'a'; c <= 'z'; c++) {
		if (t == 1) {
			if (i + 1 < n and (v[i + 1][j] == c or v[i + 1][j + 1] == c)) continue;
			if (j > 0 and v[i][j - 1] == c) continue;
		}
		else if (t == 2) {
			if (j > 0 and (v[i][j - 1] == c or v[i + 1][j - 1] == c)) continue;
			if (i + 2 < n and v[i + 2][j] == c) continue;
		}
		else {
			if (i + 2 < n and (v[i + 2][j] == c or v[i + 2][j + 1] == c)) continue;
			if (j > 0 and (v[i][j - 1] == c or v[i + 1][j - 1] == c)) continue;
		}
		return c;
	}
	return 'a';
}

void solve() {
	cin >> n >> m >> a >> b >> c;
	ans = vector<vector<char>>(n, vector<char>(m));
	if ((n & 1) and (m & 1)) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	if (n & 1) {
		if (a < m / 2) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		for (int i = 0; i < m; i += 2, a--) {
			ans[n - 1][i] = ans[n - 1][i + 1] = gtc(1, n - 1, i);
		}
	}
	if (m & 1) {
		if (b < n / 2) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		for (int i = n - 2; i >= 0; i -= 2, b--) {
			ans[i][0] = ans[i + 1][0] = gtc(2, i, 0);
		}
	}
	for (int i = n - 2 - (n & 1); i >= 0 ; i -= 2) {
		for (int j = (m & 1); j < m; j += 2) {
			debug(i, j, a, b, c);
			if (c) {
				c--;
				char ch = gtc(3, i, j);
				ans[i][j] = ans[i][j + 1] = ans[i + 1][j] = ans[i + 1][j + 1] = ch;
			}
			else if (a > 1) {
				a -= 2;
				ans[i + 1][j] = ans[i + 1][j + 1] = gtc(1, i + 1, j);
				ans[i][j] = ans[i][j + 1] = gtc(1, i, j);
			}
			else if (b > 1) {
				b -= 2;
				ans[i + 1][j] = ans[i][j] = gtc(2, i, j);
				ans[i + 1][j + 1] = ans[i][j + 1] = gtc(2, i, j + 1);
			}
			else {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << ans[i][j];
		cout << endl;
	}
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
