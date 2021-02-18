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
	ll n; cin >> n;
	ll lo = 1, hi = n;
	while (lo != hi) {
		cout << "? " << lo << " " << hi << endl << flush;
		ll x; cin >> x;
		if (hi - lo == 1) {
			if (x == lo) cout << "! " << hi << endl;
			else cout << "! " << lo << endl;
			return;
		}
		ll mid = (lo + hi) / 2, a;
		if (x >= lo and x <= mid) {
			cout << "? " << lo << " " << mid << endl << flush;
			cin >> a;
			if (a == x) hi = mid;
			else lo = mid + 1;
		}
		else {
			if (mid + 1 == hi) {
				hi = mid;
				continue;
			}
			cout << "? " << mid + 1 << " " << hi << endl << flush;
			cin >> a;
			if (a == x) lo = mid + 1;
			else hi = mid;
		}
	}
	cout << "! " << lo << endl;
}

int main()
{
	// fast;
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
