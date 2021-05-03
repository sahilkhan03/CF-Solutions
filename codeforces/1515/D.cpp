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
	int n, l, r;
	cin >> n >> l >> r;
	vl lf(n + 1), rg(n + 1);
	for (int i = 0; i < l;  i++) {
		int x; cin >> x;
		lf[x]++;
	}
	for (int i = l; i < n; i++) {
		int x; cin >> x;
		rg[x]++;
	}
	vl lfo, rgo;
	ll ans = 0, le = 0, re = 0;
	for (int i = 1; i <= n; i++) {
		while (lf[i] and rg[i]) lf[i]--, rg[i]--;
		le += lf[i], re += rg[i];
		if (lf[i] & 1) lfo.pb(i), le--;
		if (rg[i] & 1) rgo.pb(i), re--;
	}
	debug(le, re);
	while (lfo.size() > rgo.size() and re) {
		lfo.pop_back();
		lfo.pop_back();
		re -= 2;
		ans += 2;
	}
	while (rgo.size() > lfo.size() and le) {
		rgo.pop_back();
		rgo.pop_back();
		le -= 2;
		ans += 2;
	}
	ans += (le + re) / 2;
	int s1 = lfo.size(), s2 = rgo.size();
	int x = min(s1, s2);
	ans += x;
	s1 -= x, s2 -= x;
	ans += max(s1, s2);
	cout << ans << endl;
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
