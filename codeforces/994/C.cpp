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
	vector<pl> s1(4), s2(4);
	cin >> s1 >> s2;
	vl x, y, pos1, pos2;
	for (int i = 0; i < 4; i++) {
		pl cur = s1[i], nxt = s1[(i + 1) % 4];
		if (cur.F == nxt.F) x.pb(cur.F);
		else y.pb(cur.S);
	}
	sort(all(x)), sort(all(y));
	for (int i = 0; i < 4; i++) {
		pl cur = s2[i], nxt = s2[(i + 1) % 4];
		if ((cur.S - nxt.S) / (cur.F - nxt.F) == 1) pos1.pb(cur.S - cur.F);
		else pos2.pb(cur.S + cur.F);
	}
	auto check1 = [&](ll a, ll b) {
		return (a >= x[0] and a <= x[1] and b >= y[0] and b <= y[1]);
	};
	sort(all(pos1)), sort(all(pos2));
	auto check2 = [&](ll a, ll b) {
		return (a + b - pos2[0] >= 0 and  a + b - pos2[1] <= 0
		        and a - b + pos1[1] >= 0 and a - b + pos1[0] <= 0);
	};
	for (int i = -101; i < 101; i++) {
		for (int j = -101; j < 101; j++) {
			if (check1(i, j) and check2(i, j)) {
				cout << "YES" << endl;
				return;
			}
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
