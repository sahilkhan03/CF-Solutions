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
	ll n, l, r, s;
	cin >> n >> l >> r >> s;
	ll len = r - l + 1;
	if (s < len * (len + 1) / 2 or s > len * (2 * n + 1 - len) / 2) {
		cout << -1 << endl;
		return;
	}
	vl v(len);
	ll sum = len * (len + 1) / 2;
	for (int i = 0; i < len; i++) {
		while (sum + len - i <= s) v[i]++, sum += len - i;
	}
	ll pre = 0;
	vl use(n + 1);
	for (int i = 1; i <= len; i++) {
		pre += v[i - 1];
		v[i - 1] = i + pre;
		use[v[i - 1]] = 1;
	}
	ll j = 1;
	for (int i = 1; i < l; i++) {
		while (use[j]) j++;
		cout << j << " ";
		use[j] = 1;
	}
	cout << v;
	for (int i = r + 1; i <= n; i++) {
		while (use[j]) j++;
		cout << j << " ";
		use[j] = 1;
	}
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
