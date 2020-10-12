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

pl check(vl &v) {
	ll n = v.size();
	for (int i = 1; i < n; i++) {
		if (v[i] == n) continue;
		auto it = find(all(v), v[i] + 1) - v.begin();
		if (it < i) return {it, i};
	}
	return { -1, -1};
}

void solve() {
	ll n, i, j, k; cin >> n;
	vl v(n); cin >> v;
	vector<vl> ans;
	// ll g = 5;
	while (true) {
		tie(i, j) = check(v);
		if (i == -1) break;
		vl d1, tmp, d2 = {v[i]}, d3, d4, cur;
		for (k = 0; k < i; k++) d1.pb(v[k]);
		for (k = j + 1; k < n; k++) d4.pb(v[k]);
		for (k = i + 1; k < j and v[k] > v[k - 1]; k++) d2.pb(v[k]);
		while (k <= j) d3.pb(v[k++]);
		tmp = {d4};
		for (auto x : d3) tmp.pb(x);
		for (auto x : d2) tmp.pb(x);
		for (auto x : d1) tmp.pb(x);
		v = tmp;
		if (!d1.empty()) cur.pb(d1.size());
		if (!d2.empty()) cur.pb(d2.size());
		if (!d3.empty()) cur.pb(d3.size());
		if (!d4.empty()) cur.pb(d4.size());
		ans.pb(cur);
		// debug(d1, d2, d3, d4);
		debug(v);
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x.size() << " " << x << endl;
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
