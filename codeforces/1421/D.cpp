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
	ll x, y;
	cin >> x >> y;
	vl c(6); cin >> c;
	ll ans = 1e18;
	c[0] = min(c[0], c[1] + c[5]);
	c[1] = min(c[1], c[0] + c[2]);
	c[2] = min(c[2], c[3] + c[1]);
	c[3] = min(c[3], c[2] + c[4]);
	c[4] = min(c[4], c[3] + c[5]);
	c[5] = min(c[5], c[0] + c[4]);
	if (x >= 0) {
		if (y >= 0) {
			ans = c[5] * x + c[1] * y;
			ans = min(ans, min(x, y) * c[0] + (x - min(x, y)) * c[5] + (y - min(x, y)) * c[1]);
		}
		else {
			y = -y;
			ans = c[5] * x + c[4] * abs(y);
			ans = min(ans, x * c[0] + (x + y) * c[4]);
			ans = min(ans, y * c[3] + (x + y) * c[5]);
		}
	}
	else {
		x = -x;
		if (y >= 0) {
			ans = c[2] * x + c[1] * y;
			ans = min(ans, c[0] * y + (x + y) * c[2]);
			ans = min(ans, c[3] * x + (x + y) * c[1]);
		}
		else {
			y = -y;
			ans = c[2] * x + y * c[4];
			ans = min(ans, c[3] * min(x, y) + (x - min(x, y)) * c[2] + (y - min(x, y)) * c[4]);
		}
	}
	cout << ans << endl;
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
