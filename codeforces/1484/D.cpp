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
	vl ans;
	set<ll> s;
	set<pl> bad;
	for (int i = 0; i < n; i++) {
		s.insert(i);
		if (__gcd(v[i], v[(i + 1) % n]) == 1)
			bad.insert({i, (i + 1) % n});
	}
	int a = 0, b = 0, c = 0;
	while (!bad.empty()) {
		auto it = bad.lower_bound({c, -1});
		if (it == bad.end()) it = bad.begin();
		auto it1 = next(s.find(it->S));
		if (it1 == s.end()) it1 = s.begin();
		a = it->F, b = it->S, c = *it1;
		if (__gcd(v[a], v[c]) == 1)
			bad.insert({a, c});
		if (__gcd(v[b], v[c]) == 1)
			bad.erase({b, c});
		ans.pb(b + 1);
		s.erase(b);
		bad.erase({a, b});
	}
	cout << ans.size() << " " << ans << endl;
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
