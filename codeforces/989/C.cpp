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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<string> s(50, string(50, 'D'));
	for (int i = 0; i < 36; i++) {
		for (int j = 0; j < 50; j++) {
			s[i][j] = char('A' + (i / 12));
		}
	}
	a--, b--, c--, d--;
	for (int i = 1; i < 11; i += 2) {
		for (int j = 0; j < 50 and b; j += 2, b--) s[i][j] = 'B';
	}
	for (int i = 13; i < 23; i += 2) {
		for (int j = 0; j < 50 and c; j += 2, c--) s[i][j] = 'C';
	}
	for (int i = 25; i < 35; i += 2) {
		for (int j = 0; j < 50 and d; j += 2, d--) s[i][j] = 'D';
	}
	for (int i = 37; i < 50; i += 2) {
		for (int j = 0; j < 50 and a; j += 2, a--) s[i][j] = 'A';
	}
	cout << 50 << " " << 50 << endl;
	for (auto x : s) cout << x << endl;
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
