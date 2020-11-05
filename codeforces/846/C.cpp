#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	ll n; cin >> n;
	vl v(n); cin >> v;
	vl pre(n + 1);
	vector<pl> suf(n + 2);
	suf[n + 1] = {0, n + 1};
	ll ss = 0;
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + v[i];
		ss += v[n - i - 1];
		if (ss < suf[n - i + 1].F)
			suf[n - i] = {ss, n - i};
		else
			suf[n - i] = suf[n - i + 1];
	}
	ll res = -1e18;
	vl ans = {0, 0, 0};
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ll cur = 2 * pre[i] - pre[j] - suf[j + 1].F;
			if (res < cur + pre[n] - pre[j] - suf[j + 1].F) {
				res = cur + pre[n] - pre[j] - suf[j + 1].F;
				ans = {i, j, suf[j + 1].S - 1};
			}
		}
	}
	cout << ans << endl;
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
