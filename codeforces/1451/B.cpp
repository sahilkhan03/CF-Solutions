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
	ll n, q;
	cin >> n >> q;
	string s; cin >> s;
	vl pre(n + 1), suf(n + 2);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + (s[i] == '1');
	}
	for (int i = n - 1; i >= 0; i--) {
		suf[i + 1] = suf[i + 2] + (s[i] == '1');
	}
	debug(pre, suf);
	while (q--) {
		ll l, r;
		cin >> l >> r;
		int c = s[l - 1] - '0';
		if ((pre[l - 1] and c == 1) or ((l - 1 - pre[l - 1]) and c == 0)) {
			cout << "YES" << endl;
			continue;
		}
		c = s[r - 1] - '0';
		debug(c);
		if ((pre[n] - pre[r] and c == 1) or ((n - r - pre[n] + pre[r]) and c == 0)) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}

int main()
{
	fast;
	ll T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
