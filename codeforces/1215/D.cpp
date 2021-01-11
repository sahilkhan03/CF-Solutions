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
	string s; cin >> s;
	ll ca = 0, cb = 0, dif = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') ca++;
		else dif -= (s[i] - '0');
	}
	for (int i = n / 2; i < n; i++) {
		if (s[i] == '?') cb++;
		else dif += (s[i] - '0');
	}
	ll mn = min(ca, cb);
	ca -= mn, cb -= mn;
	if (cb) {
		if (((cb + 1) / 2) * 9 + dif > 0 or cb * 9 / 2 + dif < 0)
			cout << "Monocarp" << endl;
		else cout << "Bicarp" << endl;
	}
	else {
		if (-((ca + 1) / 2) * 9 + dif < 0 or - ca * 9 / 2 + dif > 0)
			cout << "Monocarp" << endl;
		else cout << "Bicarp" << endl;
	}
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
