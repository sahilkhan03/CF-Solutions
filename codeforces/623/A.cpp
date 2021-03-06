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
	ll n, m;
	cin >> n >> m;
	vector<vl> v(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		v[a - 1].pb(b - 1);
		v[b - 1].pb(a - 1);
	}
	vector<char> ans(n, 'c');
	vl c(3, 0);
	c[2] = n;
	ll ls = -1;
	for (int i = 0; i < n; i++) {
		if (v[i].size() == n - 1) ans[i] = 'b', c[1]++, c[2]--;
		else ls = i;
	}
	if (ls != -1) {
		ans[ls] = 'a', c[0]++, c[2]--;
		for (auto x : v[ls]) {
			if (ans[x] != 'b') ans[x] = 'a', c[0]++, c[2]--;
		}
	}
	for (int i = 0; i < n; i++) {
		if ((ans[i] == 'a' and v[i].size() != c[1] + c[0] - 1) or (ans[i] == 'b' and v[i].size() != n - 1) or (ans[i] == 'c' and v[i].size() != c[1] + c[2] - 1)) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	for (char xc : ans) cout << xc;
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
