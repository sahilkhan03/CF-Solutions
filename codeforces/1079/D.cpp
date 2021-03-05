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

ld calc(ld a, ld b, ld c, ld d) {
	return sqrtl((a - c) * (a - c) + (b - d) * (b - d));
}

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	pair<ld, ld> st, ed;
	cin >> st >> ed;
	ld ans = abs(st.F - ed.F) + abs(st.S - ed.S);
	if (!a or !b) {
		printf("%.10Lf\n", ans);
		return;
	}
	pair<ld, ld> p1 = {st.F, (-c - a * st.F) / b},
	             p2 = {(-c - b * st.S) / a, st.S},
	             p3 = {ed.F, (-c - a * ed.F) / b},
	             p4 = {(-c - b * ed.S) / a, ed.S};
	debug(p1);
	debug(p2);
	debug(p3);
	debug(p4);
	ans = min(ans, abs(st.S - p1.S) + abs(ed.S - p3.S) + calc(p1.F, p1.S, p3.F, p3.S));
	ans = min(ans, abs(st.S - p1.S) + abs(ed.F - p4.F) + calc(p1.F, p1.S, p4.F, p4.S));
	ans = min(ans, abs(st.F - p2.F) + abs(ed.S - p3.S) + calc(p2.F, p2.S, p3.F, p3.S));
	ans = min(ans, abs(st.F - p2.F) + abs(ed.F - p4.F) + calc(p2.F, p2.S, p4.F, p4.S));
	printf("%.10Lf\n", ans);
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
