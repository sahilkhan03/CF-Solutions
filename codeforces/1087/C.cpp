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
	vector<pl> v(3);
	cin >> v;
	sort(all(v), [](pl a, pl b) ->bool{
		return a.S < b.S;
	});
	ll midy = v[1].S;
	sort(all(v));
	ll midx = v[1].F;
	set<pl> ans;
	for (int i = midy; i <= v[1].S; i++) ans.insert({midx, i});
	for (int i = midy; i >= v[1].S; i--) ans.insert({midx, i});
	pl pt = v[1];
	sort(all(v), [](pl a, pl b) ->bool{
		return a.S < b.S;
	});
	for (int i = midx; i <= v[1].F; i++) ans.insert({i, midy});
	for (int i = midx; i >= v[1].F; i--) ans.insert({i, midy});
	for (int j = 0; j < 3; j++) {
		if (j != 1 and v[j] != pt) {
			for (int i = midy; i <= v[j].S; i++) ans.insert({midx, i});
			for (int i = midy; i >= v[j].S; i--) ans.insert({midx, i});
			for (int i = midx; i <= v[j].F; i++) ans.insert({i, v[j].S});
			for (int i = midx; i >= v[j].F; i--) ans.insert({i, v[j].S});
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
