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
	ll c = 0;
	for (auto& x : s) c += count(all(x), '*');
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (s[i][j] == '*' and s[i + 1][j] == '*' and s[i - 1][j] == '*' and s[i][j + 1] == '*'  and s[i][j - 1] == '*') {
				ll x = 1;
				for (int k = j + 1; k < m and s[i][k] == '*'; k++, x++);
				for (int k = j - 1; k >= 0 and s[i][k] == '*'; k--, x++);
				for (int k = i + 1; k < n and s[k][j] == '*'; k++, x++);
				for (int k = i - 1; k >= 0 and s[k][j] == '*'; k--, x++);
				if (x == c) {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
	return;
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
