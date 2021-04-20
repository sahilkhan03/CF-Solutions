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
	string ss; cin >> ss;
	set<int> s[2];
	vector<vi> ans;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] == '0') s[0].insert(i);
		else s[1].insert(i);
	}
	while (!s[0].empty()) {
		int i = 1;
		vi cur = {*s[0].begin()};
		s[0].erase(s[0].begin());
		while (true) {
			auto it = s[i].upper_bound(cur.back());
			if (it == s[i].end()) break;
			cur.pb(*it);
			s[i].erase(it);
			i ^= 1;
		}
		if (i % 2 == 0) {
			s[1].insert(cur.back());
			cur.pop_back();
		}
		ans.pb(cur);
	}
	if (!s[1].empty()) {
		cout << -1 << endl;
		return;
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x.size() << " " ;
		for (auto y : x) cout << y + 1 << " ";
		cout << endl;
	}
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
