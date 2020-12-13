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

void solve() {
	ll n; cin >> n;
	vl v(n); cin >> v;
	ll md = n / 2, j = md - 1;
	while (j >= 0 and v[j] == v[md]) j--;
	vl clen;
	ll len = 0, ls = -1;
	for (int i = 0; i <= j; i++) {
		if (v[i] == ls) len++;
		else {
			if (len) clen.pb(len);
			ls = v[i], len = 1;
		}
	}
	if (len) clen.pb(len);
	if (clen.size() < 3) {
		cout << "0 0 0" << endl;
		return;
	}
	vl pre(clen.size() + 1);
	for (int i = 0; i < clen.size(); i++) {
		pre[i + 1] = pre[i] + clen[i];
	}
	for (int i = 1; i < pre.size(); i++) {
		auto it = upper_bound(pre.begin() + i + 1, pre.end(), 2 * pre[i]) - pre.begin();
		if (it >= pre.size() or pre.back() - pre[it] <= pre[i]) continue;
		cout << pre[i] << " " << pre[it] - pre[i] << " " << pre.back() - pre[it] << endl;
		return;
	}
	cout << "0 0 0" << endl;
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
