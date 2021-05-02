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
	vi v(24);
	cin >> v;
	vl same;
	auto calc = [&](int a, int b, int c, int d) {
		return (v[a] == v[b] and v[b] == v[c] and v[c] == v[d]);
	};
	for (int i = 0; i < 24; i += 4) {
		if (calc(i, i + 1, i + 2, i + 3)) {
			same.pb((i + 4) / 4);
		}
	}
	if (same.empty()) {
		cout << "NO" << endl;
		return;
	}
	debug(same);
	if (same[0] == 1 and same[1] == 3) {
		if ((calc(12, 13, 6, 7) and calc(4, 5, 18, 19) and calc(16, 17, 22, 23)
		        and calc(20, 21, 14, 15)) or
		        calc(12, 13, 22, 23) and calc(4, 5, 14, 15) and calc(16, 17, 6, 7)
		        and calc(20, 21, 18, 19)) {
			cout << "YES" << endl;
			return;
		}
	}
	else if (same[0] == 2 and same[1] == 6) {
		if ((calc(0, 1, 16, 18) and calc(17, 19, 8, 9) and calc(10, 11, 13, 15)
		        and calc(12, 14, 2, 3)) or
		        calc(0, 1, 13, 15) and calc(12, 14, 8, 9) and calc(10, 11, 16, 18)
		        and calc(17, 19, 2, 3)) {
			cout << "YES" << endl;
			return;
		}
	}
	else if (same[0] == 4 and same[1] == 5) {
		debug('h', calc(0, 1, 5, 7) , calc(4, 6, 11, 9) , calc(8, 10, 20, 22)
		      , calc(1, 3, 21, 23));
		if ((calc(0, 2, 5, 7) and calc(4, 6, 11, 9) and calc(8, 10, 20, 22)
		        and calc(1, 3, 21, 23)) or
		        calc(1, 3, 4, 6) and calc(5, 7, 8, 10) and calc(0, 2, 20, 22)
		        and calc(9, 11, 21, 23)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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
