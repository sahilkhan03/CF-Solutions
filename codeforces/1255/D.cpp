#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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

vector<char> ch;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int c = 0;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) c += (s[i][j] == 'R');
	}
	int mn = c / k, mx = mn + 1, cmx = c % k, cmn = k - cmx;
	vector<vector<char>> ans(n, vector<char>(m));
	int cur = 0, use = 0, i = 0, j = 0, dir = 0;
	while (i < n) {
		if (s[i][j] == 'R') {
			if (cur == mn) {
				if (cmn <= 1) break;
				cmn--, cur = 0, use++;
			}
			cur++;
		}
		ans[i][j] = ch[use];
		if (!dir) j++; else j--;
		if (j >= m) j = m - 1, dir ^= 1, i++;
		if (j < 0) j = 0, dir ^= 1, i++;
	}
	debug(i, j, use);
	cur = 0, use++;
	while (i < n) {
		if (s[i][j] == 'R') {
			if (cur == mx)
				cmn--, cur = 1, use++;
			else cur++;
		}
		ans[i][j] = ch[use];
		if (!dir) j++; else j--;
		if (j >= m) j = m - 1, dir ^= 1, i++;
		if (j < 0) j = 0, dir ^= 1, i++;
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
	cin >> T;
	for (char i = '0'; i <= '9'; i++) ch.pb(i);
	for (char i = 'a'; i <= 'z'; i++) ch.pb(i);
	for (char i = 'A'; i <= 'Z'; i++) ch.pb(i);
	while (T--) {
		solve();
	}
	return 0;
}
