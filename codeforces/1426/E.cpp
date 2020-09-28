/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
ll n;

ll cmax(vl a, vl b) {
	ll ans = 0;
	ll x = min(a[0], b[2]);
	ans += x; a[0] -= x, b[2] -= x;
	x = min(a[1], b[0]);
	ans += x, a[1] -= x, b[0] -= x;
	x = min(a[2], b[1]);
	ans += x, a[2] -= x, b[1] -= x;
	return ans;
}

ll cmin(vl a, vl b) {
	ll ans = 0;
	a[0] -= min(a[0], b[0] + b[1]);
	a[1] -= min(a[1], b[1] + b[2]);
	a[2] -= min(a[2], b[2] + b[0]);
	return a[0] + a[1] + a[2];
}

void solve() {
	cin >> n;
	vl a(3), b(3);
	cin >> a >> b;
	swap(a[1], a[2]), swap(b[1], b[2]);
	cout << cmin(a, b) << " " << cmax(a, b) << endl;
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
