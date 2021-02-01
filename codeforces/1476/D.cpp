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
	int n; cin >> n;
	string s; cin >> s;
	vi pre(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'R') continue;
		pre[i] = 1;
		if (i >= 2 and s[i - 2] == 'R') pre[i]++;
		else continue;
		if (i >= 3 and s[i - 3] == 'L') pre[i] += pre[i - 2];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'L') continue;
		suf[i] = 1;
		if (i + 1 < n and s[i + 1] == 'L') suf[i]++;
		else continue;
		if (i + 2 < n and s[i + 2] == 'R') suf[i] += suf[i + 2];
	}
	debug(pre, suf);
	for (int i = 0; i <= n; i++) cout << pre[i] + suf[i] + 1 << " ";
	cout << endl;
}

int main()
{
	fast;
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
