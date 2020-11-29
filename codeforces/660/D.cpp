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

pl calc(pl a, pl b) {
	ll num = b.S - a.S, den = b.F - a.F;
	if (!num) return {0, 1};
	if (!den) return {1, 0};
	if (den < 0) den = -den, num = -num;
	ll g = __gcd(abs(num), abs(den));
	return {num / g, den / g};
}

ll cdis(pl a, pl b) {
	return (a.F - b.F) * (a.F - b.F)  + (a.S - b.S) * (a.S - b.S);
}

void solve() {
	ll n, ans = 0;
	cin >> n;
	vector<pl> v(n);
	cin >> v;
	map<pl, map<ll, ll>> m;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pl slp = calc(v[i], v[j]);
			ll len = cdis(v[i], v[j]);
			ans += m[slp][len];
			m[slp][len]++;
			debug(i, j, slp, len);
		}
	}
	cout << ans / 2 << endl;
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
