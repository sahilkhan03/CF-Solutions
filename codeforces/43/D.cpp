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
	int n, m, f = 0;
	cin >> n >> m;
	if (n == 1) {
		if (m == 2) {
			cout << 0 << endl;
			cout << "1 1\n1 2\n1 1" << endl;
			return;
		}
		cout << 1 << endl;
		cout << "1 " << m << " 1 1" << endl;
		for (int i = 1; i <= m; i++) cout << 1 << " " << i << endl;
		cout << "1 1" << endl;
		return;
	}
	if (m == 1) {
		if (n == 2) {
			cout << 0 << endl;
			cout << "1 1\n2 1\n1 1" << endl;
			return;
		}
		cout << 1 << endl;
		cout << n << " 1 1 1" << endl;
		for (int i = 1; i <= n; i++) cout << i << " " << 1 << endl;
		cout << "1 1" << endl;
		return;
	}
	if (m % 2 == 0) {
		cout << 0 << endl;
		cout << "1 1" << endl;
		for (int j = 1; j <= m; j++, f ^= 1) {
			if (!f) for (int i = 2; i <= n; i++) cout << i << " " << j << endl;
			else for (int i = n; i >= 2; i--) cout << i << " " << j << endl;
		}
		for (int i = m; i > 0; i--) cout << 1 << " " << i << endl;
		return;
	}
	if (n & 1) cout << 1 << endl << n << " " << m << " " << n << " " << 1 << endl;
	else cout << 0 << endl;
	cout << "1 1" << endl;
	for (int i = 1; i <= n; i++, f ^= 1) {
		if (!f) for (int j = 2; j <= m; j++) cout << i << " " << j << endl;
		else for (int j = m; j > 1; j--) cout << i << " " << j << endl;
	}
	for (int i = n; i > 0; i--) cout << i << " " << 1 << endl;
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
