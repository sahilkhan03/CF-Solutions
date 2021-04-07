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
	vl mn(n), mx(n);
	ll j = 1;
	set<ll> s1, s2;
	mn[0] = mx[0] = v[0];
	ll ls = v[0];
	for (int i = 1; i < v[0]; i++) s1.insert(i), s2.insert(i);
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) {
			mn[i] = *s1.begin();
			s1.erase(s1.begin());
			mx[i] = *s2.rbegin();
			s2.erase(prev(s2.end()));
		} else {
			mn[i] = mx[i] = v[i];
			for (int j = ls + 1; j < v[i]; j++)
				s1.insert(j), s2.insert(j);
			ls = v[i];
		}
	}
	cout << mn << endl;
	cout << mx << endl;
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