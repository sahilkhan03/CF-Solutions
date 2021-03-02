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
	ll n, k;
	cin >> n >> k;
	if (n < 30 and k > ((1ll << (2 * n)) - 1) / 3) {
		cout << "NO" << endl;
		return;
	}
	for (ll st = 1, c = 1, lvl = n - 1; lvl >= 0 and k >= st; st += (1ll << (c++)), lvl--) {
		k -= st;
		if (!k) {
			cout << "YES " << lvl << endl;
			return;
		}
		debug(k, st);
		for (ll tk = k, lv = n - 1, cnt = 1, cc = 2; lv >= lvl; lv--, cnt += (1ll << (cc++))) {
			debug('-', tk, cnt, cnt * ((1ll << (2 * lv)) - 1) / 3);
			if (lv > 30 or tk <= cnt * ((1ll << (2 * lv)) - 1) / 3) {
				cout << "YES " << lvl << endl;
				return;
			}
			tk -= cnt * ((1ll << (2 * lv)) - 1) / 3;
		}
	}
	cout << "NO" << endl;
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
