/*
	"Work until your Idols become your Rivals"
*/

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	ll n, ans = 0, ls = 0, idx = 0; cin >> n;
	vi v(n); cin >> v;
	vector<vector<vi>> grp(2, vector<vi>());
	grp[0].pb(v);
	for (int i = 30; i >= 0; i--) {
		ll in0 = 0, in1 = 0, pw = (1ll << i);
		debug(i, idx, ans, grp[idx].size(), grp[idx]);
		for (auto& g : grp[idx]) {
			ll c0 = 0, c1 = 0;
			vi a, b;
			for (int j = 0; j < g.size(); j++) {
				if (g[j] & pw) {
					c1++;
					in1 += c0;
					a.pb(g[j]);
				}
				else {
					c0++;
					in0 += c1;
					b.pb(g[j]);
				}
			}
			if (!a.empty()) grp[!idx].pb(a);
			if (!b.empty()) grp[!idx].pb(b);
		}
		grp[idx].clear();
		debug('-', in0, in1);
		ls += in0;
		if (in0 > in1) ans += pw, ls += in1 - in0;
		idx = !idx;
	}
	cout << ls << " " << ans << endl;
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
