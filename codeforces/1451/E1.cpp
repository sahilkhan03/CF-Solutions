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
	ll n; cin >> n;
	ll xr12, xr23, a12, a23, a13;
	cout << "XOR 1 2" << endl << flush;
	cin >> xr12;
	cout << "XOR 2 3" << endl << flush;
	cin >> xr23;
	cout << "AND 1 2" << endl << flush;
	cin >> a12;
	cout << "AND 2 3" << endl << flush;
	cin >> a23;
	cout << "AND 1 3" << endl << flush;
	cin >> a13;
	ll x = xr12 + 2 * a12, y = xr23 + 2 * a23, z = (xr12 ^ xr23) + 2 * a13;
	vl ans(n);
	ans[0] = (x - y + z) / 2, ans[1] = ans[0] ^ xr12, ans[2] = ans[1] ^ xr23;
	for (int i = 3; i < n; i++) {
		cout << "XOR 1 " << i + 1 << endl << flush;
		cin >> x;
		ans[i] = ans[0] ^ x;
	}
	cout << "! " << ans << endl << flush;
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
