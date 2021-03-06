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
	ll a, b, k;
	cin >> a >> b >> k;
	if (!k) {
		cout << "Yes" << endl;
		string s, t;
		while (b--) s += '1', t += '1';
		while (a--) s += '0', t += '0';
		cout << s << endl << t << endl;
		return;
	}
	if (k > a + b - 2 or b < 2 or !a) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	string  s = "11", t = "10";
	b -= 2; a--; k--;
	while (k--) {
		if (a) s += '0', t += '0', a--;
		else s += '1', t += '1', b--;
	}
	s += '0', t += '1';
	while (a--) s += '0', t += '0';
	while (b--) s += '1', t += '1';
	cout << s << endl << t << endl;

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
