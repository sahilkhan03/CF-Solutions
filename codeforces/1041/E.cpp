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
	vector<pl> v(n - 1), ans;
	cin >> v;
	vl cnt(n);
	for (auto [a, b] : v) {
		if (max(a, b) != n) {
			cout << "NO" << endl;
			return;
		}
		cnt[min(a, b)]++;
	}
	vl unuse;
	for (int i = 1; i < n; i++) {
		if (!cnt[i]) {
			unuse.pb(i);
			continue;
		}
		if (cnt[i] > i or unuse.size() + 1 < cnt[i]) {
			cout << "NO" << endl;
			return;
		}
		ll p = n;
		while (cnt[i] > 1) {
			ans.pb({unuse.back(), p});
			p = unuse.back();
			unuse.pop_back();
			cnt[i]--;
		}
		ans.pb({i, p});
	}
	cout << "YES" << endl;
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
