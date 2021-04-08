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
	set<ll> s = { -1, n};
	multiset<ll> len = {n};
	vl v(n);
	map<ll, vl> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]].pb(i);
	}
	pl ans = {1, -m.rbegin()->F - 1};
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		auto& cur = it->S;
		for (auto x : cur) {
			auto id = s.lower_bound(x);
			len.erase(len.find(*id - *prev(id) - 1));
			if (*id - x - 1) len.insert(*id - x - 1);
			if (x - *prev(id) - 1) len.insert(x - *prev(id) - 1);
			s.insert(x);
		}
		debug(it->F);
		debug(vl(all(s)));
		debug(vl(all(len)));
		if (!len.empty() and * len.begin() == *len.rbegin()) {
			ans = max(ans, pl({len.size(), -it->F}));
		}
	}
	auto it = prev(m.lower_bound(-ans.S));
	cout << it->F + 1 << endl;
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
