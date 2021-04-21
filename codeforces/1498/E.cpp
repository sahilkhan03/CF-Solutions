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
	int n; cin >> n;
	vi v(n); cin >> v;
	vector<pl> pr;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pr.pb({i, j});
		}
	}
	sort(all(pr), [&](const pl & a, const pl & b) -> bool {
		return abs(v[a.F] - v[a.S]) > abs(v[b.F] - v[b.S]);
	});
	for (auto x : pr) {
		if (v[x.F] > v[x.S]) swap(x.F, x.S);
		cout << "? " << x.S + 1 << " " << x.F + 1 << endl << flush;
		string s; cin >> s;
		if (s == "Yes") {
			cout << "! " << x.F + 1 << " " << x.S + 1 << endl;
			return;
		}
	}
	cout << "! 0 0" << endl;
}

int main()
{
	// fast;
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
