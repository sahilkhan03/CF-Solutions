#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
	ll n; cin >> n;
	vl a(n), b(n);
	cin >> a >> b;
	vector<pl> v(n);
	for (int i = 0; i < n; i++) v[i] = {a[i], b[i]};
	sort(all(v), [](pl & a, pl & b) -> bool {
		return a.S < b.S;
	});
	ll ans = 0;
	multiset<pl> s;
	for (int i = n - 1; i >= 0; i--) {
		if (s.empty()) {
			s.insert({v[i].F, v[i].F});
			continue;
		}
		auto it = s.lower_bound({v[i].F, -1});
		int l = v[i].F, r = v[i].F;
		if (it != s.begin() and prev(it)->S == v[i].F - 1)
			l = prev(it)->F, s.erase(prev(it));
		else if (it != s.begin() and prev(it)->S >= v[i].F) {
			ans += (prev(it)->S + 1 - v[i].F) * v[i].S;
			l = prev(it)->F;
			r = prev(it)->S + 1;
			bool f = 0;
			if (it->F == r + 1) r = it->S, f = 1;
			s.erase(prev(it));
			if (f) s.erase(it);
			s.insert({l, r});
			continue;
		}
		if (it != s.end() and it->F == v[i].F + 1)
			r = it->S, s.erase(it);
		else if (it != s.end() and it->F == v[i].F) {
			ans += (it->S + 1 - v[i].F) * v[i].S;
			r = it->S + 1;
			if (next(it) != s.end() and r == next(it)->F - 1) r = next(it)->S, s.erase(next(it));
			s.erase(it);
		}
		s.insert({l, r});
	}
	cout << ans << endl;
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
