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
	string s, t;
	cin >> s >> t;
	ll ca = 0, cb = 0;
	vl ab, ba;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == 'a') ab.pb(i);
			else ba.pb(i);
		}
		ca += (s[i] == 'a') + (t[i] == 'a');
		cb += (s[i] == 'b') + (t[i] == 'b');
	}
	if (ca % 2 or cb % 2) {
		cout << -1 << endl;
		return;
	}
	vector<pl> ans;
	while (ab.size() > 1) {
		int i1 = ab.back();
		ab.pop_back();
		int i2 = ab.back();
		ab.pop_back();
		ans.pb({i1 + 1, i2 + 1});
	}
	while (ba.size() > 1) {
		int i1 = ba.back();
		ba.pop_back();
		int i2 = ba.back();
		ba.pop_back();
		ans.pb({i1 + 1, i2 + 1});
	}
	if (!ab.empty()) {
		ans.pb({ab.back() + 1, ab.back() + 1});
		ans.pb({ab.back() + 1, ba.back() + 1});
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << endl;
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
