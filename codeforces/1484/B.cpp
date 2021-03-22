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
	vl v(n); cin >> v;
	bool inc = 0, dec = 0;
	ll c = -1, m = -1;
	for (int i = 1; i < n; i++) {
		if (v[i] >= v[i - 1]) {
			inc = 1;
			if (c == -1) c = v[i] - v[i - 1];
			else if (v[i] - v[i - 1] != c) {
				cout << -1 << endl;
				return;
			}
		}
		else {
			dec = 1;
			if (m == -1) m = v[i - 1] - v[i];
			else if (v[i - 1] - v[i] != m) {
				cout << -1 << endl;
				return;
			}
		}
	}
	if (!inc or !dec) {
		cout << 0 << endl;
		return;
	}
	m += c;
	for (int i = 0, cur = v[0]; i < n; i++) {
		if (cur % m != v[i]) {
			cout << -1 << endl;
			return;
		}
		(cur += c) %= m;
	}
	cout << m << " " << c << endl;
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
