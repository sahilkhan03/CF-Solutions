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
	ll n; cin >> n;
	vector<set<ll>> v(n);
	set<ll> pos = {0};
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		pos.insert(i + 1);
		cin >> a >> b;
		v[a - 1].insert(b - 1);
		v[b - 1].insert(a - 1);
	}
	vl leaf;
	for (int q = 0; q < n / 2; q++) {
		leaf.clear();
		for (int i = 0; i < n; i++) {
			if (v[i].size() == 1) leaf.pb(i);
		}
		ll x, l1 = leaf[leaf.size() - 1], l2 = leaf[leaf.size() - 2];
		cout << "? " << l1 + 1 << " " << l2 + 1 << endl << flush;
		cin >> x;
		if (x == l1 + 1 or x == l2 + 1) {
			cout << "! " << x << endl << flush;
			return;
		}
		pos.erase(pos.find(l1));
		pos.erase(pos.find(l2));
		v[l1].clear(); v[l2].clear();
		for (int i = 0; i < n; i++) {
			if (v[i].find(l2) != v[i].end()) v[i].erase(v[i].find(l2));
			if (v[i].find(l1) != v[i].end()) v[i].erase(v[i].find(l1));
		}
	}
	cout << "! " << *pos.begin() + 1 << endl << flush;
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
