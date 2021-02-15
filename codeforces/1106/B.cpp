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
	vl a(n), c(n);
	cin >> a >> c;
	set<pl> dish;
	for (int i = 0; i < n; i++) dish.insert({c[i], i});
	while (m--) {
		ll i, d, cost = 0;
		cin >> i >> d;
		i--;
		ll x = min(a[i], d);
		if (x) {
			d -= x; cost += x * c[i];
			a[i] -= x;
			if (!a[i]) dish.erase(dish.find({c[i], i}));
		}
		while (d > 0) {
			if (dish.empty()) {
				cost = 0;
				break;
			}
			i = dish.begin()->S;
			x = min(a[i], d);
			d -= x; cost += x * c[i];
			a[i] -= x;
			if (!a[i]) dish.erase(dish.find({c[i], i}));
		}
		cout << cost << endl;
	}
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
