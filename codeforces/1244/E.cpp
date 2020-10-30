#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	ll n, k;
	cin >> n >> k;
	set<pl> s;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		auto it = s.lower_bound({x, -1});
		if (it == s.end() or it->F != x) s.insert({x, 1});
		else {
			s.insert({x, it->S + 1});
			s.erase(it);
		}
	}
	while (s.size() > 1) {
		ll cost = min(s.begin()->S, s.rbegin()->S);
		if (cost > k) break;
		if (s.begin()->S < s.rbegin()->S) {
			ll up = min(k / s.begin()->S, next(s.begin())->F - s.begin()->F);
			k -= up * s.begin()->S;
			ll x = s.begin()->F;
			auto it = next(s.begin());
			if (it->F != x + up) s.insert({x + up, s.begin()->S});
			else {
				s.insert({x + up, s.begin()->S + it->S});
				s.erase(it);
			}
			s.erase(s.begin());
		}
		else {
			ll x = s.rbegin()->F;
			ll dn = min(k / s.rbegin()->S, s.rbegin()->F - prev(s.end(), 2)->F);
			k -= dn * s.rbegin()->S;
			auto it = prev(s.end(), 2);
			if (it ->F != x - dn) s.insert({x - dn, s.rbegin()->S});
			else {
				s.insert({x - dn, s.rbegin()->S + it->S});
				s.erase(it);
			}
			s.erase(prev(s.end()));
		}
	}
	cout << s.rbegin()->F - s.begin()->F << endl;
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
