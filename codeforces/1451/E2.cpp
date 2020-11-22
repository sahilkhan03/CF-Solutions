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
inline ostream &operator<<(ostream &os, const set<T> &t) {
	for (auto i : t) os << i << " ";
	return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
	for (auto i : t) os << i.first << " : " << i.second << endl;
	return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
	for (T &t : v) is >> t;
	return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
	for (pair<T1, T2> &t : v) is >> t.first >> t.second;
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
	int n, pos = -1; cin >> n;
	vi ans(n), xr(n - 1);
	map<int, int> m;
	pl same = { -1, -1};
	for (int i = 1; i < n; i++) {
		cout << "XOR 1 " << i + 1 << endl << flush;
		cin >> xr[i - 1];
		if (m.find(xr[i - 1]) != m.end()) same = {m[xr[i - 1]] + 1, i + 1};
		m[xr[i - 1]] = i;
		if (xr[i - 1] == n - 1) pos = i;
	}
	if (same.F != -1) {
		cout << "AND " << same << endl << flush;
		int x; cin >> x;
		ans[0] = x ^ xr[same.F - 2];
	}
	else {
		int c = (pos == 1 ? 2 : 1);
		int a0c, acp;
		cout << "AND 1 " << c + 1 << endl << flush;
		cin >> a0c;
		cout << "AND " << c + 1 << " " << pos + 1 << endl << flush;
		cin >> acp;
		int x = xr[c - 1] + 2 * a0c, y = xr[pos - 1], z = (xr[c - 1] ^ xr[pos - 1]) + 2 * acp;
		ans[0] = (x + y - z) / 2;
	}
	for (int i = 1; i < n; i++) ans[i] = ans[0] ^ xr[i - 1];
	cout << "! " << ans << endl << flush;
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
